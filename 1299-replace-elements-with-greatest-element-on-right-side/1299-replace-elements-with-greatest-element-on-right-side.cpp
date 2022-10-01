class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int N = arr.size();
        vector<int> ans;
        ans.push_back(-1);
        
        int maxi = INT_MIN;
        for(int i = N-1; i >= 1; i--){
            maxi = max(maxi, arr[i]);
            ans.push_back(maxi);
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};