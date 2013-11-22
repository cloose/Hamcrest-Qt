#ifndef HAMCREST_AREEQUAL_P_H
#define HAMCREST_AREEQUAL_P_H

namespace Hamcrest {

template <typename T>
inline bool AreEqual(const T &actual, const T &expected)
{
    return actual == expected;
}

inline bool AreEqual(const char *actual, const char *expected)
{
    return ::strcmp(actual, expected) == 0;
}

} // namespace Hamcrest

#endif // HAMCREST_AREEQUAL_P_H
