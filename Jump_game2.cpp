//Problem- https://leetcode.com/problems/jump-game-ii/description/
#include <iostream>
#include <vector>
using namespace std;

int minJumps(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 0;

    int jumps = 0;
    int currentEnd = 0;
    int farthest = 0;

    for (int i = 0; i < n - 1; ++i) {
        // Update the farthest point that can be reached
        farthest = max(farthest, i + nums[i]);
        
        // If we have reached the end of the current range
        if (i == currentEnd) {
            jumps++; // Increment the jump count
            currentEnd = farthest; // Update the current end to the farthest point
            
            // If the current end has reached or exceeded the last index, break the loop
            if (currentEnd >= n - 1) break;
        }
    }

    return jumps;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << "Minimum number of jumps to reach the last index: " << minJumps(nums) << endl;
    return 0;
}
