#include "matcherasserttest.h"

#include <QtTest/QtTest>

#include <matcher/isequal.h>
#include <matcherassert.h>
using namespace Hamcrest;

// custom exception for assertion errors
class AssertionError : public std::exception
{
public:
    AssertionError(const char *msg) : message(msg) {}
    virtual const char *what() const throw() { return message; }

private:
    const char *message;
};

// custom AssertionListener so we can throw an exception with the assertion message
class MatcherAssertTest::TestAssertionListener : public MatcherAssert::AssertionListener
{
public:
    virtual void assertionError(const QString &message)
    {
        throw AssertionError(message.toLatin1());
    }
};


void MatcherAssertTest::initTestCase()
{
    // register our custom assertion listener
    listener = new TestAssertionListener();
    MatcherAssert::addAssertionListener(listener);
}

void MatcherAssertTest::includesDescriptionOfTestedValueInErrorMessage()
{
    QString expected = "expected";
    QString actual = "actual";

    QString expectedMessage = "identifier\nExpected: \"expected\"\n     but: was \"actual\"";

    try {
        ASSERT_THAT2("identifier", actual, equalTo(expected));
    } catch (const AssertionError &e) {
        QVERIFY(QString(e.what()).startsWith(expectedMessage));
        return;
    }

    QFAIL("should have failed");
}

void MatcherAssertTest::cleanupTestCase()
{
    delete listener;
}
