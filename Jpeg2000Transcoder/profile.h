#ifndef PROFILE_H
#define PROFILE_H

#include "qstring.h"

class Profile
{
public:
	Profile(void);
	~Profile(void);
	QString name;			/**< name of profile */
	QString definition;		/**< definition of profile */
	QString institution;	/**< institution that created the profile */
	QString parameters;		/**< parameters of profile, this must be always set in ini file */
	QString compression;	/**< compression ratio eg. 1:10 */
	QString quality;		/**< quality of compression (lossy/lossless) */
};
#endif