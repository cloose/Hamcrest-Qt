#include "alloftest.h"

#include <QtTest/QtTest>

#include <matcher/allof.h>
#include <matcher/isequal.h>
using namespace HamcrestQt;

#include "abstractmatcher.h"


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
