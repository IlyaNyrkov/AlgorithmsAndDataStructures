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

//----------MergeTwoSortedLists------------------------

TEST(MergeTwoSortedLists, OneListNumsBiggerThanOthers) {
    std::list<int> first = {1, 2, 3};
    std::list<int> second = {4, 5, 6};
    std::list<int> result = {1, 2, 3, 4, 5, 6};
    ASSERT_EQ(yaTasks::mergeTwoSortedLists(first, second), result);
}

TEST(MergeTwoSortedLists, ListIntervalsIntercept) {
    std::list<int> first = {1, 3, 10};
    std::list<int> second = {2, 5, 6};
    std::list<int> result = {1, 2, 3, 5, 6, 10};
    ASSERT_EQ(yaTasks::mergeTwoSortedLists(first, second), result);
}

TEST(MergeTwoSortedLists, ListIntervalsHaveSameNumbers) {
    std::list<int> first = {1, 3, 10};
    std::list<int> second = {2, 3, 5, 6, 10};
    std::list<int> result = {1, 2, 3, 3, 5, 6, 10, 10};
    ASSERT_EQ(yaTasks::mergeTwoSortedLists(first, second), result);
}

TEST(MergeTwoSortedLists, OneListEmpty) {
    std::list<int> first = {};
    std::list<int> second = {2, 3, 5, 6, 10};
    std::list<int> result = {2, 3, 5, 6, 10};
    ASSERT_EQ(yaTasks::mergeTwoSortedLists(first, second), result);
}

