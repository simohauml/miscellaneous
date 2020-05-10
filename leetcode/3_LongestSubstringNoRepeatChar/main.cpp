#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using std::string;
using std::unordered_map;
using std::make_pair;
using std::max;
using std::cout;
using std::endl;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) {
            return 0;
        }
        int maxCount {1};
        int i {0};
        int tail {0};
        do {
            if(i == tail) {
                tail++;
                maxCount = max(1, maxCount);
            } else {
                string::size_type p = s.substr(i, tail - i).find(s[tail]);
                if(string::npos != p) {
                    i = i + static_cast<int>(p) + 1;
                    tail++;
                } else {
                    maxCount = max(tail - i + 1, maxCount);
                    tail++;
                }
            }
        } while ((i < s.length() - maxCount) && (tail < s.length()));
        return maxCount;
    }
};

int main() {
//    Solution sol;
//    cout << sol.lengthOfLongestSubstring("bcadefabc") << endl;

//    string a {"abcabca"};
//    cout << a.substr(1, 3).find('b') << endl;
    unordered_map<char, int> mymap;
    mymap.insert(make_pair<char, int>('a', 0));
    mymap.insert(make_pair<char, int>('b', 1));
    mymap.insert(make_pair<char, int>('c', 2));

    unordered_map<char, int>::const_iterator got = mymap.find('b');
    cout << got->first << got->second << endl;
    return 0;
}