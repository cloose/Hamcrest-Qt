#ifndef ALLOFTEST_H
#define ALLOFTEST_H

#include <QObject>

class AllOfTest : public QObject
{
    Q_OBJECT
    
private slots:
    void evaluatesToTheTheLogicalConjunctionOfTwoOtherMatchers();
    void evaluatesToTheTheLogicalConjunctionOfManyOtherMatchers();
    void hasAReadableDescription();
    void hasAMismatchDescriptionDescribingTheFirstFailingMatch();
};

#endif // ALLOFTEST_H
