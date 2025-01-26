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
//Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
//Output: 32
//Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
class Solution {
public:
    int rsum;
    void dfs(TreeNode* root, int L, int R){
        if(!root) return; 
        if(root->val >= L && root->val <= R) rsum += root->val;
		if(root->val > L) dfs(root->left,L,R);
        if(root->val < R) dfs(root->right,L,R);}
    int rangeSumBST(TreeNode* root, int L, int R){
        rsum = 0;
        dfs(root,L,R);
        return rsum;}};

