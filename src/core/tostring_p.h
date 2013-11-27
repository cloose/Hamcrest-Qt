#ifndef HAMCREST_TOSTRING_P_H
#define HAMCREST_TOSTRING_P_H

#include <qtestcase.h>

namespace QTest
{

inline char* toString(bool value)
{
    return value ? qstrdup("true") : qstrdup("false");
}

} // namespace QTest

#endif // HAMCREST_TOSTRING_P_H
