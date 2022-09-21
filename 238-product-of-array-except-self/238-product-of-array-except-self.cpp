class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int temp = 1;
        int N = nums.size();
        
        vector<int> ans(N);
        for(int i = 0; i<N; i++){
            ans[i] = temp;
            temp = temp*nums[i];
        }
        
        temp = 1;
        for(int i = N-1; i>=0; i--){
            ans[i] *= temp;
            temp = temp*nums[i];
        }
        
        return ans;
    }
};