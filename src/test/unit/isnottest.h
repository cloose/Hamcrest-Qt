#ifndef ISNOTTEST_H
#define ISNOTTEST_H

#include <QObject>

class IsNotTest : public QObject
{
    Q_OBJECT

private slots:
    void evaluatesToTheTheLogicalNegationOfAnotherMatcher();
    void providesConvenientShortcutForNotEqualTo();
    void usesDescriptionOfNegatedMatcherWithPrefix();
};

#endif // ISNOTTEST_H
