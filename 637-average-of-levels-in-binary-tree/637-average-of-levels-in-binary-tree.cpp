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
    void bfs(TreeNode* root, vector<double> &ans){
        if(root == NULL){
            
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root == NULL){   
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            double avg = 0;
            
            for(int i = 0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(node->right) {
                    q.push(node->right);
                }
                if(node->left) {
                    q.push(node->left);
                }
                
                avg += node->val;
            }
            
            avg /= size;
            ans.push_back(avg);
        }
        return ans;
    }
};