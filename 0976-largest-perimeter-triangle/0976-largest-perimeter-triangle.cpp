class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());

        int N = nums.size();
        for(int i = 0; i<N-2; i++){
            if(nums[i+1] + nums[i+2] > nums[i]){
                return nums[i] + nums[i+1] + nums[i+2];
            }
        }
        return 0;
    }
};