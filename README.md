Hamcrest-Qt
===========

[Hamcrest](http://hamcrest.org/) matchers for C++/Qt

This is an attempt to port the [Java Hamcrest](https://github.com/hamcrest/JavaHamcrest) library to C++/Qt and make it usable with [Qt Test](http://qt-project.org/doc/qt-5.1/qttestlib/qttest-index.html).

Like the original library, this code is licensed under [BSD 3-Clause License](http://opensource.org/licenses/BSD-3-Clause).

# EXPERIMENTAL
This code is pre-alpha quality. DO NOT USE IN PRODUCTION CODE.

## Links

[Homepage](http://cloose.github.io/Hamcrest-Qt)  
[API Documentation](http://cloose.github.io/Hamcrest-Qt/docs/html/index.html)

## Supported Matchers

#### allOf

Creates a matcher that matches if the examined object matches **ALL** of the specified matchers.

    ASSERT_THAT(QStringLiteral("myValue"), allOf(startsWith("my"), containsString("Val")));

#### anyOf

Creates a matcher that matches if the examined object matches **ANY** of the specified matchers.

    ASSERT_THAT(QStringLiteral("myValue"), anyOf(startsWith("foo"), containsString("Val")));

#### containsString

Creates a matcher that matches if the examined QString contains the specified
QString anywhere.

    ASSERT_THAT(QStringLiteral("myStringOfNote"), containsString("ring"));

#### endsWith

Creates a matcher that matches if the examined QString ends with the specified
QString.

    ASSERT_THAT(QStringLiteral("myStringOfNote"), endsWith("Note"));

#### equalTo

Creates a matcher that matches when the examined object is logically equal to the specified `operand`, as determined by calling the operator==() method on the **examined** object.

    ASSERT_THAT(QStringLiteral("foo"), equalTo("foo"));

#### is

Decorates another Matcher, retaining its behaviour, but allowing tests to be slightly more expressive.

    ASSERT_THAT(cheese, is(equalTo(smelly)));

#### _not

Creates a matcher that wraps an existing matcher, but inverts the logic by which it will match.

    ASSERT_THAT(cheese, is(_not(equalTo(smelly))));

#### startsWith


Creates a matcher that matches if the examined QString starts with the specified
QString.

    ASSERT_THAT(QStringLiteral("myStringOfNote"), startsWith("my"));
