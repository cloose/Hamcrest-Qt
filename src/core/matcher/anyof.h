#ifndef HAMCRESTQT_ANYOF_H
#define HAMCRESTQT_ANYOF_H

#include <QList>
#include <QSharedPointer>

#include "shortcutcombination.h"

namespace HamcrestQt {

/**
 * Calculates the logical disjunction of multiple matchers. Evaluation is shortcut, so
 * subsequent matchers are not called if an earlier matcher returns <code>true</code>.
 */
template <typename T>
class AnyOf : public ShortcutCombination<T>
{
public:
    explicit AnyOf(const QList<QSharedPointer<Matcher<T> > > &m) : ShortcutCombination<T>(m) {}

    virtual bool matches(const T &item) const
    {
        return matches(item, true);
    }

    virtual void describeTo(Description &description) const
    {
        describeTo(description, QStringLiteral("or"));
    }

    using ShortcutCombination<T>::describeTo;
    using ShortcutCombination<T>::matches;
};

template <typename T>
QSharedPointer<Matcher<T> > anyOf(const QList<QSharedPointer<Matcher<T> > > &matchers)
{
    return QSharedPointer<Matcher<T> >(new AnyOf<T>(matchers));
}

template <typename T>
QSharedPointer<Matcher<T> > anyOf(const QSharedPointer<Matcher<T> > &first,
                                  const QSharedPointer<Matcher<T> > &second)
{
    QList<QSharedPointer<Matcher<T> > > matchers;
    matchers.append(first);
    matchers.append(second);
    return anyOf(matchers);
}

template <typename T>
QSharedPointer<Matcher<T> > anyOf(const QSharedPointer<Matcher<T> > &first,
                                  const QSharedPointer<Matcher<T> > &second,
                                  const QSharedPointer<Matcher<T> > &third)
{
    QList<QSharedPointer<Matcher<T> > > matchers;
    matchers.append(first);
    matchers.append(second);
    matchers.append(third);
    return anyOf(matchers);
}

template <typename T>
QSharedPointer<Matcher<T> > anyOf(const QSharedPointer<Matcher<T> > &first,
                                  const QSharedPointer<Matcher<T> > &second,
                                  const QSharedPointer<Matcher<T> > &third,
                                  const QSharedPointer<Matcher<T> > &fourth)
{
    QList<QSharedPointer<Matcher<T> > > matchers;
    matchers.append(first);
    matchers.append(second);
    matchers.append(third);
    matchers.append(fourth);
    return anyOf(matchers);
}

template <typename T>
QSharedPointer<Matcher<T> > anyOf(const QSharedPointer<Matcher<T> > &first,
                                  const QSharedPointer<Matcher<T> > &second,
                                  const QSharedPointer<Matcher<T> > &third,
                                  const QSharedPointer<Matcher<T> > &fourth,
                                  const QSharedPointer<Matcher<T> > &fifth)
{
    QList<QSharedPointer<Matcher<T> > > matchers;
    matchers.append(first);
    matchers.append(second);
    matchers.append(third);
    matchers.append(fourth);
    matchers.append(fifth);
    return anyOf(matchers);
}

template <typename T>
QSharedPointer<Matcher<T> > anyOf(const QSharedPointer<Matcher<T> > &first,
                                  const QSharedPointer<Matcher<T> > &second,
                                  const QSharedPointer<Matcher<T> > &third,
                                  const QSharedPointer<Matcher<T> > &fourth,
                                  const QSharedPointer<Matcher<T> > &fifth,
                                  const QSharedPointer<Matcher<T> > &sixth)
{
    QList<QSharedPointer<Matcher<T> > > matchers;
    matchers.append(first);
    matchers.append(second);
    matchers.append(third);
    matchers.append(fourth);
    matchers.append(fifth);
    matchers.append(sixth);
    return anyOf(matchers);
}

} // namespace HamcrestQt

#endif // HAMCRESTQT_ANYOF_H
