int dp[101][27][101][101];
class Solution {
public:
    string str;
    int solve(int index, int prev, int len, int k){
        if(k < 0) return INT_MAX;
        int N = str.length();
        if(index >= N) return 0;
        if(dp[index][prev][len][k] != -1) return dp[index][prev][len][k];
        int del = solve(index + 1, prev, len, k-1);
        int keep = 0;
        if(str[index] - 'a' == prev){
            if(len == 1 or len == 9 or len == 99){
                keep += 1;
            }
            keep += solve(index + 1, prev, len + 1, k);
        }else{
            keep = 1 + solve(index + 1, str[index] - 'a', 1, k);
        }
    
        return dp[index][prev][len][k] = min(del, keep);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        str = s;
        memset(dp, -1, sizeof(dp));
        return solve(0, 26, 0, k);
    }
};