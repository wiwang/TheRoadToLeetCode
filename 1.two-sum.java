import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

/*
 * @lc app=leetcode id=1 lang=java
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (44.65%)
 * Likes:    12185
 * Dislikes: 427
 * Total Accepted:    2.2M
 * Total Submissions: 5M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 */

// @lc code=start
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> m = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int rest = target - nums[i];
            if (m.containsKey(rest)) {
                return new int[]{i, m.get(rest)};
            } 
            
            m.put(nums[i], i);
        }

        return new int[]{};
    }
}
// @lc code=end

