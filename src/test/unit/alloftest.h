#ifndef ALLOFTEST_H
#define ALLOFTEST_H

#include <QObject>

class AllOfTest : public QObject
{
    Q_OBJECT
    
private slots:
    void hasAReadableDescription();
    void hasAMismatchDescriptionDescribingTheFirstFailingMatch();
};

#endif // ALLOFTEST_H
