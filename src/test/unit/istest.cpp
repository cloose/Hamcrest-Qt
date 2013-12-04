#include "istest.h"

#include <QtTest/QtTest>

#include <matcher/is.h>
#include <matcher/isequal.h>
#include <matcher.h>
using namespace HamcrestQt;

#include "abstractmatcher.h"


void IsTest::matchesTheSameWayTheUnderlyingMatcherDoes()
{
    const QSharedPointer<Matcher<bool> > matcher = is(equalTo(true));

    ASSERT_MATCHES(matcher, true);
    ASSERT_DOES_NOT_MATCH(matcher, false);
}

void IsTest::generatesIsPrefixInDescription()
{
    ASSERT_DESCRIPTION("is <true>", is(equalTo(true)));
    ASSERT_DESCRIPTION("is \"A\"", is("A"));
}

void IsTest::providesConvenientShortcutForIsEqualTo()
{
    QSharedPointer<Matcher<const char*> > matcher = is("A");

    ASSERT_MATCHES(matcher, "A");
    ASSERT_DOES_NOT_MATCH(is("A"), "B");
}
