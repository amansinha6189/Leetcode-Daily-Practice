class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int N = asteroids.size();
        stack<int> st;
        
        vector<int> ans;
        
        for(auto a: asteroids){
            while(!st.empty() and a < 0 and st.top() > 0) {
                int diff = st.top() + a;
                
                if(diff < 0){ // top asteriod in stck will be destroyed
                    st.pop();
                }else if(diff > 0){ //  a will be completely vanished and 
                    a = 0;
                }else{ // both will be destroyed
                    a = 0;
                    st.pop();
                }
            }
            if(a){
                st.push(a);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};