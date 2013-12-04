Hamcrest-Qt
===========

Hamcrest matchers for C++/Qt


# EXPERIMENTAL
This code is pre-alpha quality. DO NOT USE IN PRODUCTION CODE.


## Supported Matchers

#### allOf

Creates a matcher that matches if the examined object matches **ALL** of the specified matchers.

    ASSERT_THAT(QStringLiteral("myValue"), allOf(startsWith("my"), containsString("Val")));

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
