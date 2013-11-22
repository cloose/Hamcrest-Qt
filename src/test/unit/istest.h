#ifndef ISTEST_H
#define ISTEST_H

#include <QObject>

class IsTest : public QObject
{
    Q_OBJECT
    
private slots:
    void matchesTheSameWayTheUnderlyingMatcherDoes();
    void generatesIsPrefixInDescription();
    void providesConvenientShortcutForIsEqualTo();
};

#endif // ISTEST_H
