#include "isequaltest.h"

#include <QtTest/QtTest>

#include <matcher/isequal.h>
using namespace Hamcrest;

#include "abstractmatcher.h"


void IsEqualTest::comparesObjectsUsingEqualsMethod()
{
    const QSharedPointer<Matcher<QString> > matcher1 = equalTo(QStringLiteral("hi"));
    ASSERT_MATCHES(matcher1, QStringLiteral("hi"));
    ASSERT_DOES_NOT_MATCH(matcher1, QStringLiteral("bye"));

    const QSharedPointer<Matcher<int> > matcher2 = equalTo(1);
    ASSERT_MATCHES(matcher2, 1);
    ASSERT_DOES_NOT_MATCH(matcher2, 2);

    const QSharedPointer<Matcher<const char*> > matcher3 = equalTo("hi");
    ASSERT_MATCHES(matcher3, "hi");
    ASSERT_DOES_NOT_MATCH(matcher3, "ha");
    ASSERT_DOES_NOT_MATCH(matcher3, "bye");
}
