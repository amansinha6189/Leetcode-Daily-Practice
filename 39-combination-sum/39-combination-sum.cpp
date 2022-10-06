class Solution {
public:
    void solve(int index, int target, vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans){
        if(index == nums.size()){
            if(target == 0){
                ans.push_back(ds);
                return;
            }else{
                return;
            }
        }
        
        // pick
        if(nums[index] <= target){
            ds.push_back(nums[index]);
            solve(index, target - nums[index], ds, nums, ans);
            ds.pop_back();
        }
        // not pick
        solve(index + 1, target, ds, nums, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        solve(0, target, ds, nums, ans);
        
        return ans;
    }
};