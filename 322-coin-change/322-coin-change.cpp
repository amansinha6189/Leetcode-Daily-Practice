class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int N = coins.size();
        
        // vector<vector<int>> dp(N+1, vector<int> (amount+1, 0));
        vector<int> prev(amount+1, 0);
        
        // for(int i = 0; i<=amount; i++){
        //     dp[0][i] = INT_MAX - 1;
        // }
        
        for(int i = 0; i<=amount; i++){
            if(i%coins[0] == 0){
                prev[i] = i/coins[0];
            }else{
                prev[i] = INT_MAX - 1;
            }
        }
        
        for(int i = 2; i<=N; i++){
            vector<int> curr(amount+1, 0);
            for(int j = 0; j<=amount; j++){
                if(coins[i-1] > j){
                    curr[j] = prev[j];
                }else{
                    curr[j] = min(prev[j], curr[j-coins[i-1]] + 1); 
                }
            }
            prev = curr;
        }
        
        return prev[amount] < 1e6  ? prev[amount] : -1;
    }
};