/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (50.67%)
 * Likes:    1167
 * Dislikes: 63
 * Total Accepted:    300K
 * Total Submissions: 590.6K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
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
 * Output: [3,2,1]
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        
        if (root == NULL)
        {
            return ans;
        }
        
        s.push(root);
        while (!s.empty())
        {
            TreeNode* top = s.top();
            s.pop();

            ans.insert(ans.begin(), top->val);

            if (top->left != NULL)
            {
                s.push(top->left);
            }

            if (top->right != NULL)
            {
                s.push(top->right);
            }
        }

        return ans;   
    }
};
// @lc code=end

