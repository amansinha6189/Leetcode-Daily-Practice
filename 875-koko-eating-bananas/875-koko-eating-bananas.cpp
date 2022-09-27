class Solution {
public:
    
    long countHrs(vector<int> &piles, int m){
        long count = 0;
        for(auto it: piles){
            // here we can also ciel function
            if(it%m == 0){
                count += it/m;
            }else{
                count += (it/m + 1);
            }
        }
        
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = INT_MIN;
        int low = 1;
        
        
        for(auto it: piles){
            high = max(high, it);
        }
        
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low)/2;
            long cnt = countHrs(piles, mid);
            if(cnt <= h){
                high = mid - 1;
                ans = min(ans, mid);
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};