class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int N = nums.size();
        int a = k%N;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+a);
        reverse(nums.begin() + a, nums.end());
        
    }
};