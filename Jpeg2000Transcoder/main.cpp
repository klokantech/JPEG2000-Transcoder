#include "jpeg2000transcoder.h"
#include <QtGui/QApplication>

/**
 * Main function, just starts app and shows gui
 * note: this program is not crossplatform, it is 
 *       intended for Windows OS version 2000 or higher,
 *		 because of .ini parsing, resolving application directory
 *		 and executing external applications, more info in workerThread.h
 *		 and jpeg2000transcoder.h
 */
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Jpeg2000Transcoder w;
	w.show();
	return a.exec();
}
