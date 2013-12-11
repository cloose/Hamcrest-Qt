#ifndef HAMCRESTQT_STRINGCONTAINS_H
#define HAMCRESTQT_STRINGCONTAINS_H

#include <QSharedPointer>

#include "matcher.h"
#include "substringmatcher.h"

namespace HamcrestQt {

/**
 * Tests if the argument is a string that contains a substring.
 */
class StringContains : public SubstringMatcher
{
public:
    explicit StringContains(const QString &substring) : SubstringMatcher(substring) {}

protected:
    virtual bool evalSubstringOf(const QString &str) const;
    virtual QString relationship() const;
};

/**
 * Creates a matcher that matches if the examined {@link QString} contains the specified
 * {@link QString} anywhere.
 * <p/>
 * For example:
 * @code ASSERT_THAT("myStringOfNote", containsString("ring")); @endcode
 *
 * @param substring
 * the substring that the returned matcher will expect to find within any examined string
 *
 */
inline QSharedPointer<Matcher<QString> > containsString(const QString &substring)
{
    return QSharedPointer<Matcher<QString> >(new StringContains(substring));
}

// template specialization for c-style string
inline QSharedPointer<Matcher<QString> > containsString(const char *substring)
{
    return QSharedPointer<Matcher<QString> >(new StringContains(QString(substring)));
}

} // namespace HamcrestQt

#endif // HAMCRESTQT_STRINGCONTAINS_H
