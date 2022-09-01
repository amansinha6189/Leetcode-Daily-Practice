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
    void solve(TreeNode* root, int &count ,int maxi ){
        //base case
        if( root == NULL ){
            return;
        }

        maxi = max(maxi,root->val);

        if(root->val >= maxi){ 
            count++;         
        }

        solve(root->left,count,maxi);  //left part recursion
        solve(root->right,count,maxi); // right part recursion

    }

    int goodNodes(TreeNode* root) {
        int count = 0;  
        int maxi = INT_MIN;

        solve(root,count,maxi);

        return count;
    }
};