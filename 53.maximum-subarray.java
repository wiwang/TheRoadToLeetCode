/*
 * @lc app=leetcode id=53 lang=java
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (44.83%)
 * Likes:    5547
 * Dislikes: 235
 * Total Accepted:    693.1K
 * Total Submissions: 1.5M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */

 /**
  * the first step is to divide the problem set into a complete subset which can fully cover the original problem,
  also the original problem can be solved by sub-problems
  here the sub-problem is  a range which ends in position i.
  the equation for this optimal problem: maxEnd(i) = (maxEnd(i-1)>0? maxEnd(i-1):0)+nums[i]
  */

// @lc code=start
class Solution {
    public int maxSubArray(int[] nums) {
        int length = nums.length;
        int maxSum = nums[0];
        int[] maxEnd = new int[length];
        maxEnd[0] = nums[0];

        for (int i = 1; i < length; i++) {
            maxEnd[i] = (maxEnd[i-1]>0? maxEnd[i-1]:0)+nums[i];
            maxSum = Integer.max(maxSum, maxEnd[i]);
        }

        return maxSum;
    }
}
// @lc code=end

