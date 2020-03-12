import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

import jdk.jshell.execution.Util;

/*
 * @lc app=leetcode id=15 lang=java
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.99%)
 * Likes:    4853
 * Dislikes: 578
 * Total Accepted:    696.1K
 * Total Submissions: 2.8M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */
/**
 * The idea is to sort an input array and then run through all indices of a possible first element of a triplet. 
 * For each possible first element we make a standard bi-directional 2Sum sweep of the remaining part of the array. 
 * Also we want to skip equal elements to avoid duplicates in the answer without making a set or smth like that.
 */

 /**
  * the key to solve this problem is how we can cover all cases in a lowest-cost way, that`s why
  * we need sort this array first. take time to absorb it
  */


// @lc code=start

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList(); 
        for (int i = 0; i < nums.length-2; i++) {
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                int lo = i+1, hi = nums.length-1, sum = 0 - nums[i];
                while (lo < hi) {
                    if (nums[lo] + nums[hi] == sum) {
                        res.add(Arrays.asList(nums[i], nums[lo], nums[hi]));
                        while (lo < hi && nums[lo] == nums[lo+1]) lo++;
                        while (lo < hi && nums[hi] == nums[hi-1]) hi--;
                        lo++; hi--;
                    } else if (nums[lo] + nums[hi] < sum) lo++;
                    else hi--;
               }
            }
        }
        return res;
    }
}
// @lc code=end

