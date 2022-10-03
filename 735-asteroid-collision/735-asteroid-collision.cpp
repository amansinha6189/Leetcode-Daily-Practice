class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto a: asteroids){
            while(!st.empty() and st.top() > 0 and a < 0){
                int diff = a + st.top();
                if(diff < 0){
                    st.pop();
                }else if(diff == 0){
                    a = 0;
                    st.pop();
                }else{
                    a = 0;
                } 
            }
            if(a){
                st.push(a);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};