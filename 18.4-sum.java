import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

import javax.lang.model.util.ElementScanner6;

/*
 * @lc app=leetcode id=18 lang=java
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (31.69%)
 * Likes:    1360
 * Dislikes: 268
 * Total Accepted:    275.7K
 * Total Submissions: 864.7K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

 /**If you have already read and implement the 3sum and 4sum by using the sorting approach: reduce them into 2sum at the end, you might already got the feeling that, all ksum problem can be divided into two problems:

2sum Problem
Reduce K sum problem to K – 1 sum Problem
Therefore, the ideas is simple and straightforward. We could use recursive to solve this problem. Time complexity is O(N^(K-1)).

    public class Solution {
        int len = 0;
        public List<List<Integer>> fourSum(int[] nums, int target) {
            len = nums.length;
            Arrays.sort(nums);
            return kSum(nums, target, 4, 0);
        }
       private ArrayList<List<Integer>> kSum(int[] nums, int target, int k, int index) {
            ArrayList<List<Integer>> res = new ArrayList<List<Integer>>();
            if(index >= len) {
                return res;
            }
            if(k == 2) {
            	int i = index, j = len - 1;
            	while(i < j) {
                    //find a pair
            	    if(target - nums[i] == nums[j]) {
            	    	List<Integer> temp = new ArrayList<>();
                    	temp.add(nums[i]);
                    	temp.add(target-nums[i]);
                        res.add(temp);
                        //skip duplication
                        while(i<j && nums[i]==nums[i+1]) i++;
                        while(i<j && nums[j-1]==nums[j]) j--;
                        i++;
                        j--;
                    //move left bound
            	    } else if (target - nums[i] > nums[j]) {
            	        i++;
                    //move right bound
            	    } else {
            	        j--;
            	    }
            	}
            } else{
                for (int i = index; i < len - k + 1; i++) {
                    //use current number to reduce ksum into k-1sum
                    ArrayList<List<Integer>> temp = kSum(nums, target - nums[i], k-1, i+1);
                    if(temp != null){
                        //add previous results
                        for (List<Integer> t : temp) {
                            t.add(0, nums[i]);
                        }
                        res.addAll(temp);
                    }
                    while (i < len-1 && nums[i] == nums[i+1]) {
                        //skip duplicated numbers
                        i++;
                    }
                }
            }
            return res;
        }
    } */



// @lc code=start
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);

        return findNSum(nums, target, 4, 0);
    }

    private ArrayList<List<Integer>> findNSum(int[] nums, int target, int k, int begin) {
        ArrayList<List<Integer>> res = new ArrayList<>();
        
        if (begin+k > nums.length) {
            return res;
        }

        //early return if impossbile to get target
        if (k*nums[begin]>target || k*nums[nums.length-1]<target) {
            return res;
        }

        if (k == 2) {
            int low = begin;
            int high = nums.length-1;
            int sum;
            while (low < high) {
                sum = nums[low]+nums[high];
                if (sum == target) {
                    List<Integer> tmp = new ArrayList<>();
                    tmp.add(nums[low]);
                    tmp.add(nums[high]);
                    res.add(tmp);
                    while(low<high && nums[low]==nums[low+1]) low++;
                    while(low<high && nums[high-1]==nums[high]) high--;
                    low++;
                    high--;
                } 
                else if (sum < target){
                    low++;
                }
                else {
                    high--;
                }
            }
        } else {
            for (int i = begin; i < nums.length-k+1; i++) {
                if (i==begin || nums[i] != nums[i-1]) {
                    ArrayList<List<Integer>> tmp = findNSum(nums, target-nums[i], k-1, i+1);
                    for (List<Integer> list : tmp) {
                        list.add(0, nums[i]);
                    }
                    res.addAll(tmp);
                }
            }
        }

        return res;
    }
}
// @lc code=end

