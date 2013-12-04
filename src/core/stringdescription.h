#ifndef HAMCRESTQT_STRINGDESCRIPTION_H
#define HAMCRESTQT_STRINGDESCRIPTION_H

#include "basedescription.h"

namespace HamcrestQt {

class SelfDescribing;

/**
* A {@link Description} that is stored as a string.
*/
class StringDescription : public BaseDescription
{
public:
    StringDescription();

    virtual QString toString() const;

    /**
     * Return the description of a {@link SelfDescribing} object as a String.
     *
     * @param selfDescribing
     * The object to be described.
     * @return
     * The description of the object.
     */
    static QString toString(const SelfDescribing &selfDescribing);

    /**
     * Alias for {@link #toString(SelfDescribing)}.
     */
    static QString asString(const SelfDescribing &selfDescribing);

protected:
    virtual void appendString(const QString &str);
    virtual void append(const QChar &c);

private:
    QString out;
};

} // namespace HamcrestQt

#endif // HAMCRESTQT_STRINGDESCRIPTION_H
