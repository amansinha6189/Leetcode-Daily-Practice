class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int low = 0; 
        int high = 0;
        
        for(auto it: nums){
            low = max(it, low);
            high += it;
        }
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            
            int count = 1;
            int tempSum = 0;
            
            for(auto it: nums){
                if(tempSum + it <= mid) tempSum += it;
                else {
                    count++;
                    tempSum = it;
                }
            }
            
            if(count <= m) {
                high = mid - 1;
                ans = mid;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};