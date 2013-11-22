#ifndef HAMCREST_TOSTRING_P_H
#define HAMCREST_TOSTRING_P_H

#include <string>
#include <sstream>
#include <QString>
#include <QStringList>

template <typename T>
QString ToString(const T &value)
{
    std::stringstream stream;
    stream << value;

    return QString::fromStdString(stream.str());
}

inline QString ToString(bool value)
{
    return value ? "true" : "false";
}

inline QString ToString(const QStringList &list)
{
    return list.join(",");
}

#endif // HAMCREST_TOSTRING_P_H
