//Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
//
//For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].

#include <iostream>
#include <vector>

using namespace std;

class Solution_280 {
public:
    // Exp: https://discuss.leetcode.com/topic/23877/4-lines-o-n-c
    // Time:	O(n)
    // Space:	O(1)
    void wiggleSort(vector<int> &nums) {
        int sign = 1;
        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] - nums[i-1]) * sign < 0)
                swap(nums[i], nums[i-1]);
            sign = -sign;
        }
    }
};