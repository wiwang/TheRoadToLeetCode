import java.util.Arrays;

/*
 * @lc app=leetcode id=16 lang=java
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.72%)
 * Likes:    1460
 * Dislikes: 107
 * Total Accepted:    398.6K
 * Total Submissions: 872.2K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */

// @lc code=start
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int res = nums[0]+nums[1]+nums[nums.length-1];

        for (int i = 0; i < nums.length-2; i++) {
            int low = i+1;
            int high = nums.length-1;
            while (low < high) {
                int sum = nums[i]+nums[low]+nums[high];
                //early return for this optimal case
                if (sum == target) {
                    return sum;
                }

                if (Math.abs(sum-target) < Math.abs(res-target)) {
                    res = sum;
                }                

                if (sum > target) {
                    high--;
                } else {
                    low++;
                }
            }
        }

        return res;
    }
}
// @lc code=end

