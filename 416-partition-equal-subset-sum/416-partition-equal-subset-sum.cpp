class Solution {
public:
    bool subset[201][200001];
    bool subsetSum(vector<int> &nums,int N, int sum){
        for(int i = 0; i<=N; i++){
            subset[i][0] = true;
        }
        for(int i = 1; i<=sum ; i++){
            subset[0][i] = false;
        }
        
        for(int i = 1; i<=N; i++){
            for(int j = 1; j<=sum; j++){
                if(j < nums[i-1]){
                    subset[i][j] = subset[i-1][j];
                }else{
                    subset[i][j] = subset[i-1][j]||subset[i-1][j - nums[i-1]];
                }
            }
        }
        return subset[N][sum];
    }
    bool canPartition(vector<int>& nums) {
        int N = nums.size();
        int sum = 0;
        for(int i = 0; i<N; i++){
            sum += nums[i];
        }
        
        if(sum % 2 == 0) return subsetSum(nums, N,sum/2);
        else return false;
    }
};