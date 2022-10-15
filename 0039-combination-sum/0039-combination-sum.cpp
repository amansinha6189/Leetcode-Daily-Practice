class Solution {
public:
    void solve(int index, int target, vector<int> &temp, vector<vector<int>> &ans, vector<int> &nums){
        int N = nums.size();
        
        if(index == N){
            return;
        }
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        
        if(nums[index] <= target){
            temp.push_back(nums[index]);
            solve(index, target - nums[index], temp, ans, nums);
            temp.pop_back();
        }
        
        solve(index + 1, target, temp, ans, nums);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        solve(0, target, temp, ans, candidates);
        
        return ans;
    }
};