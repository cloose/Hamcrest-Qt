#ifndef HAMCREST_BASEMATCHER_H
#define HAMCREST_BASEMATCHER_H

#include "matcher.h"

#include "description.h"
#include "stringdescription.h"

namespace Hamcrest {

/**
 * BaseClass for all Matcher implementations.
 *
 * @see Matcher
 */
template <typename T>
class BaseMatcher : public Matcher<T>
{
public:
    virtual void describeMismatch(const T &item, Description &description) const
    {
        description.appendText(QStringLiteral("was ")).appendValue(item);
    }

    virtual QString toString() const
    {
        return StringDescription::toString(*this);
    }
};

} // namespace Hamcrest

#endif // HAMCREST_BASEMATCHER_H
