class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans(2, 0);
        int prev = 0;
        for(int i = 0; i < nums.size(); i++) {
            if((nums[i] - prev) == 2) ans[1] = nums[i]-1;
            if((nums[i] - prev) == 0) ans[0] = nums[i];
            prev = nums[i];
        }
        if(!ans[1]) ans[1] = nums[nums.size()-1]+1;
        return ans;
    }
};