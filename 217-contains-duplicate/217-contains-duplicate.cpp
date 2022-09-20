class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
//         sorting method
        // sort(nums.begin(), nums.end());
        // for(int i = 0; i<nums.size() - 1; i++){
        //     if(nums[i] == nums[i+1]){
        //         return true;
        //     }
        // }
        // return false;
       
//         mpping method
        map<int, int> mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        
        for(auto it = mpp.begin(); it != mpp.end(); it++){
            if(it->second > 1){
                return true;
            }
        }
        return false;
    }
};