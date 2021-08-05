//
// Created by ilya on 05.08.2021.
//

#ifndef ALGORITHM_AND_DATA_STRUCTURES_YANDEXTASKS_H
#define ALGORITHM_AND_DATA_STRUCTURES_YANDEXTASKS_H
#pragma once
#include <string>
#include <list>

namespace yaTasks {

    //TASK: replace all spaces in strings by %20 symbols in place (without using copies)
    void ReplaceSpacesInString(std::string& str);

    //TASK: mergeTwoSortedLists in new sorted list
    std::list<int> mergeTwoSortedLists(const std::list<int>& firstList,
                                       const std::list<int>& secondList);

}
#endif //ALGORITHM_AND_DATA_STRUCTURES_YANDEXTASKS_H
