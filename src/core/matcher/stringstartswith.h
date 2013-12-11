#ifndef HAMCRESTQT_STRINGSTARTSWITH_H
#define HAMCRESTQT_STRINGSTARTSWITH_H

#include <QSharedPointer>

#include "matcher.h"
#include "substringmatcher.h"

namespace HamcrestQt {

/**
 * Tests if the argument is a string that starts with a substring.
 */
class StringStartsWith : public SubstringMatcher
{
public:
    explicit StringStartsWith(const QString &substring) : SubstringMatcher(substring) {}

protected:
    virtual bool evalSubstringOf(const QString &str) const;
    virtual QString relationship() const;
};

/**
 * Creates a matcher that matches if the examined @c QString starts with the specified
 * @c QString.
 * <p/>
 * For example:
 * <pre>assertThat("myStringOfNote", startsWith("my"))</pre>
 *
 * @param prefix
 * the substring that the returned matcher will expect at the start of any examined string
 */
inline QSharedPointer<Matcher<QString> > startsWith(const QString &prefix)
{
    return QSharedPointer<Matcher<QString> >(new StringStartsWith(prefix));
}

// template specialization for c-style string
inline QSharedPointer<Matcher<QString> > startsWith(const char *prefix)
{
    return QSharedPointer<Matcher<QString> >(new StringStartsWith(QString(prefix)));
}

} // namespace HamcrestQt

#endif // HAMCRESTQT_STRINGSTARTSWITH
