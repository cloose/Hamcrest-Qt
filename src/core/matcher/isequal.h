#ifndef HAMCRESTQT_ISEQUAL_H
#define HAMCRESTQT_ISEQUAL_H

#include "basematcher.h"
#include "description.h"
#include "areequal_p.h"

namespace HamcrestQt {

/**
 * Is the value equal to another value, as tested by the
 * operator==() method?
 */
template <typename T>
class IsEqual : public BaseMatcher<T>
{
public:
    explicit IsEqual(const T &equalArg) : expectedValue(equalArg) {}

    virtual bool matches(const T &actualValue) const
    {
        return AreEqual(actualValue, expectedValue);
    }

    virtual void describeTo(Description &description) const
    {
        description.appendValue(expectedValue);
    }

private:
    T expectedValue;
};

template <typename T>
QSharedPointer<Matcher<T> > equalTo(const T &operand)
{
    return QSharedPointer<Matcher<T> >(new IsEqual<T>(operand));
}

// template specialization for c-style string
inline QSharedPointer<Matcher<const char*> > equalTo(const char operand[])
{
    return QSharedPointer<Matcher<const char*> >(new IsEqual<const char*>(operand));
}

} // namespace HamcrestQt

#endif // HAMCRESTQT_ISEQUAL_H
