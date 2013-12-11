#include <QtTest/QtTest>

#include "alloftest.h"
#include "anyoftest.h"
#include "basedescriptiontest.h"
#include "basematchertest.h"
#include "isequaltest.h"
#include "isnottest.h"
#include "istest.h"
#include "matcherasserttest.h"

int main(int argc, char *argv[])
{
    int ret = 0;

    AllOfTest test;
    ret += QTest::qExec(&test, argc, argv);

    AnyOfTest test2;
    ret += QTest::qExec(&test2, argc, argv);

    BaseDescriptionTest test3;
    ret += QTest::qExec(&test3, argc, argv);

    BaseMatcherTest test4;
    ret += QTest::qExec(&test4, argc, argv);

    IsEqualTest test5;
    ret += QTest::qExec(&test5, argc, argv);

    IsNotTest test6;
    ret += QTest::qExec(&test6, argc, argv);

    IsTest test7;
    ret += QTest::qExec(&test7, argc, argv);

    MatcherAssertTest test8;
    ret += QTest::qExec(&test8, argc, argv);

    return ret;
}
