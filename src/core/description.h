#ifndef HAMCRESTQT_DESCRIPTION_H
#define HAMCRESTQT_DESCRIPTION_H

#include <QString>
#include "tostring_p.h"

namespace HamcrestQt {

class SelfDescribing;

/**
* A description of a Matcher. A Matcher will describe itself to a description
* which can later be used for reporting.
*
* @see Matcher#describeTo(Description)
*/
class Description
{
public:
    virtual ~Description() {}

    /**
     * Appends some plain text to the description.
     */
    virtual Description &appendText(const QString &text) = 0;

    /**
     * Appends the description of a {@link SelfDescribing} value to this description.
     */
    virtual Description &appendDescriptionOf(const SelfDescribing &value) = 0;

    /**
     * Appends an arbitrary value to the description.
     */
    template <typename T>
    Description &appendValue(const T &value);

    Description &appendValue(short value);
    Description &appendValue(long value);
    Description &appendValue(float value);
    Description &appendValue(double value);

    Description &appendValue(const char *value);
    Description &appendValue(const QString &value);

    Description &appendValue(char value);
    Description &appendValue(const QChar &value);

    /**
     * Appends a list of {@link SelfDescribing} objects
     * to the description.
     */
    template <typename Iterator>
    Description &appendList(const QString &start, const QString &separator, const QString &end,
                            Iterator startIterator, Iterator endIterator)
    {
        bool separate = false;

        appendString(start);
        while (startIterator != endIterator) {
            if (separate) appendString(separator);
            SelfDescribing &selfDescribing = dynamic_cast<SelfDescribing&>(**startIterator);
            appendDescriptionOf(selfDescribing);
            startIterator++;
            separate = true;
        }
        appendString(end);

        return *this;
    }

    /**
     * Converts the description into a @c QString value.
     */
    virtual QString toString() const = 0;

    class NullDescription;
    static Description &NONE();

protected:
    virtual void appendString(const QString &str) = 0;
    virtual void append(const QChar &c) = 0;

    virtual void toCppSyntaxString(const QString &unformatted);
    virtual void toCppSyntax(const QChar &ch);
};


template <typename T>
Description &Description::appendValue(const T &value)
{
    appendString("<");
    appendString(QTest::toString(value));
    appendString(">");
    return *this;
}

} // namespace HamcrestQt

#endif // HAMCRESTQT_DESCRIPTION_H
