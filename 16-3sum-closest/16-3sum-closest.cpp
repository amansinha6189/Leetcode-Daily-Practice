class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int N = nums.size();
        
        sort(nums.begin(), nums.end());
        int ans;
        int diff = INT_MAX;
        for(int i = 0; i<N; i++){
            if(i > 0 and nums[i] == nums[i-1]) continue;
            
            int low = i + 1; 
            int high = N - 1;
            
            while(low < high){
               int sum = nums[i] + nums[low] + nums[high];
                
                if(abs(sum - target) < abs(diff)){
                    diff = sum - target;
                }
                
                
                if(sum == target) return target;
                
                if(sum < target) low++;
                else high--;
            }
        }
        return diff + target;
    }
};