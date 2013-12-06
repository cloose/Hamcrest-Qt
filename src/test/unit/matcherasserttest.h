#ifndef MATCHERASSERTTEST_H
#define MATCHERASSERTTEST_H

#include <QObject>

class MatcherAssertTest : public QObject
{
    Q_OBJECT
    
private slots:
    void initTestCase();

    void includesDescriptionOfTestedValueInErrorMessage();
    void descriptionCanBeElided();
    void canTestBooleanDirectly();
    void includesMismatchDescription();

    void cleanupTestCase();

private:
    class TestAssertionListener;
    TestAssertionListener *listener;
};

#endif // MATCHERASSERTTEST_H
