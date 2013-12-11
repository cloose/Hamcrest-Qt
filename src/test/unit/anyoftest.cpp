#include "anyoftest.h"

#include <QtTest/QtTest>

#include <matcher/anyof.h>
#include <matcher/isequal.h>
#include <matcher/stringcontains.h>
#include <matcher/stringendswith.h>
#include <matcher/stringstartswith.h>
using namespace HamcrestQt;

#include "abstractmatcher.h"


void AnyOfTest::evaluatesToTheTheLogicalDisjunctionOfTwoOtherMatchers()
{
    QSharedPointer<Matcher<QString> > matcher = anyOf(startsWith("goo"), endsWith("ood"));

    ASSERT_MATCHES_MSG("didn't pass both sub-matchers", matcher, QStringLiteral("good"));
    ASSERT_MATCHES_MSG("didn't pass second sub-matcher", matcher, QStringLiteral("mood"));
    ASSERT_MATCHES_MSG("didn't pass first sub-matcher", matcher, QStringLiteral("goon"));
    ASSERT_DOES_NOT_MATCH_MSG("didn't fail both sub-matchers", matcher, QStringLiteral("flan"));
}

void AnyOfTest::evaluatesToTheTheLogicalDisjunctionOfManyOtherMatchers()
{
    QSharedPointer<Matcher<QString> > matcher = anyOf(startsWith("g"), startsWith("go"), endsWith("d"), containsString("oo"), startsWith("goo"));

    ASSERT_MATCHES_MSG("didn't pass middle sub-matcher", matcher, QStringLiteral("vlad"));
    ASSERT_DOES_NOT_MATCH_MSG("didn't fail all sub-matchers", matcher, QStringLiteral("flan"));
}

void AnyOfTest::hasAReadableDescription()
{
    ASSERT_DESCRIPTION("(\"good\" or \"bad\" or \"ugly\")",
                       anyOf(equalTo("good"), equalTo("bad"), equalTo("ugly")));
}
