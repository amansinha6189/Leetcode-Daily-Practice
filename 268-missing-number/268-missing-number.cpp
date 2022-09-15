class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(auto it: nums){
            sum += it;
        }
        
        int N = nums.size();
        
        int s = N*(N+1)/2;
        
        return s - sum;
    }
};