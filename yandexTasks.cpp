#include "yandexTasks.h"

namespace yaTasks {

    void ReplaceSpacesInString(std::string& str) {
        //  add spaces counter, to count how much additional space we need
        //  %20 requires 3 bytes, space symbol requires one
        //  let's take " a c d b" for example
        size_t SpacesCount = 0;
        for (size_t i = 0; i < str.size(); ++i) {
            if (str[i] == ' ') {
                SpacesCount++;
            }
        }
        //  in our example " a c d b" SpacesCount = 4
        //  we need to save index of last element for symbol-replacement-loop
        size_t beginningIndex = str.size() - 1;
        //  in our example beginningIndex = 7
        //  we already have 1 byte for each space, for %20 we need additional two
        str.resize(str.size() + 2 * SpacesCount);
        //  in our example new size = 8 + 2 * 4 = 16
        //  in symbol-replacement-loop we start from last symbol
        //  in our example(dots are empty string elements "" symbol,
        //  STL string doesn't fill empty elements with spaces:
        //          \/
        //  " a c d b........"
        //  we move all non-space symbols to new correct positions
        //  if [i] is previous position, new position should be [i + 2 * SpacesCount]
        //  in our example:
        //  " a c d ........b" (previous index was i = 7, new index is i = 7 + 2 * 4 = 15
        //  when spaces symbol is reached, we replace elements at indexes i + 2 * SpacesCount for '0'
        //  at i + 2 * SpacesCount - 1 for '2', and at i + 2 * SpacesCount - 2 for '%'
        //  in our example
        //      \/
        //   a c d ........b // (previous index was i = 6, new index is i = 6 + 2 * 4 = 14, place '0' there
        //   a c d .....%20b // on i = 13 = '2', on i = 12 '%'
        //  after replacement we decrease SpacesCount by one
        //  fast-forward
        //  %20a%20b%20c%20d
        // here we use int, because after 0, we subtract 1
        // and get max size_t num and get out range
        for (int i = beginningIndex; i >= 0; --i) {
            if (str[i] != ' ') {
                std::swap(str[i], str[i + 2 * SpacesCount]);
            } else {
                str[i + 2 * SpacesCount] = '0';
                str[i + 2 * SpacesCount - 1] = '2';
                str[i + 2 * SpacesCount - 2] = '%';
                SpacesCount--;
            }
        }
    }

    std::list<int> mergeTwoSortedLists(const std::list<int>& firstList,
                                       const std::list<int>& secondList) {
        std::list<int> result;
        //  make iterators for both lists
        //  (can't use indexes because list is not random access container
        auto firstIt = firstList.begin();
        auto secondIt = secondList.begin();
        // if one of iterators reaches end we stop to avoid out of range exception
        while (firstIt != firstList.end() && secondIt != secondList.end()) {
            // if first iterator is smaller we push that element in result
            if (*firstIt < *secondIt) {
                result.push_back(*firstIt);
                firstIt++;
            } else if (*firstIt == *secondIt) {
                //  if elements equal add and increment both of them,
                // we don't need to get rid of duplicates in this task
                result.push_back(*firstIt);
                result.push_back(*secondIt);
                firstIt++;
                secondIt++;
            } else {
                result.push_back(*secondIt);
                secondIt++;
            }
        }
        //  when one of lists reaches end we need to add remaining elements
        //  which are already sorted and first element in remaining sequence
        //  is bigger or equal than last element in result, so we can safely
        //  add remaining elements
        while (firstIt != firstList.end()) {
            result.push_back(*firstIt);
            firstIt++;
        }
        // we don't need to check what iterator reached end because
        // while already does that, that's why we repeat two loops
        while (secondIt != secondList.end()) {
            result.push_back(*secondIt);
            secondIt++;
        }
        return result;
    }
}