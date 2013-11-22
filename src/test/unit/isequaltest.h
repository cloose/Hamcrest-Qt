#ifndef ISEQUALTEST_H
#define ISEQUALTEST_H

#include <QObject>

class IsEqualTest : public QObject
{
    Q_OBJECT
    
private slots:
    void comparesObjectsUsingEqualsMethod();
};

#endif // ISEQUALTEST_H
