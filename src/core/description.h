#ifndef HAMCREST_DESCRIPTION_H
#define HAMCREST_DESCRIPTION_H

#include <QString>

namespace Hamcrest {

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

    /**
     * Converts the description into a {@link QString} value.
     */
    virtual QString toString() const = 0;

protected:
    virtual void appendString(const QString &str) = 0;
    virtual void append(const QChar &c) = 0;
};


template <typename T>
Description &Description::appendValue(const T &)
{
    return *this;
}

} // namespace Hamcrest

#endif // HAMCREST_DESCRIPTION_H
