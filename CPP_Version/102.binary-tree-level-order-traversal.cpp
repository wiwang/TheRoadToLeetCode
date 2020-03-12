/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (50.54%)
 * Likes:    1928
 * Dislikes: 51
 * Total Accepted:    460.1K
 * Total Submissions: 905.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
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
#include <queue>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<queue<TreeNode*>> q;
        int level = 0;
        bool next = true;

        if (root == NULL)
        {
            return result;
        }

        q[level].push(root);
        
        while (next)
        {
            next = false;
            while (!q[level].empty())
            {
                TreeNode* current = q[level].front();
                q[level].pop();
                result[level].push_back(current->val);

                if (current->left != NULL)
                {
                    q[level+1].push(current->left);
                    next = true;
                }

                if (current->right != NULL)
                {
                    q[level+1].push(current->right);
                    next = true;
                }
            }

            level++;
        }

        return result;
    }
};
// @lc code=end

