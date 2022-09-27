class Solution {
public:
    int arrangeCoins(int n) {
        long high = n;
        long low = 1;
        
        long ans = 0;
        while(low <= high){
            long mid = low + (high - low) /2;
            if(mid*(mid+1)/2 > n){
                high = mid - 1;
            }else{
                low = mid + 1;
                ans = max(ans, mid);
            }
        }
        return (int)ans;
    }
};