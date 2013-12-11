#ifndef HAMCRESTQT_MATCHER_H
#define HAMCRESTQT_MATCHER_H

#include "selfdescribing.h"

/**
 * Hamcrest-Qt is a library of matchers, which can be combined in to
 * create flexible expressions of intent in tests.
 */
namespace HamcrestQt {

class Description;

/**
 * A matcher over acceptable values.
 * A matcher is able to describe itself to give feedback when it fails.
 *
 * @see BaseMatcher
 */
template <typename T>
class Matcher : public SelfDescribing
{
public:
    virtual ~Matcher()  {}

    /**
     * Evaluates the matcher for argument <var>item</var>.
     *
     * @param item the object against which the matcher is evaluated.
     * @return <code>true</code> if <var>item</var> matches, otherwise <code>false</code>.
     *
     * @see BaseMatcher
     */
    virtual bool matches(const T &item) const = 0;

    /**
     * Generate a description of why the matcher has not accepted the item.
     * The description will be part of a larger description of why a matching
     * failed, so it should be concise.
     * This method assumes that <code>matches(item)</code> is false, but
     * will not check this.
     *
     * @param item The item that the Matcher has rejected.
     * @param mismatchDescription
     * The description to be built or appended to.
     */
    virtual void describeMismatch(const T &item, Description &mismatchDescription) const = 0;

    virtual QString toString() const = 0;
};

} // namespace HamcrestQt

#endif // HAMCRESTQT_MATCHER_H
