class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int N = coins.size();
        
        vector<vector<int>> dp(N+1, vector<int> (amount+1, 0));
        
        for(int i = 0; i<=amount; i++){
            dp[0][i] = INT_MAX - 1;
        }
        
        for(int i = 0; i<=amount; i++){
            if(i%coins[0] == 0){
                dp[1][i] = i/coins[0];
            }else{
                dp[1][i] = INT_MAX - 1;
            }
        }
        
        for(int i = 2; i<=N; i++){
            for(int j = 0; j<=amount; j++){
                if(coins[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1); 
                }
            }
        }
        
        return dp[N][amount] < 1e6  ? dp[N][amount] : -1;
    }
};