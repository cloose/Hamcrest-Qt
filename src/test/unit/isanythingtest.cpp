#include "isanythingtest.h"

#include <QtTest/QtTest>

#include <matcher/isanything.h>
#include <matcher.h>
using namespace HamcrestQt;

#include "abstractmatcher.h"

class CustomThing {};

void IsAnythingTest::alwaysEvaluatesToTrue()
{
    ASSERT_MATCHES_MSG("didn't match QObject", anything<QObject*>(), new QObject());
    ASSERT_MATCHES_MSG("didn't match custom object", anything<CustomThing*>(), new CustomThing());
    ASSERT_MATCHES_MSG("didn't match int value", anything<int>(), 42);
    ASSERT_MATCHES_MSG("didn't match String", anything<const char*>(), "hi");
}

void IsAnythingTest::hasUsefulDefaultDescription()
{
    ASSERT_DESCRIPTION("ANYTHING", anything<int>());
}

void IsAnythingTest::canOverrideDescription()
{
    QString description = "description";
    ASSERT_DESCRIPTION(description, anything<int>(description));
}
