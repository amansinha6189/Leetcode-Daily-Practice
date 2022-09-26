class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        int N = temperatures.size();
        vector<int> ans(N);
        
        for(int i = 0; i<N; i++){
            while(!st.empty() and temperatures[i] > st.top().first){
                int reqIndex = st.top().second;
                int temp = st.top().first;
                
                st.pop();
                
                ans[reqIndex] = i - reqIndex;
            }
            st.push({temperatures[i],i});
        }
        return ans;
    }
};