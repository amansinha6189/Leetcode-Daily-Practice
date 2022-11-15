class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size();
        int mx_area = 0;
        
        int low = 0;
        int high = N-1;
        
        while(low <= high){
            int h = min(height[low], height[high]);
            int area = h*(high - low);
            mx_area = max(area, mx_area);
            
            if(height[low] < height[high]){
                low++;
            }else{
                high--;
            }
        }
        return mx_area;
    }
};