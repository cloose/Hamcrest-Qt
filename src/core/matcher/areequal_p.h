#ifndef HAMCRESTQT_AREEQUAL_P_H
#define HAMCRESTQT_AREEQUAL_P_H

namespace HamcrestQt {

template <typename T>
inline bool AreEqual(const T &actual, const T &expected)
{
    return actual == expected;
}

inline bool AreEqual(const char *actual, const char *expected)
{
    return ::strcmp(actual, expected) == 0;
}

} // namespace HamcrestQt

#endif // HAMCRESTQT_AREEQUAL_P_H
