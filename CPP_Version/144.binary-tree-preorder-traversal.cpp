/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (52.89%)
 * Likes:    987
 * Dislikes: 46
 * Total Accepted:    391K
 * Total Submissions: 738.1K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,2,3]
 * 
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
 */
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;

        s.push(root);

        while (!s.empty())
        {
            TreeNode* top = s.top();
            s.pop();

            if (top != NULL)
            {
                s.push(top->right);
                s.push(top->left);

                result.push_back(top->val);
            }
        }
        
        return result;
        
    }
};
// @lc code=end

