class Solution {
    public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        int prod = 1;
        int count = 0;
        for(int i = 0; i<N; i++){
            if(nums[i] != 0){
                prod *= nums[i];
            }else{
                count++;
            }
        }
        vector<int> ans(N, 0);
        vector<int> x(N,0);
        for(int i = 0; i<N; i++){
            if(nums[i] != 0 and count == 0){
                ans[i] = prod/nums[i];
            }else if(nums[i] == 0 and count >1){
                return x;
            }else if(nums[i] == 0 and count == 1) {
                ans[i] = prod;
            }
        }
        
        return ans;
    }
};