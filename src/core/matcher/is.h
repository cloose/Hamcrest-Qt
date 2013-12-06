#ifndef HAMCRESTQT_IS_H
#define HAMCRESTQT_IS_H

#include <QSharedPointer>

#include "basematcher.h"
#include "isequal.h"

namespace HamcrestQt {

/**
 * Decorates another Matcher, retaining the behaviour but allowing tests
 * to be slightly more expressive.
 *
 * For example: assertThat(cheese, equalTo(smelly))
 * vs. assertThat(cheese, is(equalTo(smelly)))
 */
template <typename T>
class Is : public BaseMatcher<T>
{
public:
    explicit Is(const QSharedPointer<Matcher<T> > &m) : matcher(m) {}

    virtual bool matches(const T &item) const
    {
        return matcher->matches(item);
    }

    virtual void describeTo(Description &description) const
    {
        description.appendText("is ").appendDescriptionOf(*matcher);
    }

    virtual void describeMismatch(const T &item, Description &description) const
    {
        matcher->describeMismatch(item, description);
    }

private:
    QSharedPointer<Matcher<T> > matcher;
};

template <typename T>
QSharedPointer<Matcher<T> > is(const QSharedPointer<Matcher<T> > &matcher)
{
    return QSharedPointer<Matcher<T> >(new Is<T>(matcher));
}

template <typename T>
QSharedPointer<Matcher<T> > is(const T &operand)
{
    return is(equalTo(operand));
}

// template specialization for c-style string
inline QSharedPointer<Matcher<const char*> > is(const char *operand)
{
    return QSharedPointer<Matcher<const char*> >(new Is<const char*>(equalTo(operand)));
}

} // namespace HamcrestQt

#endif // HAMCRESTQT_IS_H
