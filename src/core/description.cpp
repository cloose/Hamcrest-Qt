#include "description.h"

namespace Hamcrest {

Description &Description::appendValue(short value)
{
    appendString("<");
    appendString(QString().setNum(value));
    appendString("s>");

    return *this;
}

} // namespace Hamcrest
