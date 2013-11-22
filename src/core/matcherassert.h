#ifndef HAMCREST_MATCHERASSERT_H
#define HAMCREST_MATCHERASSERT_H

#include <QList>
#include <qtestcase.h>
#include "matcher.h"
#include "stringdescription.h"

namespace Hamcrest {

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
    if (!Hamcrest::MatcherAssert::assertThat(actual, matcher, __FILE__, __LINE__))\
        return;\
} while (0)


#define ASSERT_THAT2(reason, actual, matcher) \
do {\
    if (!Hamcrest::MatcherAssert::assertThat(reason, actual, matcher, __FILE__, __LINE__))\
        return;\
} while (0)

} // namespace Hamcrest

#endif // HAMCREST_MATCHERASSERT_H
