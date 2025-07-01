#include <map>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        int start = 0;
        int size = s.size();
        map<char, int> table;

        for (int end=0;end<size;end++) {
            // this is the devil. count() method is used to check whether a key with proper char exist in c++ map. 
            // space will not be considered as a character and will not exist in table.
            if (table.count(s[end]) && table[s[end]] >= start) {
                start = table[s[end]] + 1;
            }
            result = max(result, end - start + 1);
            table[s[end]] = end;
        }

        return result;
    }
};