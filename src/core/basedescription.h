#ifndef HAMCREST_BASEDESCRIPTION_H
#define HAMCREST_BASEDESCRIPTION_H

#include "description.h"

namespace Hamcrest {


/**
* A {@link Description} that is stored as a string.
*/
class BaseDescription : public Description
{
public:
    // interface Description
    virtual Description &appendText(const QString &text);
    virtual Description &appendDescriptionOf(const SelfDescribing &value);
    virtual QString toString() const;

protected:
    /**
     * Append the String <var>str</var> to the description.
     * The default implementation passes every character to {@link #append(QChar)}.
     * Override in subclasses to provide an efficient implementation.
     */
    virtual void appendString(const QString &str);
};

} // namespace Hamcrest

#endif // HAMCREST_BASEDESCRIPTION_H
