class Solution {
public:
    void solve(int index, vector<int> &ds, int k, int n, vector<vector<int>> &ans){
        if(ds.size() == k){
            ans.push_back(ds);
            return;
        }
        
        for(int i = index; i<=n; i++){
            ds.push_back(i);
            solve(i+1, ds, k, n, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> ds;
        vector<vector<int>> ans;
        
        solve(1, ds, k, n, ans);
        
        return ans;
    }
};