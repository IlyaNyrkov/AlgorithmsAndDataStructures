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

    int biggestBinSubSequence(const std::vector<int>& binVector) {
        //check if vector is empty
        if (binVector.size() == 0) {
            return 0;
        }
        int BiggestSubCount = 0;
        int CurrentCounter = 0;
        //  for example, we have binVector : 100110111011
        //  we iterate through it and find '1' at index
        //  increment CurrentCounter
        //  when we reach '0' we check if CurrentCounter is bigger
        //  than BiggestSubCount, assign new value if bigger
        //  to CurrentCounter assign zero
        for (size_t i = 0; i < binVector.size(); ++i) {
            if (binVector[i] == 1) {
                CurrentCounter++;
            } else {
                if (CurrentCounter > BiggestSubCount) {
                    BiggestSubCount = CurrentCounter;
                }
                CurrentCounter = 0;
            }
        }
        //  after for-loop we can have situation where last element
        //  of bin vector is 1, but we check if CurrentCounter is bigger
        //  only when element is 0, so we check CurrentCounter again
        if (CurrentCounter > BiggestSubCount) {
            BiggestSubCount = CurrentCounter;
        }
        return BiggestSubCount;
    }

    int binarySearch(const std::vector<int>& arr, const int& target) {
        if (arr.size() == 0) {
            return -1;
        }
        int l = 0;
        int r = arr.size();
        int mid = l + (r - l) / 2; // we could use (l + r) / 2,
        // but there could be type overflow
        while (l + 1 < r) {
            if (arr[mid] > target) {
                r = mid;
            } else {
                //  special case if all elements are same
                //  we need to get index of first element equal to target
                if (target == arr[l]) {
                    return l;
                }
                l = mid;
            }
            mid = l + (r - l) / 2;
        }
        if (target == arr[l]) {
            return l;
        } else {
            return -1;
        }

    }

    bool isAnagram(const std::string& firstStr, const std::string& secondStr) {
        //  if strings are different sizes, they cannot be anagrams already
        if (firstStr.size() != secondStr.size()) {
            return false;
        }
        //  there are two main ways to solve this problem:
        //  1st - sort both strings and compare them, complexity
        //  will be O(N log(N)), where N is size of string, in average case
        //  but at worst case quick sort complexity can be O(N*N), so the same
        //  for our solution, besides that we modify original strings, we could
        //  copy them, but then, this solution looses it's memory efficiency
        //  2nd - create 2 dictionaries for both strings and compare them
        //  adding element to dictionary has O(log(N)) time complexity (and that's for last element)
        //  so roughly we have O(Nlog(N)) time complexity, then we compare both dictionaries with
        //  O(N) time complexity, so overall time complexity is O(Nlog(N)), and memory is O(N)

        //  let's make utility function to build a dictionary
        //  (for python boys out there you can do it in one line of code
        auto strToDict = [](const std::string& str) {
            std::map<char, int> result;
            for (size_t i = 0; i < str.size(); ++i) {
                result[str[i]]++;
            }
            return result;
        };
        //  Just Compare those dictionaries (maps)
        return strToDict(firstStr) == strToDict(secondStr);
    }
}