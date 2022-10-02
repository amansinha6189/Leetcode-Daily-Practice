class Solution {
public:
    int mod = 1e9+7;
    long solve(int index, int k, int sum, int target, vector<vector<int>> &dp){
        if(index == 0 and sum == target){
            return 1;
        }
        if(index == 0 and sum != target){
            return 0;
        }
        
        long ans = 0;
        
        if(dp[index][sum] != -1){
            return dp[index][sum];
        }
        
        for(int i = 1; i <= k; i++ ){
            ans += solve(index - 1, k, sum + i, target, dp);
        }
        
        return dp[index][sum] = ans%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int> (1001, -1));
        return solve(n, k, 0, target, dp);
    }
};