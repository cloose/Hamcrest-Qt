#ifndef HAMCRESTQT_ISANYTHING_H
#define HAMCRESTQT_ISANYTHING_H

#include <QSharedPointer>
#include <QString>

#include "basematcher.h"

namespace HamcrestQt {

/**
* A matcher that always returns <code>true</code>.
*/
template <typename T>
class IsAnything : public BaseMatcher<T>
{
public:
    explicit IsAnything(const QString &msg = "ANYTHING") : message(msg) {}

    virtual bool matches(const T &) const
    {
        return true;
    }

    virtual void describeTo(Description &description) const
    {
        description.appendText(message);
    }

private:
    QString message;
};


/**
 * Creates a matcher that always matches, regardless of the examined object.
 */
template <typename T>
QSharedPointer<Matcher<T> > anything()
{
    return QSharedPointer<Matcher<T> >(new IsAnything<T>());
}

/**
 * Creates a matcher that always matches, regardless of the examined object, but describes
 * itself with the specified @c QString.
 *
 * @param description
 * a meaningful @c QString used when describing itself
 */
template <typename T>
QSharedPointer<Matcher<T> > anything(const QString &description)
{
    return QSharedPointer<Matcher<T> >(new IsAnything<T>(description));
}

} // namespace HamcrestQt

#endif // HAMCRESTQT_ISANYTHING_H
