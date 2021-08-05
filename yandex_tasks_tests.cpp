#include "gtest/gtest.h"
#include "yandexTasks.h"

TEST(ReplaceSpacesInString, FromSolutionExplanation) {
    std::string str = " a b c d";
    yaTasks::ReplaceSpacesInString(str);
    ASSERT_EQ(str, "%20a%20b%20c%20d");
}

TEST(ReplaceSpacesInStrings, AllSpaces) {
    std::string str = "     "; //5 spaces
    yaTasks::ReplaceSpacesInString(str);
    ASSERT_EQ(str, "%20%20%20%20%20");
}

TEST(ReplaceSpacesInStrings, SpaceAfterEachSymbol) {
    std::string str = "a b c d e";
    yaTasks::ReplaceSpacesInString(str);
    ASSERT_EQ(str, "a%20b%20c%20d%20e");
}

TEST(ReplaceSpacesInStrings, EmptyString) {
    std::string str = "";
    yaTasks::ReplaceSpacesInString(str);
    ASSERT_EQ(str, "");
}

TEST(ReplaceSpacesInStrings, SpacesAtBegging) {
    std::string str = "    c d e"; //4 spaces at begging
    yaTasks::ReplaceSpacesInString(str);
    ASSERT_EQ(str, "%20%20%20%20c%20d%20e");
}
