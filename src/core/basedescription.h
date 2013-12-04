#ifndef HAMCRESTQT_BASEDESCRIPTION_H
#define HAMCRESTQT_BASEDESCRIPTION_H

#include "description.h"

namespace HamcrestQt {


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

} // namespace HamcrestQt

#endif // HAMCRESTQT_BASEDESCRIPTION_H
