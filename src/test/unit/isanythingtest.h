#ifndef ISANYTHINGTEST_H
#define ISANYTHINGTEST_H

#include <QObject>

class IsAnythingTest : public QObject
{
    Q_OBJECT
    
private slots:
    void alwaysEvaluatesToTrue();
    void hasUsefulDefaultDescription();
    void canOverrideDescription();
};

#endif // ISANYTHINGTEST_H
