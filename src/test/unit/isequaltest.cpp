#include "isequaltest.h"

#include <QtTest/QtTest>

#include <matcher/isequal.h>
using namespace Hamcrest;


void IsEqualTest::comparesObjectsUsingEqualsMethod()
{
    QString *null1 = 0;

    const QSharedPointer<Matcher<QString> > matcher1 = equalTo(QStringLiteral("hi"));
    QVERIFY(matcher1->matches(QStringLiteral("hi")));
    QVERIFY(!matcher1->matches(QStringLiteral("bye")));
    QVERIFY(!matcher1->matches(*null1));

    int *null2 = 0;

    const QSharedPointer<Matcher<int> > matcher2 = equalTo(1);
    QVERIFY(matcher2->matches(1));
    QVERIFY(!matcher2->matches(2));
    QVERIFY(!matcher2->matches(*null2));
}
