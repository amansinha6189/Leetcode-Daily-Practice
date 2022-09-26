class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        int N = temperatures.size();
        vector<int> ans(N);
        
        for(int i = 0; i<N; i++){
            while(!st.empty() and temperatures[i] > st.top().first){
                int stackIndex = st.top().second;
                int temp = st.top().first;
                
                st.pop();
                
                ans[stackIndex] = i - stackIndex;
            }
            st.push({temperatures[i],i});
        }
        return ans;
    }
};