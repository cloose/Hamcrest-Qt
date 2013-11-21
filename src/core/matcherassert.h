#ifndef HAMCREST_MATCHERASSERT_H
#define HAMCREST_MATCHERASSERT_H

#include <qtestcase.h>
#include "matcher.h"
#include "stringdescription.h"

namespace Hamcrest {

class MatcherAssert
{
public:
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

            QTest::qFail(description.toString().toLatin1(), file, line);
            return false;
        }

        return true;
    }
};

#define ASSERT_THAT2(reason, actual, matcher) \
do {\
    if (!Hamcrest::MatcherAssert::assertThat(reason, actual, matcher, __FILE__, __LINE__))\
        return;\
} while (0)

} // namespace Hamcrest

#endif // HAMCREST_MATCHERASSERT_H
