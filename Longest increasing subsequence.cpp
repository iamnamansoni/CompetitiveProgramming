#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;

    int n = nums.size();
    vector<int> dp(n, 1); // dp[i] will hold the length of LIS ending at index i

    // Build the dp array
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // Find the maximum value in dp array
    int maxLength = 0;
    for (int length : dp) {
        maxLength = max(maxLength, length);
    }

    return maxLength; // The length of the longest increasing subsequence
}

int main() {
    int n; // Number of elements in the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n); // Vector to store the array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i]; // Read each element
    }

    int length = lengthOfLIS(arr); // Calculate the length of the longest increasing subsequence
    cout << "Length of Longest Increasing Subsequence: " << length << endl;

    return 0;
}
