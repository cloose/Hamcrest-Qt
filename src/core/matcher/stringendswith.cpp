#include "stringendswith.h"

namespace HamcrestQt {

bool StringEndsWith::evalSubstringOf(const QString &str) const
{
    return str.endsWith(substring);
}

QString StringEndsWith::relationship() const
{
    return QStringLiteral("ending with");
}


} // namespace HamcrestQt

