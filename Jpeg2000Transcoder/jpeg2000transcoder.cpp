#include "jpeg2000transcoder.h"
#define CONFIGURATION "configuration.ini"


Jpeg2000Transcoder::Jpeg2000Transcoder(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	//setMaximumWidth to desktop width, so it won't resize out of screen
	ui.centralWidget->setMaximumWidth(QApplication::desktop()->width());
	thread = new WorkerThread();

	connect(ui.chooseInputFileButton, SIGNAL(clicked()),
            this, SLOT(setOpenFileName()));
	connect(ui.chooseOutputFolderButton, SIGNAL(clicked()),
            this, SLOT(setExistingOutputDirectory()));
	connect(ui.transcodeButton, SIGNAL(clicked()),
            this, SLOT(transcode()));
	connect(ui.cancelButton, SIGNAL(clicked()),
		this, SLOT(cancelTranscoding()));
	connect(ui.actionAbout_Jpeg2000Transcoder, SIGNAL(triggered()),
		this, SLOT(displayAbout()));
	connect(ui.actionHow_to_use_transcoder, SIGNAL(triggered()),
		this, SLOT(displayHelp()));
	connect(thread,SIGNAL(finished(QString)),
		this, SLOT(enableButtons(QString)));
	connect(thread,SIGNAL(progressChanged(QString, int, int)),
		this, SLOT(displayProgress(QString, int, int)));
	connect(thread, SIGNAL(overwriteFileSignal(QString)),
		this, SLOT(overwriteFileDialog(QString)));
	connect(ui.formatComboBox, SIGNAL(currentIndexChanged(int)),
		this, SLOT(updateProfileDisplay(int)));

	checkDependencies();
	parseIniFile(getExeDir()+CONFIGURATION);
}

Jpeg2000Transcoder::~Jpeg2000Transcoder()
{
	if(profilesArray)
		delete [] profilesArray;
	if(thread)
		delete thread;
}

void Jpeg2000Transcoder::setOpenFileName()
{
	//calls standard OS dialog for choosing files
	inputFiles = QFileDialog::getOpenFileNames(this,"Choose File", QDir::rootPath(),
		"Image Files(*.bmp;*.tif;*.tiff;*.pbm;*.pgm;*ppm;*raw;*rawl;*jpeg;*jpg)");
	if (!inputFiles.isEmpty())
		ui.inputFileLineEdit->setText(filesToQString(inputFiles));
}

void Jpeg2000Transcoder::setExistingOutputDirectory()
{
	//call standard OS dialog for choosing directories
    QFileDialog::Options options = QFileDialog::DontResolveSymlinks | QFileDialog::ShowDirsOnly;
    QString directory = QFileDialog::getExistingDirectory(this, "Choose folder", 
		outputDir, options);//dialog will always start in folder set in ini file for easier finding
    if (!directory.isEmpty())
	{
		ui.outputFolderLineEdit->setText(directory);
	}
}

void Jpeg2000Transcoder::transcode()
{
	if(ui.inputFileLineEdit->text().isEmpty())
	{//no file was chosen to transcode
		QMessageBox::StandardButton reply;
		reply = QMessageBox::information(this, "No source entered", "You must choose one or more files that will be processed.");
		return;
	}
	disableButtons();
	ui.progressBar->setValue(0);
	ui.progressBar->setRange(0, inputFiles.count());
	int index = ui.formatComboBox->currentIndex();//get index from comboBox so we can send right parameters for encoding
	thread->setAttributes(inputFiles, ui.outputFolderLineEdit->text(), profilesArray[index].parameters, getExeDir());
	thread->start();
}

void Jpeg2000Transcoder::cancelTranscoding()
{
	ui.messageBoxTextEdit->append("Canceling");
	thread->isCancelled = true;
}

void Jpeg2000Transcoder::disableButtons()
{
	ui.cancelButton->setEnabled(true);
	ui.transcodeButton->setEnabled(false);
}

