#include <bits/stdc++.h>
using namespace std;

bool palindromeString(string s) {
    vector<int> freq(26, 0);

    // Count character frequencies
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Check how many characters have odd frequencies
    int oddCount = 0;
    for (int count : freq) {
        if (count % 2 != 0) {
            oddCount++;
        }
        if (oddCount > 1) {
            return false; // Cannot form a palindrome
        }
    }

    return true; // Can form a palindrome
}

int main() {
    string s = "civic";
    cout << (palindromeString(s) ? "true" : "false") << endl;

    s = "ivicc";
    cout << (palindromeString(s) ? "true" : "false") << endl;

    s = "hello";
    cout << (palindromeString(s) ? "true" : "false") << endl;

    return 0;
}
