#include "abstractmatcher.h"

bool AbstractMatcher::assertMatches(const QSharedPointer<Hamcrest::Matcher<const char*> > &matcher, const char *arg, const char *file, int line)
{
    if (!matcher->matches(arg)) {
        QTest::qFail(QString("%1 because: '%2'").arg("").arg(mismatchDescription(matcher, arg)).toLatin1(), file, line);
        return false;
    }
    return true;
}


bool AbstractMatcher::assertDoesNotMatch(const QSharedPointer<Hamcrest::Matcher<const char *> > &matcher, const char *arg, const char *file, int line)
{
    return QTest::qVerify(!matcher->matches(arg), "matcher", "", file, line);
}
