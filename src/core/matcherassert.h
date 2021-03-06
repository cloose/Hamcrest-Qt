#ifndef HAMCRESTQT_MATCHERASSERT_H
#define HAMCRESTQT_MATCHERASSERT_H

#include <QList>
#include <qtestcase.h>
#include "matcher.h"
#include "stringdescription.h"

namespace HamcrestQt {

class MatcherAssert
{
public:
    class AssertionListener
    {
    public:
        virtual ~AssertionListener() {}
        virtual void assertionError(const QString &message) = 0;
    };

    static void addAssertionListener(MatcherAssert::AssertionListener *listener)
    {
        listeners.append(listener);
    }

    template <typename T>
    static bool assertThat(const QString &reason, const T &actual, const Matcher<T> &matcher, const char *file, int line)
    {
        if (!matcher.matches(actual)) {
            StringDescription description;
            description.appendText(reason)
                       .appendText("\nExpected: ")
                       .appendDescriptionOf(matcher)
                       .appendText("\n     but: ");
            matcher.describeMismatch(actual, description);

            // notify listeners
            notifyAssertionListener(description.toString());

            // assertion failed
            QTest::qFail(description.toString().toLatin1(), file, line);
            return false;
        }

        return true;
    }

    template <typename T>
    static bool assertThat(const QString &reason, const T &actual, const QSharedPointer<Matcher<T> > &matcher, const char *file, int line)
    {
        return assertThat(reason, actual, *matcher, file, line);
    }

    template <typename T>
    static bool assertThat(const T &actual, const Matcher<T> &matcher, const char *file, int line)
    {
        return assertThat(QStringLiteral(""), actual, matcher, file, line);
    }

    template <typename T>
    static bool assertThat(const T &actual, const QSharedPointer<Matcher<T> > &matcher, const char *file, int line)
    {
        return assertThat(QStringLiteral(""), actual, *matcher, file, line);
    }

    static bool assertThat(const QString &reason, bool assertion, const char *file, int line)
    {
        if (!assertion) {
            // notify listeners
            notifyAssertionListener(reason);

            // assertion failed
            QTest::qFail(reason.toLatin1(), file, line);
            return false;
        }

        return true;
    }

private:
    static void notifyAssertionListener(const QString &message)
    {
        foreach (MatcherAssert::AssertionListener *listener, listeners) {
            listener->assertionError(message);
        }
    }

    static QList<MatcherAssert::AssertionListener*> listeners;
};


#define ASSERT_THAT(actual, matcher) \
do {\
    if (!HamcrestQt::MatcherAssert::assertThat(actual, matcher, __FILE__, __LINE__))\
        return;\
} while (0)


#define ASSERT_THAT_MSG(reason, actual, matcher) \
do {\
    if (!HamcrestQt::MatcherAssert::assertThat(reason, actual, matcher, __FILE__, __LINE__))\
        return;\
} while (0)

} // namespace HamcrestQt

#endif // HAMCRESTQT_MATCHERASSERT_H
