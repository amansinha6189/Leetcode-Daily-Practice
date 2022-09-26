class Solution {
public:
    
    void solve(int N, vector<string> &ans, int open, int close, string temp){
        if(open == N and close == N){
            ans.push_back(temp);
            return;
        }
        if(open < N){
            temp += '(';
            solve(N, ans, open+1, close, temp);
            temp.pop_back();
        }
        if(open > close){
            temp += ')';
            solve(N, ans, open, close+1, temp);
            return;
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp = "";
        vector<string> ans;
        int open = 0, close = 0;
        
        solve(n, ans, open, close, temp);
        
        return ans;
    }
};