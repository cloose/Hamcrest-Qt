#ifndef HAMCRESTQT_IS_H
#define HAMCRESTQT_IS_H

#include <QList>
#include "diagnosingmatcher.h"

namespace HamcrestQt {

/**
 * Calculates the logical conjunction of multiple matchers. Evaluation is shortcut, so
 * subsequent matchers are not called if an earlier matcher returns <code>false</code>.
 */
template <typename T>
class AllOf : public DiagnosingMatcher<T>
{
public:
    explicit AllOf(const QList<QSharedPointer<Matcher<T> > > &m) : matchers(m) {}

    virtual bool matches(const T &item, Description &mismatch) const
    {
        foreach (const QSharedPointer<Matcher<T> > &matcher, matchers) {
            if (!matcher->matches(item)) {
                mismatch.appendDescriptionOf(*matcher).appendText(" ");
                matcher->describeMismatch(item, mismatch);
                return false;
            }
        }

        return true;
    }

    virtual void describeTo(Description &description) const
    {
        description.appendList(QStringLiteral("("), QStringLiteral(" and "), QStringLiteral(")"),
                               matchers.begin(), matchers.end());
    }

private:
    QList<QSharedPointer<Matcher<T> > > matchers;
};

template <typename T>
QSharedPointer<Matcher<T> > allOf(const QList<QSharedPointer<Matcher<T> > > &matchers)
{
    return QSharedPointer<Matcher<T> >(new AllOf<T>(matchers));
}

template <typename T>
QSharedPointer<Matcher<T> > allOf(const QSharedPointer<Matcher<T> > &first, const QSharedPointer<Matcher<T> > &second)
{
    QList<QSharedPointer<Matcher<T> > > matchers;
    matchers.append(first);
    matchers.append(second);
    return allOf(matchers);
}

template <typename T>
QSharedPointer<Matcher<T> > allOf(const QSharedPointer<Matcher<T> > &first,
                                  const QSharedPointer<Matcher<T> > &second,
                                  const QSharedPointer<Matcher<T> > &third)
{
    QList<QSharedPointer<Matcher<T> > > matchers;
    matchers.append(first);
    matchers.append(second);
    matchers.append(third);
    return allOf(matchers);
}

} // namespace HamcrestQt

#endif // HAMCRESTQT_IS_H
