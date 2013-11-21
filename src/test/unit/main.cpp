#include <QtTest/QtTest>

#include "basedescriptiontest.h"

int main(int argc, char *argv[])
{
    int ret = 0;

    BaseDescriptionTest test;
    ret += QTest::qExec(&test, argc, argv);

    return ret;
}
