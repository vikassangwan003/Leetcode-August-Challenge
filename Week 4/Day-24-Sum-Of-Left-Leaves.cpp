/**
Problem: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3435/

Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

**/

//Solution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* node){
        if(node==NULL)return 0;
        int ans=0;
        if(node->left!=NULL&&node->left->left==NULL&&node->left->right==NULL)
            ans=node->left->val;
        
        return ans+dfs(node->left)+dfs(node->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root);
    }
};
