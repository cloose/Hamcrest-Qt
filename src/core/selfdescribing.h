#ifndef HAMCRESTQT_SELFDESCRIBING_H
#define HAMCRESTQT_SELFDESCRIBING_H

namespace HamcrestQt {

class Description;

/**
 * The ability of an object to describe itself.
 */
class SelfDescribing
{
public:
    virtual ~SelfDescribing() {}

    /**
     * Generates a description of the object. The description may be part of a
     * description of a larger object of which this is just a component, so it
     * should be worded appropriately.
     *
     * @param description
     * The description to be built or appended to.
     */
    virtual void describeTo(Description &description) const = 0;
};

} // namespace HamcrestQt

#endif // HAMCRESTQT_SELFDESCRIBING_H
