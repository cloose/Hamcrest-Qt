#include "stringdescription.h"

#include "selfdescribing.h"

namespace Hamcrest {

StringDescription::StringDescription()
{
}

QString StringDescription::toString() const
{
    return out;
}

QString StringDescription::toString(const SelfDescribing &selfDescribing)
{
    StringDescription description;
    return description.appendDescriptionOf(selfDescribing).toString();
}

QString StringDescription::asString(const SelfDescribing &selfDescribing)
{
    return toString(selfDescribing);
}

void StringDescription::appendString(const QString &str)
{
    out.append(str);
}

void StringDescription::append(const QChar &c)
{
    out.append(c);
}

} // namespace Hamcrest
