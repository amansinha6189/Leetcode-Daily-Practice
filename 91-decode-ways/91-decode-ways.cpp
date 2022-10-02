class Solution {
public:
    
    int solve(string s, int index, vector<int> &dp){
        if(index == s.length()){
            return 1;
        }
        
        // if(s[index] == '0'){
        //     return 0;
        // }
        
        if(dp[index] != -1){
            return dp[index];
        }
        
        int ans = 0;
        
        if(s[index] != '0'){
            ans += solve(s, index+1, dp);
        }
        
        if(index + 1 < s.length()){
            if(s[index] != '0'){
                int num = s[index] - '0';
                num *= 10;
                num += s[index+1] - '0';
                if(num <= 26){
                    ans += solve(s, index+2, dp);
                }
            }
        }
        
        return dp[index] = ans;
    }
    int numDecodings(string s) {
        int N = s.length();
        vector<int> dp(101, -1);
        
        return solve(s, 0, dp);
        
    }
};