void Jpeg2000Transcoder::enableButtons(QString folder)
{
	ui.messageBoxTextEdit->append("Finished");
	ui.cancelButton->setEnabled(false);
	ui.transcodeButton->setEnabled(true);
	//open last successfully processed file in browser
	if (thread->getLastProcessedFile() == "")
	{//at this point we have nothing to show, just write error and end
		QMessageBox::information(this, "No successfuly processed files:", "All processed files failed.");
		return;
	}
	QString urlBuilder = "\"" + encodeUrl(iipImageURL) +"?image=" + encodeUrl(thread->getLastProcessedFile()) + "\"";
	if (folder == outputDir)
	{
		wchar_t tmpUrl[2048] = L"";
		urlBuilder.toWCharArray(tmpUrl);
		int result = (int) ShellExecute(NULL, L"open", tmpUrl, NULL, NULL, SW_SHOWNORMAL);
		if (result <= 32)//if error during opening browser occured 
		{
			QMessageBox::information(this, "Can't open browser:", "URL to last processed file is " + urlBuilder);
		}
	}
	else
	{
		QMessageBox::information(this, "Files not in iipimage directory:", "Output directory is not the same as IIPImage directory \
set in configuration.ini. Move files to " +outputDir + " directory and use this hyperlink to access images in iipimage: "
+ urlBuilder);
	}
}

QString Jpeg2000Transcoder::filesToQString(QStringList files)
{
	QString qstring = "";
	for (int i = 0; i < files.count(); i++)
	{
		qstring = qstring + "\""+files.at(i) + "\" ";
	}
	return qstring;
}

QString Jpeg2000Transcoder::getExeDir()
{
	wchar_t bufferExePath[MAX_PATH+1] = L"";
	GetModuleFileName(NULL, bufferExePath, MAX_PATH);
	QString returnString = QString::fromUtf16(bufferExePath);
	int endOfFolderPart = returnString.lastIndexOf("\\");
	returnString.chop(returnString.length() - endOfFolderPart - 1);
    return returnString;
}

