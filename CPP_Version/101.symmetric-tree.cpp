/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (44.68%)
 * Likes:    2828
 * Dislikes: 64
 * Total Accepted:    491.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3] is not:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            return symHelper(root->left, root->right);
        }
    }

    bool symHelper(TreeNode* a, TreeNode* b) {
        if (a==NULL && b!=NULL)
        {
            return false;
        }

        if (a!=NULL && b==NULL)
        {
            return false;
        }

        if (a==NULL && b==NULL)
        {
            return true;
        }        
        
        if (a->val != b->val)
        {
            return false;
        }
        else
        {
            return symHelper(a->left, b->right) && symHelper(a->right, b->left);
        }
    }
};
// @lc code=end

