class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int sum = 0;
        int N = nums.size();
        
        vector<long long> prefixSum(N, 0);
        prefixSum[0] = nums[0];
        
        int minAvg = INT_MAX;
        int ans = 0;
        
        for(int i = 1; i<N; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        
        for(int i = 0; i<N; i++){
            int temp;
            if(i + 1 == N) {
                temp = abs(prefixSum[i]/(i+1));
            }else{
                temp = abs(prefixSum[i]/(i+1) - (prefixSum[N-1] - prefixSum[i])/(N-i-1));
            }
            
            if(temp < minAvg){
                minAvg = temp;
                ans = i;
            }
        }
        return ans;
    }
};