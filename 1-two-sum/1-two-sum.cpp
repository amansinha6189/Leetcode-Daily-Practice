class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        
        int N = nums.size();
        vector<int> ans;        
        for(int i = 0; i<N; i++){
            if(mpp.find(target - nums[i]) != mpp.end()){
                ans.push_back(mpp[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }else{
                mpp[nums[i]] = i;
            }
        }
        return ans;
    }
};