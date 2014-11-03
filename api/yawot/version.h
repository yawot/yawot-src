
#ifndef YAWOT_VERSION_H
#define YAWOT_VERSION_H

namespace yawot
{

/**
 * Return the version of the *library* as an
 * unsigned integer.  The format is XXYYZZ
 * XX - major version
 * YY - minor version
 * ZZ - patch version
 */
unsigned int version();

/**
 * Return the version of the *library* as a
 * string.  The format is "X.Y.Z"
 * XX - major version
 * YY - minor version
 * ZZ - patch version
 */
const std::string versionString();

}

#endif /* YAWOT_VERSION_H */

