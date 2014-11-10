
#include "yawot/version.h"

#include "configure/version.h"

namespace yawot
{

unsigned int version()
{
    return LIBRARY_VERSION;
}

const std::string versionString()
{
    return LIBRARY_VERSION_STRING;
}

} // namespace yawot
