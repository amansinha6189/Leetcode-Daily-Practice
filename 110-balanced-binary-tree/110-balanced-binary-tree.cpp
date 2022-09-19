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

// brute force -> for every node check for left and right height, difference fo both heoght is greater than 1, it is not balanced binary tree.
class Solution {
public:
    
    int dfsHeight(TreeNode* node){
        if(node == NULL){
            return 0;
        }
        
        int lh = dfsHeight(node->left);
        if(lh == -1) return -1;
        
        int rh = dfsHeight(node->right);
        if(rh == -1) return -1;
        
        if(abs(lh - rh) > 1) return -1;
        
        return max(lh, rh) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
};