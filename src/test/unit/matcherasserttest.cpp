#include "matcherasserttest.h"

#include <QtTest/QtTest>

#include <matcher/isequal.h>
#include <matcherassert.h>
using namespace HamcrestQt;

// custom exception for assertion errors
class AssertionError : public std::exception
{
public:
    AssertionError(const char *msg) : message(msg) {}
    ~AssertionError() throw() { delete[] message; }
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
        throw AssertionError(qstrdup(message.toLatin1()));
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
        ASSERT_THAT_MSG("identifier", actual, equalTo(expected));
    } catch (const AssertionError &e) {
        QVERIFY(QString(e.what()).startsWith(expectedMessage));
        return;
    }

    QFAIL("should have failed");
}

void MatcherAssertTest::descriptionCanBeElided()
{
    QString expected = "expected";
    QString actual = "actual";

    QString expectedMessage = "\nExpected: \"expected\"\n     but: was \"actual\"";

    try {
        ASSERT_THAT(actual, equalTo(expected));
    } catch (const AssertionError &e) {
        QVERIFY(QString(e.what()).startsWith(expectedMessage));
        return;
    }

    QFAIL("should have failed");
}

void MatcherAssertTest::canTestBooleanDirectly()
{
    ASSERT_THAT("success reason message", true);

    try {
        ASSERT_THAT("failing reason message", false);
    } catch (const AssertionError &e) {
        QCOMPARE(e.what(), "failing reason message");
        return;
    }

    QFAIL("should have failed");
}

class MatcherWithCustomMismatchDescription : public BaseMatcher<QString>
{
public:
    virtual bool matches(const QString &) const
    {
        return false;
    }

    virtual void describeTo(Description &description) const
    {
        description.appendText("Something cool");
    }

    virtual void describeMismatch(const QString &, Description &mismatchDescription) const
    {
        mismatchDescription.appendText("Not cool");
    }
};

void MatcherAssertTest::includesMismatchDescription()
{
    Matcher<QString> *matcherWithCustomMismatchDescription = new MatcherWithCustomMismatchDescription();

    QString expectedMessage = "\nExpected: Something cool\n     but: Not cool";

    try {
        ASSERT_THAT(QStringLiteral("Value"), *matcherWithCustomMismatchDescription);
        QFAIL("should have failed");
    } catch (const AssertionError &e) {
        QCOMPARE(QString(e.what()), expectedMessage);
    }
}

void MatcherAssertTest::cleanupTestCase()
{
    delete listener;
}
