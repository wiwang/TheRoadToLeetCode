/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (43.66%)
 * Likes:    2174
 * Dislikes: 61
 * Total Accepted:    266K
 * Total Submissions: 607.9K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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

using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildNode(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode* buildNode(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
        int inMid;

        if (preStart > preEnd)
        {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);

        for (inMid = inStart; inMid <= inEnd; inMid++)
        {
            if (inorder[inMid] == preorder[preStart])
            {
                break;
            }
        }
        
        root->left = buildNode(preorder, inorder, preStart+1, preStart+inMid-inStart, inStart, inMid-1);
        root->right = buildNode(preorder, inorder, preStart+inMid-inStart+1, preEnd, inMid+1, inEnd);

        return root;
    }
};
// @lc code=end

