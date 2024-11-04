#include <iostream>
#include <vector>
#include <algorithm>

class LongestIncreasingSubsequence {
public:
    // Function to calculate the length of the longest increasing subsequence
    int lengthOfLIS(const std::vector<int>& nums) {
        if (nums.empty()) return 0;

        int n = nums.size();
        std::vector<int> dp(n, 1); // dp[i] holds the length of the LIS ending at index i
        int maxLength = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            maxLength = std::max(maxLength, dp[i]);
        }
        return maxLength;
    }

    // Function to retrieve the longest increasing subsequence
    std::vector<int> getLIS(const std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        std::vector<int> dp(n, 1), prev(n, -1); // 'prev' stores the indices for backtracking
        int maxLength = 1, bestEnd = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > maxLength) {
                maxLength = dp[i];
                bestEnd = i;
            }
        }

        // Reconstruct the LIS by backtracking through 'prev'
        std::vector<int> lis;
        for (int i = bestEnd; i >= 0; i = prev[i]) {
            lis.push_back(nums[i]);
            if (prev[i] == -1) break;
        }
        std::reverse(lis.begin(), lis.end());
        return lis;
    }
};

int main() {
    std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    LongestIncreasingSubsequence lisSolver;

    int length = lisSolver.lengthOfLIS(nums);
    std::vector<int> lis = lisSolver.getLIS(nums);

    std::cout << "Length of LIS: " << length << std::endl;
    std::cout << "Longest Increasing Subsequence: ";
    for (int num : lis) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
