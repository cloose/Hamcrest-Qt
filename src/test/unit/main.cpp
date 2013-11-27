#include <QtTest/QtTest>

#include "basedescriptiontest.h"
#include "basematchertest.h"
#include "isequaltest.h"
#include "isnottest.h"
#include "istest.h"
#include "matcherasserttest.h"

int main(int argc, char *argv[])
{
    int ret = 0;

    BaseDescriptionTest test;
    ret += QTest::qExec(&test, argc, argv);

    BaseMatcherTest test2;
    ret += QTest::qExec(&test2, argc, argv);

    IsEqualTest test3;
    ret += QTest::qExec(&test3, argc, argv);

    IsNotTest test4;
    ret += QTest::qExec(&test4, argc, argv);

    IsTest test5;
    ret += QTest::qExec(&test5, argc, argv);

    MatcherAssertTest test6;
    ret += QTest::qExec(&test6, argc, argv);

    return ret;
}
