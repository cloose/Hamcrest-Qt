#include <QtTest/QtTest>

#include "basedescriptiontest.h"
#include "basematchertest.h"
#include "matcherasserttest.h"

int main(int argc, char *argv[])
{
    int ret = 0;

    BaseDescriptionTest test;
    ret += QTest::qExec(&test, argc, argv);

    BaseMatcherTest test2;
    ret += QTest::qExec(&test2, argc, argv);

    MatcherAssertTest test3;
    ret += QTest::qExec(&test3, argc, argv);

    return ret;
}
