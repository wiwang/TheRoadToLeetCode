/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (26.47%)
 * Likes:    2523
 * Dislikes: 369
 * Total Accepted:    496.7K
 * Total Submissions: 1.9M
 * Testcase Example:  '[2,1,3]'
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 
 * Input: [2,1,3]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 
 * Input: [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isBST(root, NULL, NULL);
    }

    bool isBST(TreeNode* root, int *min, int *max) {
        if (root == NULL)
        {
            return true;
        }

        if (min != NULL)
        {
            if (root->val <= *min)
            {
                return false;
            }
        }

        if (max != NULL)
        {
            if (root->val >= *max)
            {
                return false;
            }
        }
        
        if (!isBST(root->left, min, &root->val))
        {
            return false;
        }
        
        if (!isBST(root->right, &root->val, max))
        {
            return false;
        }

        return true;
    }
};
// @lc code=end

