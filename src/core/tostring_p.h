#ifndef HAMCREST_TOSTRING_P_H
#define HAMCREST_TOSTRING_P_H

#include <qtestcase.h>
#include "matcher.h"

namespace QTest
{

inline char* toString(bool value)
{
    return value ? qstrdup("true") : qstrdup("false");
}

template <typename T>
inline char* toString(const QSharedPointer<HamcrestQt::Matcher<T> > &matcher)
{
    return qstrdup(matcher->toString().toLatin1());
}

} // namespace QTest

#endif // HAMCREST_TOSTRING_P_H
