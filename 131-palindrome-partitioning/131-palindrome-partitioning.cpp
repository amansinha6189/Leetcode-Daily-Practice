class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
    void solve(int index, string s, vector<string> &part, vector<vector<string>> &ans){
        if(index == s.length()){
            ans.push_back(part);
            return;
        }
        
        for(int i = index; i < s.length(); i++){
            if(isPalindrome(s, index, i)){
                part.push_back(s.substr(index, i - index + 1));
                solve(i + 1, s, part, ans);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> part;
        vector<vector<string>> ans;
        
        solve(0, s, part, ans);
        
        return ans;
    }
};