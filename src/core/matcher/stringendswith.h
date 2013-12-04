#ifndef HAMCRESTQT_STRINGENDSWITH
#define HAMCRESTQT_STRINGENDSWITH

#include <QSharedPointer>
#include "matcher.h"
#include "substringmatcher.h"

namespace HamcrestQt {

class StringEndsWith : public SubstringMatcher
{
public:
    explicit StringEndsWith(const QString &substring) : SubstringMatcher(substring) {}

protected:
    virtual bool evalSubstringOf(const QString &str) const;
    virtual QString relationship() const;
};

/**
 * Creates a matcher that matches if the examined {@link QString} ends with the specified
 * {@link QString}.
 * <p/>
 * For example:
 * <pre>assertThat("myStringOfNote", endsWith("Note"))</pre>
 *
 * @param suffix
 * the substring that the returned matcher will expect at the end of any examined string
 */
QSharedPointer<Matcher<QString> > endsWith(const QString &suffix)
{
    return QSharedPointer<Matcher<QString> >(new StringEndsWith(suffix));
}

// template specialization for c-style string
inline QSharedPointer<Matcher<QString> > endsWith(const char *prefix)
{
    return QSharedPointer<Matcher<QString> >(new StringEndsWith(QString(prefix)));
}

} // namespace HamcrestQt

#endif // HAMCRESTQT_STRINGENDSWITH
