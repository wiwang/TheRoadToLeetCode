
/*
 * @lc app=leetcode id=108 lang=java
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (53.15%)
 * Likes:    1703
 * Dislikes: 168
 * Total Accepted:    332.6K
 * Total Submissions: 611.4K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        if (nums.length == 0) {
            return null;
        }

        return recursiveBST(nums, 0, nums.length-1);
    }

    private TreeNode recursiveBST(int[] nums, int m, int n) {
        if (m == n) {
            return new TreeNode(nums[m]);
        }

        int mid = (m+n+1)/2;

        TreeNode node = new TreeNode(nums[mid]);
        if (mid > m) {
            node.left = recursiveBST(nums, m, mid-1);
        }

        if (mid < n) {
            node.right = recursiveBST(nums, mid+1, n);
        }

        return node;
    }
}
// @lc code=end

