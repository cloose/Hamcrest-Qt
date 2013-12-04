#include "stringstartswith.h"

namespace HamcrestQt {

bool StringStartsWith::evalSubstringOf(const QString &str) const
{
    return str.startsWith(substring);
}

QString StringStartsWith::relationship() const
{
    return QStringLiteral("starting with");
}


} // namespace HamcrestQt