void Jpeg2000Transcoder::parseIniFile(QString iniFile)
{
	//path to .ini file
	wchar_t iniFileWChar[MAX_PATH+1] = L"";
	iniFile.toWCharArray(iniFileWChar);
	//output folder
	wchar_t tmpOutputFolder[MAX_PATH+1] = L"";
	wchar_t tmpDefaultFolder[MAX_PATH+1] = L""; 
	//we will set default folder to something existing, in case it is not present in .ini file
	QDir::homePath().toWCharArray(tmpDefaultFolder);
	GetPrivateProfileString(L"OutputFolder", L"name", tmpDefaultFolder,
		tmpOutputFolder,MAX_PATH,iniFileWChar);
	outputDir = QString::fromUtf16(tmpOutputFolder);
	//directory must not end with backslash, it will be added in rest of program
	if (outputDir.lastIndexOf("\\") == outputDir.length()-1)
	{
		outputDir.chop(1);
	}
	ui.outputFolderLineEdit->setText(outputDir);
	//iipImage URL
	wchar_t tmpIIPImageURL[2049] = L"";
	GetPrivateProfileString(L"IIPImageURL", L"url", L"",
		tmpIIPImageURL,2048,iniFileWChar);
	iipImageURL = QString::fromUtf16(tmpIIPImageURL);
	//profiles
	int count = GetPrivateProfileIntW(L"Profiles", L"count", 0, iniFileWChar);
	profilesArray = new Profile[count];
	wchar_t tmpReturnedValue[10000] = L"";
	wchar_t tmpRequest[100] = L"";
	//strings for creating requests in cycle
	QString requestConstant;
	QString request;
	int result;
	profilesArraySize = 0;
	for (int i = 1; i <= count; i++)
	{
		Profile profile = Profile();
		requestConstant = "profile" + QString::number(i);
		//name
		request = requestConstant + ".name";
		request.toWCharArray(tmpRequest);
		result = GetPrivateProfileString(L"Profiles", tmpRequest, L"", tmpReturnedValue, 9999, iniFileWChar);
		if (result > 0)
		{
			profile.name = QString::fromUtf16(tmpReturnedValue);

		}
		memset(tmpRequest,'\0',200);//always reset wchar so it doesn't make problems reusing it 
		memset(tmpReturnedValue,'\0',10000);
		//institution
		request = requestConstant + ".institution";
		request.toWCharArray(tmpRequest);
		result = GetPrivateProfileString(L"Profiles", tmpRequest, L"", tmpReturnedValue, 9999, iniFileWChar);
		if (result > 0)
			profile.institution = QString::fromUtf16(tmpReturnedValue);
		memset(tmpRequest,'\0',200);
		memset(tmpReturnedValue,'\0',10000);
		//definition
		request = requestConstant + ".definition";
		request.toWCharArray(tmpRequest);
		result = GetPrivateProfileString(L"Profiles", tmpRequest, L"", tmpReturnedValue, 9999, iniFileWChar);
		if (result > 0)
			profile.definition = QString::fromUtf16(tmpReturnedValue);
		memset(tmpRequest,'\0',200);
		memset(tmpReturnedValue,'\0',10000);
		//parameters
		request = requestConstant + ".parameters";
		request.toWCharArray(tmpRequest);
		result = GetPrivateProfileString(L"Profiles", tmpRequest, L"", tmpReturnedValue, 9999, iniFileWChar);
		if (result > 0)
			profile.parameters = QString::fromUtf16(tmpReturnedValue);
		memset(tmpRequest,'\0',200);
		memset(tmpReturnedValue,'\0',10000);
		//compression
		request = requestConstant + ".compression";
		request.toWCharArray(tmpRequest);
		result = GetPrivateProfileString(L"Profiles", tmpRequest, L"",tmpReturnedValue,9999,iniFileWChar);
		if (result > 0)
			profile.compression = QString::fromUtf16(tmpReturnedValue);
		memset(tmpRequest,'\0',200);
		memset(tmpReturnedValue,'\0',10000);
		//quality loss
		request = requestConstant + ".quality";
		request.toWCharArray(tmpRequest);
		result = GetPrivateProfileString(L"Profiles", tmpRequest, L"",tmpReturnedValue,9999,iniFileWChar);
		if (result > 0)
			profile.quality = QString::fromUtf16(tmpReturnedValue);
		memset(tmpRequest,'\0',200);
		memset(tmpReturnedValue,'\0',10000);

		if (!profile.parameters.isEmpty())
		{
			profilesArray[i-1] = profile; //array is indexed from zero,  profiles in ini file from 1
			ui.formatComboBox->insertItem(i-1,profile.name);
			profilesArraySize++;
		}
	}
	if (profilesArraySize == 0)
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::information(this, "Profiles not found",
			"In configuration.ini file weren't found any profiles with parameters set.");
		exit(42);
	}
}

void Jpeg2000Transcoder::checkDependencies()
{
	QString errorString = "The following files are missing: ";
	std::ifstream kakaduFile((getExeDir()+"kdu_compress.exe").toLocal8Bit().constData());
	std::ifstream djpegFile((getExeDir()+"djpeg.exe").toLocal8Bit().constData());
	std::ifstream configFile((getExeDir()+CONFIGURATION).toLocal8Bit().constData());
	if (!kakaduFile)
	{
		errorString += "kdu_compress.exe ";
	}
	if (!djpegFile)
	{
		errorString += "djpeg.exe ";
	}
	if (!configFile)
	{
		errorString += CONFIGURATION;
	}
	if (! (kakaduFile && djpegFile && configFile))
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::information(this, "Missing dependency:", errorString);
		exit(404);
	}
}

void Jpeg2000Transcoder::displayProgress(QString fileName, int result, int chunk)
{
	switch(result)
	{
	case 0:
		ui.messageBoxTextEdit->append("Processing of file "+fileName+" was successful.");
		break;
	case -1:
		ui.messageBoxTextEdit->append("Processing of file "+fileName+" failed. Couldn't make intermediate .PPM file. (djpeg.exe)");
		break;
	case -2:
		ui.messageBoxTextEdit->append("Processing of file "+fileName+" failed. Couldn't make jpeg2000 transformation. (kdu_compress.exe)");
		break;
	default:
		ui.messageBoxTextEdit->append("Unknown result code: "+ QString::number(result));
	}
	ui.progressBar->setValue(chunk);
}

