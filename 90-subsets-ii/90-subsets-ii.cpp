class Solution {
public:
    void solve(int index, vector<vector<int>> &ans, vector<int> &ds, vector<int> &nums){
        int N = nums.size();
        ans.push_back(ds);
        for(int i = index; i<N; i++){
            if(i != index and nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            solve(i + 1, ans, ds, nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        solve(0, ans, ds, nums);
        
        return ans;
    }
};