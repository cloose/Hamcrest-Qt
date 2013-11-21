#ifndef BASEDESCRIPTIONTEST_H
#define BASEDESCRIPTIONTEST_H

#include <QObject>

class BaseDescriptionTest : public QObject
{
    Q_OBJECT
    
private slots:
    void bracketsAppendedShortValue();
    void bracketsAppendedLongValue();
    void bracketsAppendedFloatValue();
    void bracketsAppendedDoubleValue();
};

#endif // BASEDESCRIPTIONTEST_H
