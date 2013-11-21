#ifndef HAMCREST_DESCRIPTION_H
#define HAMCREST_DESCRIPTION_H

namespace Hamcrest {

class SelfDescribing;

class Description
{
public:
    /**
     * Appends some plain text to the description.
     */
    virtual Description &appendText(const QString &text) = 0;

    /**
     * Appends the description of a {@link SelfDescribing} value to this description.
     */
    virtual Description &appendDescriptionOf(const SelfDescribing &value) = 0;

    template <typename T>
    Description &appendValue(const T &value);

    /**
     * Converts the description into a {@link QString} value.
     */
    virtual QString toString() const = 0;
};


template <typename T>
Description &Description::appendValue(const T &)
{
    return *this;
}

} // namespace Hamcrest

#endif // HAMCREST_DESCRIPTION_H
