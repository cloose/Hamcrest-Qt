#include "description.h"

namespace Hamcrest {

Description &Description::appendValue(short value)
{
    appendString("<");
    appendString(QString().setNum(value));
    appendString("s>");

    return *this;
}

Description &Description::appendValue(long value)
{
    appendString("<");
    appendString(QString().setNum(value));
    appendString("L>");

    return *this;
}

Description &Description::appendValue(float value)
{
    appendString("<");
    appendString(QString().setNum(value));
    appendString("F>");

    return *this;
}

Description &Description::appendValue(double value)
{
    appendString("<");
    appendString(QString().setNum(value));
    appendString("D>");

    return *this;
}

} // namespace Hamcrest
