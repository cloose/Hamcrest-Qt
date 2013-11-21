#include "basedescriptiontest.h"

#include <QtTest/QtTest>

#include <basedescription.h>
using namespace Hamcrest;

namespace {

static QString result;

class BaseDescriptionMock : public BaseDescription
{
public:
    BaseDescriptionMock() { result.clear(); }

protected:
    virtual void append(const QChar &c) { result += c; }
};

}

void BaseDescriptionTest::bracketsAppendedShortValue()
{
    QScopedPointer<Description> baseDescription(new BaseDescriptionMock());
    baseDescription->appendValue((short)2);
    QCOMPARE(result, QStringLiteral("<2s>"));
}
