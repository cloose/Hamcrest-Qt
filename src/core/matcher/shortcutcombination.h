#ifndef HAMCRESTQT_SHORTCUTCOMBINATION_H
#define HAMCRESTQT_SHORTCUTCOMBINATION_H

#include <QList>
#include <QSharedPointer>

#include "basematcher.h"

namespace HamcrestQt {

template <typename T>
class ShortcutCombination : public BaseMatcher<T>
{
public:
    explicit ShortcutCombination(const QList<QSharedPointer<Matcher<T> > > &m) : matchers(m) {}

    void describeTo(Description &description, const QString &op) const
    {
        description.appendList(QStringLiteral("("), QString(" %1 ").arg(op), QStringLiteral(")"),
                               matchers.begin(), matchers.end());
    }

protected:
    virtual bool matches(const T &item, bool shortcut) const
    {
        foreach (const QSharedPointer<Matcher<T> > &matcher, matchers) {
            if (matcher->matches(item) == shortcut) {
                return shortcut;
            }
        }

        return !shortcut;
    }

private:
    QList<QSharedPointer<Matcher<T> > > matchers;
};

} // namespace HamcrestQt

#endif // HAMCRESTQT_SHORTCUTCOMBINATION_H
