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
private: 
    int max_depth;
    int ans;
    
    void dfs(TreeNode* node, int depth){
        if(node == NULL){
            return ;
        }
        
        if(depth > max_depth) {
            max_depth = depth;
            ans = node->val;
        }else if(depth == max_depth){
            ans += node->val;
        }
        
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        max_depth = 0;
        ans = 0;
        
        dfs(root, 0);
        
        return ans;
    }
};