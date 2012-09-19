JPEG2000-Transcoder
===================

JPEG2000-Transcoder is utility for transcoding image files to JPEG 2000 jp2 format.
It uses djpeg.exe and kdu_compress.exe for transcoding and JPEG2000Transcoder.exe is GUI wrapper, connecting functionality of these apps.
Supported are bmp, tiff, pbm, pgm, ppm, raw, rawl and jpeg images.
It also uses configuration.ini to get required initialization information, eg. default output folder, url of IIPImage Server and profiles.
This application is not crossplatform, but uses Qt libraries, so for full crossplatform solution, there is needed only change few Windows functions to also support another systems, which shouldn't be too hard. Closer info in documentation and in header files.
Transcoder was created in Moravian Library as part of the IIPImage JPEG2000 windows installer.

If you have questions write mail to michal.becak@gmail.com.