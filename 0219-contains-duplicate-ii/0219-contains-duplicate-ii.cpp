class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        
        int N = nums.size();
        for(int i = 0; i<N; i++){
            auto it = mpp.find(nums[i]);
            
            if(it != mpp.end() and abs(it->second - i) <= k) return true;
            
            mpp[nums[i]] = i;
        }
        return false;
    }
};