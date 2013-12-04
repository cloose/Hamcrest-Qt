#ifndef ABSTRACTMATCHER_H
#define ABSTRACTMATCHER_H

#include <QSharedPointer>
#include <qtestcase.h>
#include <matcher.h>
#include <stringdescription.h>

class AbstractMatcher
{
public:
    template <typename T>
    static bool assertMatches(const QSharedPointer<HamcrestQt::Matcher<T> > &matcher, const T &arg, const char *file, int line)
    {
        return assertMatches(QString("Expected match, but mismatched"), matcher, arg, file, line);
    }

    template <typename T>
    static bool assertMatches(const QString &message, const QSharedPointer<HamcrestQt::Matcher<T> > &matcher, const T &arg, const char *file, int line)
    {
        if (!matcher->matches(arg)) {
            QTest::qFail(QString("%1 because: '%2'").arg(message).arg(mismatchDescription(matcher, arg)).toLatin1(), file, line);
            return false;
        }
        return true;
    }

    template <typename T>
    static bool assertDoesNotMatch(const QSharedPointer<HamcrestQt::Matcher<T> > &matcher, const T &arg, const char *file, int line)
    {
        return assertDoesNotMatch(QStringLiteral("Unexpected match"), matcher, arg, file, line);
    }

    template <typename T>
    static bool assertDoesNotMatch(const QString &message, const QSharedPointer<HamcrestQt::Matcher<T> > &matcher, const T &arg, const char *file, int line)
    {
        return QTest::qVerify(!matcher->matches(arg), "matcher", message.toLatin1(), file, line);
    }

    template <typename T>
    static bool assertDescription(const QString &expected, const QSharedPointer<HamcrestQt::Matcher<T> > &matcher, const char *file, int line)
    {
        HamcrestQt::StringDescription description;
        description.appendDescriptionOf(*matcher);
        return QTest::qCompare(description.toString(), expected, "description", "expected", file, line);
    }

    template <typename T>
    static bool assertMismatchDescription(const QString &expected, const QSharedPointer<HamcrestQt::Matcher<T> > &matcher, const T &arg, const char *file, int line)
    {
        return QTest::qCompare(mismatchDescription(matcher, arg), expected, "description", "expected", file, line);
    }

    static bool assertMismatchDescription(const QString &expected, const QSharedPointer<HamcrestQt::Matcher<const char*> > &matcher, const char *arg, const char *file, int line)
    {
        return QTest::qCompare(mismatchDescription(matcher, arg), expected, "description", "expected", file, line);
    }

    template <typename T>
    static QString mismatchDescription(const QSharedPointer<HamcrestQt::Matcher<T> > &matcher, const T &arg)
    {
        HamcrestQt::StringDescription description;
        matcher->describeMismatch(arg, description);
        return description.toString().trimmed();
    }

    static bool assertMatches(const QSharedPointer<HamcrestQt::Matcher<const char*> > &matcher, const char *arg, const char *file, int line);
    static bool assertDoesNotMatch(const QSharedPointer<HamcrestQt::Matcher<const char*> > &matcher, const char *arg, const char *file, int line);
};

#define ASSERT_MATCHES(matcher, arg) \
do {\
    if (!AbstractMatcher::assertMatches(matcher, arg, __FILE__, __LINE__)) \
        return;\
} while (0)

#define ASSERT_DOES_NOT_MATCH(matcher, arg) \
do {\
    if (!AbstractMatcher::assertDoesNotMatch(matcher, arg, __FILE__, __LINE__)) \
        return;\
} while (0)

#define ASSERT_DESCRIPTION(expected, matcher) \
do {\
    if (!AbstractMatcher::assertDescription(expected, matcher, __FILE__, __LINE__)) \
        return;\
} while (0)

#define ASSERT_MISMATCH_DESCRIPTION(expected, matcher, arg) \
do {\
    if (!AbstractMatcher::assertMismatchDescription(expected, matcher, arg, __FILE__, __LINE__)) \
        return;\
} while (0)

#endif // ABSTRACTMATCHER_H
