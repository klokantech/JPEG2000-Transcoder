#ifndef WORKER_THREAD_H
#define WORKER_THREAD_H
#include "qthread.h"
#include "qstringlist.h"
#include <Windows.h>
#include <ShellAPI.h>
#include <stdio.h>
#include <fstream>

/**
 * This is WorkerThread of application, it does hard work in different thread as gui runs in
 * This class is not crossplatform! For crossplatform solution replace ShellExecuteEx
 * and WaitForSingleObject calls in transcodeFile() and related variables. Also add 
 * folder separators / everywhere where is \\ used.
 */
class WorkerThread : public QThread
{
Q_OBJECT
 private:
	 QStringList source;			/**< list of files that will be processed */
	 QString destination;			/**< name of folder where will go output files */
	 QString parameters;			/**< parameters of format chosen by user */
	 QString exeDir;				/**< folder where is application stored */
	 QString lastProcessedFile;		/**< name of last processed .jp2 file without folder part */

	 /**
	  * Executes thread, takes parameters from class attributes,
	  * it means, that setAttributes must be used always before starting thread
	  */
     void run();
	 /**
	  * transcodes single file from any format to jpeg 2000 by given format parameters and saves it to destination folder
	  * @param source absolute path to source file
	  * @param destination absolute path to folder where will be saved processed files
	  * @param parameters parameters of format chosen for transcoding
	  * @return  0 if everything successful,
	  *			-1 if couldn't transform to intermediate PPM (only for JPEG),
	  *			-2 if couldn't transform to jp2,
	  */
	 int transcodeFile(QString source, QString destination, QString parameters);
	 /**
	  * Tells whether file is jpeg (.jpg or .jpeg extension, case insensitive) 
	  * @param fileName absolute path to file
	  * @return true if file is jpeg, false otherwise
	  */
	 bool isJpeg(QString fileName);

	 /**
	  * Finds if file with output name already exists and aks user whether overwrite it
	  * Creates new name adding number behind filename if file already exists and user
	  * doesn't want to overwrite it
	  * @param fileName absolute path to file
	  * @return new free filename
	  */
	 QString createName(QString fileName);

 public:
	 bool isCancelled;			/**< Flag that informs about cancellation by user */
	 bool overwriteFile;		/**< Flag that informs about user choice of overwriting file */
	 bool overwriteFileWasSet;	/**< Flag that informs that user has chosen action about overwriting file */
	 
	 /**
	  * Sets all needed attributes of thread
	  * @param source list of filenames that should be processed
	  * @param destination folder where will be output saved
	  * @param parameters parameters of profile chosen by user
	  * @param exeDir directory of the application
	  */
	 void setAttributes(QStringList source, QString destination, QString parameters, QString exeDir);
	 /**
	  * Returns last successful processed file from source list (only fileName without folder part with .jp extension)
	  * @return last successfully processed .jp2 file
	  */
	 QString getLastProcessedFile();

signals:
	 /**
	  * Sends signal, that progress was changed (file was processed)
	  * @param fileName name of file that was processed
	  * @param result tells whether processing of this file failed or succeeded
	  * @param chunk number of processed files
	  */
	 void progressChanged(QString fileName, int result, int chunk);
	 /**
	  * Sends signal, that file with given name exists, and user should be asked for action
	  * @param fileName file name that already exists
	  */
	 void overwriteFileSignal(QString fileName);
	 /**
	  * Sends signal, that thread has finished and saved everything to this folder
	  * @param folder output folder
	  */
	 void finished(QString folder);
 };
#endif