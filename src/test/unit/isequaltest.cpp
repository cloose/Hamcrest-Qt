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
    ASSERT_DOES_NOT_MATCH(matcher3, "bye");
}

void IsEqualTest::comparesTheElementsOfAQList()
{
    QStringList s1; s1 << "a" << "b";
    QStringList s2; s2 << "a" << "b";
    QStringList s3; s3 << "c" << "d";
    QStringList s4; s4 << "a" << "b" << "c" << "d";

    const QSharedPointer<Matcher<QStringList> > matcher = equalTo(s1);
    ASSERT_MATCHES(matcher, s1);
    ASSERT_MATCHES(matcher, s2);
    ASSERT_DOES_NOT_MATCH(matcher, s3);
    ASSERT_DOES_NOT_MATCH(matcher, s4);
}
