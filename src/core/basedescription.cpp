#include "basedescription.h"

#include "selfdescribing.h"

namespace HamcrestQt {

Description &BaseDescription::appendText(const QString &text)
{
    appendString(text);
    return *this;
}

Description &BaseDescription::appendDescriptionOf(const SelfDescribing &value)
{
    value.describeTo(*this);
    return *this;
}

QString BaseDescription::toString() const
{
    return QStringLiteral("");
}

void BaseDescription::appendString(const QString &str)
{
    foreach (const QChar &c, str) {
        append(c);
    }
}

} // namespace HamcrestQt
