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
void solve(TreeNode* root , int &ans,int &a)
{
    if(root==NULL)
    return ;

    solve(root->left,ans,a);
    if(a!=-1)
    {
        ans=min(ans,root->val-a);
    }

    a=root->val;
    solve(root->right,ans,a);

}
    int minDiffInBST(TreeNode* root) 
    {
        int ans=INT_MAX;
        int a=-1;
        solve(root,ans,a);
        return ans;
        
    }
};