void Jpeg2000Transcoder::overwriteFileDialog(QString fileName)
{
	if (QMessageBox::question(this,"File already exists: ","File with name "+
			fileName+" already exists, do you want to overwrite it?",QMessageBox::Yes,
			QMessageBox::No) == QMessageBox::Yes)
	{
		thread->overwriteFile = true;
	}
	else
	{
		thread->overwriteFile = false;
	}
	thread->overwriteFileWasSet = true;
}

QString Jpeg2000Transcoder::encodeUrl(QString stringToEncode)
{
	QString encodedString = "";
	//convert our Utf8 QString to Local 8 bit standard string
	std::string stdStringToEncode = stringToEncode.toLocal8Bit().constData();
	for(int i = 0; i < stringToEncode.length(); i++)
	{
		if((stringToEncode.at(i) >= '0' && stringToEncode.at(i) <= '9')
			|| (stringToEncode.at(i) >= 'A' && stringToEncode.at(i) <= 'Z')
			|| (stringToEncode.at(i) >= 'a' && stringToEncode.at(i) <= 'z') 
			|| stringToEncode.at(i) == '.' 
			|| stringToEncode.at(i) == ':' 
			|| stringToEncode.at(i) == '/' 
			|| stringToEncode.at(i) == '?' 
			|| stringToEncode.at(i) == '\0')
		{
			encodedString.append(stringToEncode.at(i));
		}
		else
		{
			//get ordinal value, convert it to string as hexadecimal and append it with % to our result string
			//we have to use standard string's [] operator here because QChar is Utf8
			encodedString.append("%" + QString::number((unsigned char)stdStringToEncode[i],16));
		}
	}
	return encodedString;
}

void Jpeg2000Transcoder::displayAbout()
{
	QMessageBox::about(this,"About Jpeg2000Transcoder", "Jpeg2000Transcoder is utility for transformation \
of image files to JPEG 2000 format. \nIt uses kdu_compress.exe created by Kakadu and therefore can be used \
only for non-commercial purpose. \nCreated in Moravian Library 2012.");
}

void Jpeg2000Transcoder::displayHelp()
{
	QMessageBox::about(this,"How to use Jpeg2000Transcoder", "To convert your image to jpeg 2000 follow these simple steps:\n\
1. Choose one or more files you wish to convert by clicking upper 'Choose' button in Input File line. For choosing multiple files \
use ctrl key and click on the files you wish to select. Currently supported formats are bmp, tiff, pbm, pgm, ppm, raw, rawl and jpeg.\n\
2. Choose directory where you want to put converted .jp2 file by clicking upper 'Choose' button in Input File line. \
In default it should be set to IIPImage Images directory.\n\
3. Choose suitable profile for transformation (lossless/lossy, bigger/smaller compression ratio etc.). You can add your personal profiles \
into application by adding them to configuration.ini file in application directory and increasing count number in this file.\n\
4. Click transcode button and wait, when all files will be processed, last successfully processed file will be open in browser in IIPImage.");
}

void Jpeg2000Transcoder::updateProfileDisplay(int index)
{
	ui.profileDisplayTextEdit->clear();
	ui.profileDisplayTextEdit->append("Name: "+profilesArray[index].name);
	ui.profileDisplayTextEdit->append("Institution: "+profilesArray[index].institution);
	ui.profileDisplayTextEdit->append("Definition: "+profilesArray[index].definition);
	ui.profileDisplayTextEdit->append("Quality: "+profilesArray[index].quality);
	ui.profileDisplayTextEdit->append("Compression: "+profilesArray[index].compression);
	ui.profileDisplayTextEdit->append("Parameters: "+profilesArray[index].parameters);
	ui.profileDisplayTextEdit->moveCursor(QTextCursor::Start);
}