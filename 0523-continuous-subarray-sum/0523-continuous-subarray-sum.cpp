class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prev = 0;
        map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < nums.size(); i++){
			// generate current sum (mod k)
            nums[i] = (nums[i]+prev) % k;
            prev = nums[i];
			// if we have two places in the array where the current sums are equal
            if (m.find(nums[i]) != m.end()){
				// and they are at least 2 values long
                if (i-m[nums[i]] >= 2){
                    return true;
                }
			// otherwise record where we found a sum
            } else {
                m[nums[i]] = i;
            }
        }
        return false;   
    }
};