#include "description.h"

namespace HamcrestQt {

class Description::NullDescription : public Description
{
    virtual Description &appendText(const QString &) { return *this; }
    virtual Description &appendDescriptionOf(const SelfDescribing &) { return *this; }
    virtual QString toString() const { return QStringLiteral(""); }
    virtual void appendString(const QString &) {}
    virtual void append(const QChar &) {}

};

Description &Description::appendValue(short value)
{
    appendString("<");
    appendString(QString().setNum(value));
    appendString("s>");

    return *this;
}

Description &Description::appendValue(long value)
{
    appendString("<");
    appendString(QString().setNum(value));
    appendString("L>");

    return *this;
}

Description &Description::appendValue(float value)
{
    appendString("<");
    appendString(QString().setNum(value));
    appendString("F>");

    return *this;
}

Description &Description::appendValue(double value)
{
    appendString("<");
    appendString(QString().setNum(value));
    appendString("D>");

    return *this;
}

Description &Description::appendValue(const char *value)
{
    appendValue(QString(value));
    return *this;
}

Description &Description::appendValue(const QString &value)
{
    toCppSyntaxString(value);
    return *this;
}

Description &Description::appendValue(char value)
{
    appendValue(QChar(value));
    return *this;
}

Description &Description::appendValue(const QChar &value)
{
    append('"');
    toCppSyntax(value);
    append('"');
    return *this;
}

Description &Description::NONE()
{
    static NullDescription nullDescription;
    return nullDescription;
}

void Description::toCppSyntaxString(const QString &unformatted)
{
    append('"');
    foreach (QChar c, unformatted) {
        toCppSyntax(c);
    }
    append('"');
}

void Description::toCppSyntax(const QChar &ch)
{
    if (ch == '"')
        appendString("\\\"");
    else if (ch == '\n')
        appendString("\\n");
    else  if (ch == '\r')
        appendString("\\r");
    else if (ch == '\t')
        appendString("\\t");
    else
        append(ch);
}

} // namespace HamcrestQt
