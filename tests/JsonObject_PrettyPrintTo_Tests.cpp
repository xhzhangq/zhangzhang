/*
* Arduino JSON library
* Benoit Blanchon 2014 - MIT License
*/

#include <gtest/gtest.h>
#include <JsonObject.h>
#include <JsonValue.h>
#include <StaticJsonBuffer.h>

class JsonObject_PrettyPrintTo_Tests : public testing::Test
{
protected:
    JsonObject object;
    StaticJsonBuffer<30> json;

    virtual void SetUp()
    {
        object = json.createObject();
    }

    void outputMustBe(const char* expected)
    {
        size_t n = object.prettyPrintTo(buffer, sizeof(buffer));
        EXPECT_STREQ(expected, buffer);
        EXPECT_EQ(strlen(expected), n);
    }

private:
    char buffer[256];
};

TEST_F(JsonObject_PrettyPrintTo_Tests, EmptyObject)
{
    outputMustBe("{}");
}

TEST_F(JsonObject_PrettyPrintTo_Tests, OneMember)
{
    object["key"] = "value";

    outputMustBe(
        "{\r\n"
        "  \"key\": \"value\"\r\n"
        "}");
}

TEST_F(JsonObject_PrettyPrintTo_Tests, TwoMembers)
{
    object["key1"] = "value1";
    object["key2"] = "value2";

    outputMustBe(
        "{\r\n"
        "  \"key1\": \"value1\",\r\n"
        "  \"key2\": \"value2\"\r\n"
        "}");
}

TEST_F(JsonObject_PrettyPrintTo_Tests, EmptyNestedObjects)
{
    object.createNestedObject("key1");
    object.createNestedObject("key2");

    outputMustBe(
        "{\r\n"
        "  \"key1\": {},\r\n"
        "  \"key2\": {}\r\n"
        "}");
}

TEST_F(JsonObject_PrettyPrintTo_Tests, NestedObjects)
{
    JsonObject nested1 = object.createNestedObject("key1");
    nested1["a"] = 1;

    JsonObject nested2 = object.createNestedObject("key2");
    nested2["b"] = 2;

    outputMustBe(
        "{\r\n"
        "  \"key1\": {\r\n"
        "    \"a\": 1\r\n"
        "  },\r\n"
        "  \"key2\": {\r\n"
        "    \"b\": 2\r\n"
        "  }\r\n"
        "}");
}