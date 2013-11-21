#ifndef BASEMATCHERTEST_H
#define BASEMATCHERTEST_H

#include <QObject>

class BaseMatcherTest : public QObject
{
    Q_OBJECT

private slots:
    void describesItselfWithToStringMethod();
};

#endif // BASEMATCHERTEST_H
