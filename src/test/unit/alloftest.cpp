#include "alloftest.h"

#include <QtTest/QtTest>

#include <matcher/allof.h>
#include <matcher/isequal.h>
#include <matcher/stringendswith.h>
#include <matcher/stringstartswith.h>
using namespace HamcrestQt;

#include "abstractmatcher.h"


void AllOfTest::evaluatesToTheTheLogicalConjunctionOfTwoOtherMatchers()
{
    QSharedPointer<Matcher<QString> > matcher = allOf(startsWith("goo"), endsWith("ood"));

    ASSERT_MATCHES_MSG("didn't pass both sub-matchers", matcher, QStringLiteral("good"));
    ASSERT_DOES_NOT_MATCH_MSG("didn't fail first sub-matcher", matcher, QStringLiteral("mood"));
    ASSERT_DOES_NOT_MATCH_MSG("didn't fail second sub-matcher", matcher, QStringLiteral("goon"));
    ASSERT_DOES_NOT_MATCH_MSG("didn't fail both sub-matchers", matcher, QStringLiteral("fred"));
}

void AllOfTest::evaluatesToTheTheLogicalConjunctionOfManyOtherMatchers()
{
    QSharedPointer<Matcher<QString> > matcher = allOf(startsWith("g"), startsWith("go"), endsWith("d"), startsWith("go"), startsWith("goo"));

    ASSERT_MATCHES_MSG("didn't pass all sub-matchers", matcher, QStringLiteral("good"));
    ASSERT_DOES_NOT_MATCH_MSG("didn't fail middle sub-matcher", matcher, QStringLiteral("goon"));
}

void AllOfTest::hasAReadableDescription()
{
    ASSERT_DESCRIPTION("(\"good\" and \"bad\" and \"ugly\")",
                       allOf(equalTo("good"), equalTo("bad"), equalTo("ugly")));
}

void AllOfTest::hasAMismatchDescriptionDescribingTheFirstFailingMatch()
{
    ASSERT_MISMATCH_DESCRIPTION("\"good\" was \"bad\"",
                                allOf(equalTo("bad"), equalTo("good")), "bad");
}
