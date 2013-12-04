#ifndef HAMCRESTQT_SUBSTRINGMATCHER_H
#define HAMCRESTQT_SUBSTRINGMATCHER_H

#include <QString>
#include "basematcher.h"

namespace HamcrestQt {

class SubstringMatcher : public BaseMatcher<QString>
{
public:
    virtual bool matches(const QString &item) const
    {
        return evalSubstringOf(item);
    }

    virtual void describeTo(Description &description) const
    {
        description.appendText("a string ")
                   .appendText(relationship())
                   .appendText(" ")
                   .appendValue(substring);
    }

    virtual void describeMismatch(const QString &item, Description &description) const
    {
        description.appendText("was \"").appendText(item).appendText("\"");
    }

protected:
    explicit SubstringMatcher(const QString &str) : substring(str) {}

    virtual bool evalSubstringOf(const QString &str) const = 0;
    virtual QString relationship() const = 0;

protected:
    QString substring;
};

} // namespace HamcrestQt

#endif // HAMCRESTQT_SUBSTRINGMATCHER_H
