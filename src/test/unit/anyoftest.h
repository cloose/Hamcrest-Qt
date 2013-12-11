#ifndef ANYOFTEST_H
#define ANYOFTEST_H

#include <QObject>

class AnyOfTest : public QObject
{
    Q_OBJECT

private slots:
    void evaluatesToTheTheLogicalDisjunctionOfTwoOtherMatchers();
    void evaluatesToTheTheLogicalDisjunctionOfManyOtherMatchers();
    void hasAReadableDescription();
};

#endif // ANYOFTEST_H
