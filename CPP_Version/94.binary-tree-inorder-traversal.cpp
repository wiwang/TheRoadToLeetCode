/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (58.97%)
 * Likes:    2115
 * Dislikes: 95
 * Total Accepted:    561.5K
 * Total Submissions: 946.9K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
 * 
 * basically this pattern can also be used in preorder traverse
 */
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;

        while (root!=NULL || !s.empty())
        {
            while (root != NULL)
            {
                s.push(root);
                root = root->left;
            }

            root = s.top();
            s.pop();

            res.push_back(root->val);

            root = root->right;
        }

        return res;
    }
};
// @lc code=end

