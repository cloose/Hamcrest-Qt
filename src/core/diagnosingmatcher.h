#ifndef HAMCRESTQT_DIAGNOSINGMATCHER_H
#define HAMCRESTQT_DIAGNOSINGMATCHER_H

#include "basematcher.h"

namespace HamcrestQt {

template <typename T>
class DiagnosingMatcher : public BaseMatcher<T>
{
public:
    virtual bool matches(const T &item) const
    {
        return matches(item, Description::NONE());
    }

    virtual void describeMismatch(const T &item, Description &mismatchDescription) const
    {
        matches(item, mismatchDescription);
    }

protected:
        virtual bool matches(const T &item, Description &mismatchDescription) const = 0;
};

} // namespace HamcrestQt

#endif // HAMCRESTQT_DIAGNOSINGMATCHER_H
