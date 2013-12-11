#include "stringcontains.h"

namespace HamcrestQt {

bool StringContains::evalSubstringOf(const QString &str) const
{
    return str.contains(substring);
}

QString StringContains::relationship() const
{
    return QStringLiteral("containing");
}


} // namespace HamcrestQt

