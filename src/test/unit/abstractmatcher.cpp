#include "abstractmatcher.h"

bool AbstractMatcher::assertMatches(const QSharedPointer<HamcrestQt::Matcher<const char*> > &matcher, const char *arg, const char *file, int line)
{
    return assertMatches("Expected match, but mismatched", matcher, arg, file, line);
}

bool AbstractMatcher::assertMatches(const char *message, const QSharedPointer<HamcrestQt::Matcher<const char*> > &matcher, const char *arg, const char *file, int line)
{
    if (!matcher->matches(arg)) {
        QTest::qFail(QString("%1 because: '%2'").arg(message).arg(mismatchDescription(matcher, arg)).toLatin1(), file, line);
        return false;
    }
    return true;
}

bool AbstractMatcher::assertDoesNotMatch(const QSharedPointer<HamcrestQt::Matcher<const char *> > &matcher, const char *arg, const char *file, int line)
{
    return assertDoesNotMatch("Unexpected match", matcher, arg, file, line);
}

bool AbstractMatcher::assertDoesNotMatch(const char *message, const QSharedPointer<HamcrestQt::Matcher<const char *> > &matcher, const char *arg, const char *file, int line)
{
    return QTest::qVerify(!matcher->matches(arg), "matcher", message, file, line);
}
