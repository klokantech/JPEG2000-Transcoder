#include "workerThread.h"

void WorkerThread::run()
 {
	 isCancelled = false;
	 lastProcessedFile = "";//set last processed file to empty string - no file was processed yet
	 for (int i = 0; i < source.count(); i++)
	 {
		 if (isCancelled)//if signal for stopping was send
		 {
			break;
		 }
		 QString fileName = source.at(i);
		 int result = transcodeFile(fileName, destination, parameters);
		 emit progressChanged(fileName,result,i+1);//inform about progress change
	 }
	 emit finished(destination);
}

void WorkerThread::setAttributes(QStringList source, QString destination, QString parameters, QString exeDir)
{
	this->source = source;
	this->destination = destination;
	this->parameters = parameters;
	this->exeDir = exeDir;
}

int WorkerThread::transcodeFile(QString source, QString destination, QString parameters)
{
	bool result;//result of ShellExecuteEx
	DWORD returnCode = 0;//return of this function
	QString name = createName(destination + source.mid(source.lastIndexOf("\\")));
	bool deleteSource = false;	//used for intermediate file in jpeg->jpeg2000 conversion
	if(isJpeg(source))
	{
		QString tempPPM = source + ".PPM";
		tempPPM = tempPPM.remove(0,tempPPM.lastIndexOf("\\"));
		tempPPM.prepend(destination);
		wchar_t bufferExePath[MAX_PATH+1] = L"";
		("\""+exeDir+"bins\\djpeg.exe\"").toWCharArray(bufferExePath);//put app path + name to bufferExePath 
		wchar_t bufferParams[1000] = L"";
		("-pnm \""+source+"\" \""+tempPPM+"\"").toWCharArray(bufferParams); // put params for transcoding to bufferParams
		//set everything important for executing djpeg.exe through ShellExecuteEx(ShellExecuteInfo)
		SHELLEXECUTEINFO ShExecInfo = {0};
		ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
		ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
		ShExecInfo.hwnd = NULL;
		ShExecInfo.lpVerb = NULL;
		ShExecInfo.lpFile = bufferExePath;//set app name	
		ShExecInfo.lpParameters = bufferParams;//set params
		ShExecInfo.lpDirectory = NULL;
		ShExecInfo.nShow = SW_HIDE;//hide console
		ShExecInfo.hInstApp = NULL;	
		result = ShellExecuteEx(&ShExecInfo);//execute command
		WaitForSingleObject(ShExecInfo.hProcess,INFINITE);//wait for completion
		GetExitCodeProcess(ShExecInfo.hProcess, &returnCode);
		source = tempPPM;
		if (!result || returnCode != 0)
		{
			remove(source.toLocal8Bit().constData());//try to remove evidence of intermediate file if any
			return -1;//negative 1 means transformation to interm. file failed, we don't care where exactly was the problem
		}
		deleteSource = true;
	}
	//transcode to jpeg2000
	wchar_t bufferExePath[MAX_PATH+1] = L"";
	("\""+exeDir+"bins\\kdu_compress.exe\"").toWCharArray(bufferExePath);//put app path + name to bufferExePath
	wchar_t bufferParams[10000] = L"";
	("-i \""+source+"\" -o \""+name+"\" "+parameters).toWCharArray(bufferParams);//put params for transcoding to bufferParams
	//set everything important for executing external app
	SHELLEXECUTEINFO ShExecInfo = {0};
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = bufferExePath;//external app path	
	ShExecInfo.lpParameters = bufferParams;//parameters for transcoding
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_HIDE;//hide console window
	ShExecInfo.hInstApp = NULL;	
	result = ShellExecuteEx(&ShExecInfo);//execute command
	WaitForSingleObject(ShExecInfo.hProcess,INFINITE);//wait for completion
	GetExitCodeProcess(ShExecInfo.hProcess, &returnCode);
	if (!result || returnCode != 0)
	{
		remove (name.toLocal8Bit().constData());
		returnCode = -2;//transformation to jpeg2000 failed, we don't look for exact problem
	}
	if(deleteSource)
		remove(source.toLocal8Bit().constData());
	if (returnCode == 0)
		lastProcessedFile = name.mid(name.lastIndexOf("\\")+1);
	return returnCode;
}

bool WorkerThread::isJpeg(QString fileName)
{
	QString extension = fileName.mid(fileName.lastIndexOf(".")+1);//get everything behind last dot
	return extension.compare("jpg",Qt::CaseInsensitive)==0 ||
		   extension.compare("jpeg",Qt::CaseInsensitive)==0;
}

QString WorkerThread::createName(QString fileName)
{
	int lastDotPosition = fileName.lastIndexOf(".");//find extension
	fileName.truncate(lastDotPosition);//cut extension
	fileName = fileName + ".jp2";//add .jp2 extension
	std::ifstream name(fileName.toLocal8Bit().constData());
	if(name)
	{//file with this name exist
		overwriteFileWasSet = false;
		emit overwriteFileSignal(fileName);//ask user what to do
		while (!overwriteFileWasSet)
		{//wait until user selects action
			this->msleep(1);//give some time to set flag, without this cycle would be infinite
		}
		if( !overwriteFile )
		{//we don't want overwrite this file
			fileName.chop(4);//cut off .jp2
			int possibleSplit = fileName.lastIndexOf("_");//find last underscore
			QString partBehindUnderscore = fileName.mid(possibleSplit+1);//take everything behind that underscore
			bool ok;
			int num = partBehindUnderscore.toInt(&ok, 10);//try to parse it to integer
			if (!ok)//if not integer behind underscore, add new underscore to the end, num will be 0 by default
			{
				fileName = fileName + "_";
				possibleSplit = fileName.length()-1;//we will be adding number behind whole fileName with new underscore
			}
			bool existingName = true;
			while (existingName)//increase number until such file doesn't exist
			{
				num++;//increase number
				fileName = fileName.left(possibleSplit+1) + QString::number(num) + ".jp2";//build fileName
				std::ifstream newName(fileName.toLocal8Bit().constData());//try new fileName
				existingName = newName;
			}
		}
	}
	return fileName;
}

QString WorkerThread::getLastProcessedFile()
{
	return lastProcessedFile;
}