class Solution {
public:
    bool solve(vector<int> &nums, vector<int> &dp, int index, int N){
        if(index >= N-1){
            return true;
        }
        
        if(dp[index] != -1) return dp[index];
        
        for(int i = nums[index]; i >= 1; i--){
            if(solve(nums, dp, index+i, N)) return dp[index] = true;
        }
        return dp[index] = false;
    }
    bool canJump(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N,-1);
        return solve(nums, dp, 0, N);
    }
};