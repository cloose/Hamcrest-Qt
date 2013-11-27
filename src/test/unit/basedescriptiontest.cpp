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

void BaseDescriptionTest::quotesAppendedStringValue()
{
    QScopedPointer<Description> baseDescription(new BaseDescriptionMock());
    baseDescription->appendValue("foo\n");
    QCOMPARE(result, QStringLiteral("\"foo\\n\""));

    QScopedPointer<Description> baseDescription2(new BaseDescriptionMock());
    baseDescription2->appendValue(QString("foo\n"));
    QCOMPARE(result, QStringLiteral("\"foo\\n\""));
}

void BaseDescriptionTest::quotesAppendedCharacterValue()
{
    QScopedPointer<Description> baseDescription(new BaseDescriptionMock());
    baseDescription->appendValue('f');
    QCOMPARE(result, QStringLiteral("\"f\""));

    QScopedPointer<Description> baseDescription2(new BaseDescriptionMock());
    baseDescription2->appendValue(QChar('f'));
    QCOMPARE(result, QStringLiteral("\"f\""));
}

void BaseDescriptionTest::bracketsAppendedShortValue()
{
    QScopedPointer<Description> baseDescription(new BaseDescriptionMock());
    baseDescription->appendValue((short)2);
    QCOMPARE(result, QStringLiteral("<2s>"));
}

void BaseDescriptionTest::bracketsAppendedLongValue()
{
    QScopedPointer<Description> baseDescription(new BaseDescriptionMock());
    baseDescription->appendValue((long)2);
    QCOMPARE(result, QStringLiteral("<2L>"));
}

void BaseDescriptionTest::bracketsAppendedFloatValue()
{
    QScopedPointer<Description> baseDescription(new BaseDescriptionMock());
    baseDescription->appendValue((float)1.2);
    QCOMPARE(result, QStringLiteral("<1.2F>"));
}

void BaseDescriptionTest::bracketsAppendedDoubleValue()
{
    QScopedPointer<Description> baseDescription(new BaseDescriptionMock());
    baseDescription->appendValue((double)1.2);
    QCOMPARE(result, QStringLiteral("<1.2D>"));
}

void BaseDescriptionTest::bracketsAppendedBooleanValue()
{
    QScopedPointer<Description> baseDescription(new BaseDescriptionMock());
    baseDescription->appendValue(false);
    QCOMPARE(result, QStringLiteral("<false>"));
}
