class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int N = nums.size();
        int left = INT_MAX, mid = INT_MAX;
        for(int i=0; i<N; i++){
            if(nums[i]>mid) return true;
            else if(nums[i]>left && nums[i]<mid) mid = nums[i];
            else if(nums[i]<left) left = nums[i];
        }
        return false;   
    }
};