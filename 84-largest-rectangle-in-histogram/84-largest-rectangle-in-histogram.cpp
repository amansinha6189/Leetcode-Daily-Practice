class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> st;
        
        int N = heights.size();
        
        for(int i = 0; i<N; i++){
            int start = i;
            // if condition in while loop id true we can not extend, therefore we have to pop it out. and calculate area.
            while(!st.empty() and st.top().second > heights[i]){
                int index = st.top().first;
                int height = st.top().second;
                
                st.pop();
                
                maxArea = max(maxArea, height*(i - index));
                start = index;
            }
            // if while loop do not follows ----> we just keep pushing it in stack.. as we are extending
            st.push({start, heights[i]});
        }
        
        
        // at last if anything left in stack calcualte area and remove.
        while(!st.empty()){
            int i = st.top().first;
            int h = st.top().second;
            maxArea = max(maxArea, h*(N-i));
            
            st.pop();
        }
        return maxArea;
    }
};