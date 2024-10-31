#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();

        unordered_map<char, int> mp;
        int start = 0;
        int maxSub = 0;

        for (int i = 0; i < s.size(); i++) {
            if (mp.count(s[i]) && mp[s[i]] >= start) {
                start = mp[s[i]] + 1;
            }
            mp[s[i]] = i;
            maxSub = max(maxSub, i - start + 1);
        }
        return maxSub;
    }
};

int main() {
    Solution solution;
    string s;
    
    cout << "Enter a string: ";
    cin >> s;

    int result = solution.lengthOfLongestSubstring(s);
    cout << "The length of the longest substring without repeating characters is: " << result << endl;

    return 0;
}
