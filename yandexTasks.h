//
// Created by ilya on 05.08.2021.
//

#ifndef ALGORITHM_AND_DATA_STRUCTURES_YANDEXTASKS_H
#define ALGORITHM_AND_DATA_STRUCTURES_YANDEXTASKS_H
#pragma once
#include <string>
#include <list>
#include <vector>
#include <map>
namespace yaTasks {

    //  TASK: replace all spaces in strings by %20 symbols in place (without using copies)
    //  example: "a b c " -> "a%20b%20c%20"
    void ReplaceSpacesInString(std::string& str);

    //  TASK: mergeTwoSortedLists in new sorted list
    //  example: {1, 2, 3}, {4, 5, 6} -> {1, 2, 3, 4, 5, 6}
    std::list<int> mergeTwoSortedLists(const std::list<int>& firstList,
                                       const std::list<int>& secondList);

    //  TASK: in given binary vector find elements count in the biggest subsequence of '1's
    //  example: {1, 1, 1, 0, 0, 0, 1, 1, 1, 1} -> 4
    int biggestBinSubSequence(const std::vector<int>& binVector);

    //  TASK: implement binary search
    //  example: {1, 2, 3, 4, 5}, 5 -> 4
    int binarySearch(const std::vector<int>& arr, const int& target);

    //  TASK: check if first string is anagram of others
    // example: "capital", "laticap" -> true
    bool isAnagram(const std::string& firstStr, const std::string& secondStr);

}
#endif //ALGORITHM_AND_DATA_STRUCTURES_YANDEXTASKS_H
