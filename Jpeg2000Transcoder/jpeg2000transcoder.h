#ifndef JPEG2000TRANSCODER_H
#define JPEG2000TRANSCODER_H

#include "QtGui/QMainWindow"
#include "qdesktopwidget.h"
#include "qtgui/qfiledialog.h"
#include "ui_jpeg2000transcoder.h"
#include "workerThread.h"
#include "QtGui/qmessagebox.h"
#include "profile.h"
#include <fstream>
#include <ShellAPI.h>
/**
 * GUI thread of application
 * This class is not crossplatform! For crossplatform solution change
 * ShellExecute call in enableButtons(), GetModuleFileName call in getExeDir(),
 * parsing of ini file in parseIniFile() and related variables. Also add posix
 * folder separators / everywhere, where is \\ used.
 */
class Jpeg2000Transcoder : public QMainWindow
{
	Q_OBJECT

public:
	/**
	 * Constructor, sets GUI, checks dependencies, parses ini file, creates WorkerThread
	 */
	Jpeg2000Transcoder(QWidget *parent = 0, Qt::WFlags flags = 0);
	/**
	 * Destructor, deletes WorkerThread and profilesArray
	 */
	~Jpeg2000Transcoder();

private slots:
	/**
	 * Chooses existing files via standard dialog window and sets it to inputFileLineEdit,
	 * action triggered by Choose button of input file
	 */
    void setOpenFileName();
	/**
	 * Chooses existing folder via standard dialog window and sets it to outputFolderLineEdit,
	 * action triggered by Choose button of output folder
	 */
	void setExistingOutputDirectory();
	/**
	 * Sets attributes for WorkerThread with values chosen by user 
	 * and starts it, so it will transform chosen file/files into jpeg2000,
	 * action triggered by Transcode button
	 */
	void transcode();
	/**
	 * Sends signal to WorkerThread that user want to stop after this file, 
	 * sets WorkerThread::isCancelled attribute to True,
	 * action triggered by Cancel button
	 */
	void cancelTranscoding();
	/**
	 * Enables transcode button, disables cancel button, opens last processed
	 * image in browser if output folder is IIPImage Images folder at least 1 
	 * file was successfully processed,
	 * action triggered recieving finished signal from WorkerThread
	 * @param folder output folder of converted files
	 */
	void enableButtons(QString folder);
	/**
	 * Display progress information, writes if file was processed successfully + percentage,
	 * action triggered by WorkerThread's progressChanged signal
	 * @param fileName name of file that was processed
	 * @param result tells whether processing of this file failed or succeeded,
	 * 0 means success, -1 means problem with djpeg transformation, -2 problem with 
	 * kdu_compress transformation
	 * @param chunk number of processed files to show progress percentage
	 */
	void displayProgress(QString fileName, int result, int chunk);
	/**
	 * Displays basic information about program in new messageBox,
	 * action triggered by Help->About JPEG2000 Transcoder
	 */
	void displayAbout();
	/**
	 * Displays manual to program in new messageBox,
	 * action triggered by Help->How to use transcoder
	 */
	void displayHelp();
	/**
	 * Displays dialog asking if user want to overwrite file with the fileName and sets 
	 * overwriteFile and overwriteFileWasSet flags in WorkerThread,
	 * action triggered by overwriteFileSignal of WorkerThread
	 * @param fileName name of file, that could be overwritten
	 */
	void overwriteFileDialog(QString fileName);
	/**
	 * Updates profile message box with information about currently selected profile
	 * @param index index of selected profile
	 */
	void updateProfileDisplay(int index);


private:
	Ui::Jpeg2000TranscoderClass ui;	/**< interface class automatically generated from .ui file created in Qt*/
	WorkerThread * thread;			/**< WorkerThread for resolving operations out of GUI thread */
	QStringList inputFiles;			/**< List of files, that was chosen by user for transcoding */
	QString outputDir;				/**< default output directory, always points to directory in .ini file */
	Profile * profilesArray;		/**< array containing profiles loaded from .ini file */
	int profilesArraySize;			/**< number of profiles in the profilesArray, not real size of array */
	QString iipImageURL;			/**< url to iipimage viewer from .ini file*/
	/**
	 * Disables transcode button, enables cancel button, used while starting WorkerThread
	 */
	void disableButtons();
	/**
	 * Converts QStringList to QString putting space and "" between filenames,
	 * used for showing chosen files in inputFileLineEdit
	 */
	QString filesToQString(QStringList files);
	/**
	 * Returns directory of this application
	 * @return application directory
	 */
	QString getExeDir();
	/**
	 * Parses ini file and gets configuration from it
	 * @param iniFile absolute path to ini file
	 */
	void parseIniFile(QString fileName);
	/**
	 * Checks presence of dependencies (djpeg, kdu_compress and configuration.ini),
	 * writes error and exits if some dependency is missing
	 */
	void checkDependencies();
	/**
	 * Encodes string with percent-encoding (url encoding),
	 * encoded is every non alphanumerical character except of : . ? / and null character
	 * because these characters are part of url address and can't be in fileName
	 * NOTE: other characters eg. = are also encoded (because they can be in fileName) 
	 * @param stringToEncode string that will be encoded
	 * @return QString with percent-encoded input string
	 */
	QString encodeUrl(QString stringToEncode);
};

#endif // JPEG2000TRANSCODER_H
