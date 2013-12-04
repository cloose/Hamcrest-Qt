#ifndef HAMCRESTQT_ISNOT_H
#define HAMCRESTQT_ISNOT_H

#include "basematcher.h"
#include "isequal.h"

namespace HamcrestQt {

/**
 * Calculates the logical negation of a matcher.
 */
template <typename T>
class IsNot : public BaseMatcher<T>
{
public:
    explicit IsNot(const QSharedPointer<Matcher<T> > &m) : matcher(m) {}

    virtual bool matches(const T &item) const
    {
        return !matcher->matches(item);
    }

    virtual void describeTo(Description &description) const
    {
        description.appendText("not ").appendDescriptionOf(*matcher);
    }

private:
    QSharedPointer<Matcher<T> > matcher;
};


/**
 * Creates a matcher that wraps an existing matcher, but inverts the logic by which
 * it will match.
 * <p/>
 * For example:
 * <pre>assertThat(cheese, is(not(equalTo(smelly))))</pre>
 *
 * @param matcher
 * the matcher whose sense should be inverted
 */
template <typename T>
QSharedPointer<Matcher<T> > _not(const QSharedPointer<Matcher<T> > &matcher)
{
    return QSharedPointer<Matcher<T> >(new IsNot<T>(matcher));
}

/**
 * A shortcut to the frequently used <code>not(equalTo(x))</code>.
 * <p/>
 * For example:
 * <pre>assertThat(cheese, is(not(smelly)))</pre>
 * instead of:
 * <pre>assertThat(cheese, is(not(equalTo(smelly))))</pre>
 *
 * @param value
 * the value that any examined object should <b>not</b> equal
 */
template <typename T>
QSharedPointer<Matcher<T> > _not(const T &operand)
{
    return _not(equalTo(operand));
}

// template specialization for c-style string
inline QSharedPointer<Matcher<const char*> > _not(const char *operand)
{
    return QSharedPointer<Matcher<const char*> >(new IsNot<const char*>(equalTo(operand)));
}

} // namespace HamcrestQt

#endif // HAMCRESTQT_ISNOT_H
