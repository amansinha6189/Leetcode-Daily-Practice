class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int N = nums.size();
        vector<long long> prefixSum(N, 0);
        
        long long sum = 0;
        for(auto it: nums) sum += it;
        
        int count = 0;
        long long frontSum = 0;
        for(int i = 0; i<N-1; i++){
            frontSum += nums[i];
            long long endSum = sum - frontSum;
            
            if(frontSum >= endSum) count++;
        }
        return count;
    }
};