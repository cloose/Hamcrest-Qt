#include "basematchertest.h"

#include <QtTest/QtTest>

#include <basematcher.h>
#include <description.h>
using namespace HamcrestQt;

namespace {
class MatcherMock : public BaseMatcher<int>
{
public:
    virtual bool matches(const int &) const
    {
        QWARN("Unsupported Operation");
        return false;
    }

    virtual void describeTo(Description &description) const
    {
        description.appendText("SOME DESCRIPTION");
    }
};
}

void BaseMatcherTest::describesItselfWithToStringMethod()
{
    QScopedPointer<Matcher<int> > someMatcher(new MatcherMock());
    QCOMPARE(someMatcher->toString(), QStringLiteral("SOME DESCRIPTION"));
}
