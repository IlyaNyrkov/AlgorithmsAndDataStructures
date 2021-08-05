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

//  biggestBinSubSequence-----------------------------------------------

TEST(biggestBinSubSequence, EmptySequence) {
    std::vector<int> binVector;
    ASSERT_EQ(yaTasks::biggestBinSubSequence(binVector), 0);
}

TEST(biggestBinSubSequence, AllOnes) {
    std::vector<int> binVector = {1, 1, 1, 1, 1, 1};
    ASSERT_EQ(yaTasks::biggestBinSubSequence(binVector), 6);
}

TEST(biggestBinSubSequence, AllZeroes) {
    std::vector<int> binVector = {0, 0, 0, 0};
    ASSERT_EQ(yaTasks::biggestBinSubSequence(binVector), 0);
}

TEST(biggestBinSubSequence, AllZeroesLastOne) {
    std::vector<int> binVector = {0, 0, 0, 1};
    ASSERT_EQ(yaTasks::biggestBinSubSequence(binVector), 1);
}

TEST(biggestBinSubSequence, OnesAfterZeroes) {
    std::vector<int> binVector = {0, 0, 0, 1, 1, 1, 1};
    ASSERT_EQ(yaTasks::biggestBinSubSequence(binVector), 4);
}

TEST(biggestBinSubSequence, SeveralSequences) {
    std::vector<int> binVector = {0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0};
    ASSERT_EQ(yaTasks::biggestBinSubSequence(binVector), 4);
}

//------------------------binarySearch----------------------------------
TEST(binarySearch, EmptySequence) {
    std::vector<int> arr = {};
    ASSERT_EQ(yaTasks::binarySearch(arr, 10), -1);
}

TEST(binarySearch, CorrectSequence) {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6};
    ASSERT_EQ(yaTasks::binarySearch(arr, 6), 5);
}

TEST(binarySearch, AllSameNumbers) {
    std::vector<int> arr = {1, 1, 1, 1, 1};
    ASSERT_EQ(yaTasks::binarySearch(arr, 1), 0);
}

TEST(binarySearch, TargetMissing) {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6};
    ASSERT_EQ(yaTasks::binarySearch(arr, 10), -1);
}

TEST(binarySearch, NegativeNumbers) {
    std::vector<int> arr = {-6, -5, -4, -3, -2};
    ASSERT_EQ(yaTasks::binarySearch(arr, -3), 3);
}

//----------------------------isAnagram---------------------

TEST(isAnagram, EmptyStrings) {
    std::string first = "";
    std::string second = "";
    ASSERT_TRUE(yaTasks::isAnagram(first, second));
}

TEST(isAnagram, OneEmptyString) {
    std::string first = "";
    std::string second = "Smth";
    ASSERT_FALSE(yaTasks::isAnagram(first, second));
}

TEST(isAnagram, Example) {
    std::string first = "capital";
    std::string second = "laticap";
    ASSERT_TRUE(yaTasks::isAnagram(first, second));
}

TEST(isAnagram, SameSymbols) {
    std::string first = "aaaaaa";
    std::string second = "aaa";
    ASSERT_FALSE(yaTasks::isAnagram(first, second));
}

TEST(isAnagram, DifferentSizes) {
    std::string first = "aba";
    std::string second = "abaaba";
    ASSERT_FALSE(yaTasks::isAnagram(first, second));
}

