#include "isnottest.h"

#include <QtTest/QtTest>

#include <matcher/isnot.h>
#include <matcher/isequal.h>
#include <matcher.h>
using namespace HamcrestQt;

#include "abstractmatcher.h"


void IsNotTest::evaluatesToTheTheLogicalNegationOfAnotherMatcher()
{
    const QSharedPointer<Matcher<const char*> > matcher = _not(equalTo("A"));

    ASSERT_MATCHES(matcher, "B");
    ASSERT_DOES_NOT_MATCH(matcher, "A");
}

void IsNotTest::providesConvenientShortcutForNotEqualTo()
{
    const QSharedPointer<Matcher<const char*> > matcher = _not("A");

    ASSERT_MATCHES(matcher, "B");
    ASSERT_DOES_NOT_MATCH(matcher, "A");
}

void IsNotTest::usesDescriptionOfNegatedMatcherWithPrefix()
{
   ASSERT_DESCRIPTION("not \"A\"", _not("A"));
}
