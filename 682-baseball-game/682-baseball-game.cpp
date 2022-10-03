class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        
        for(string it: operations){
            if(it != "+" and it != "D" and it != "C"){
                int num = stoi(it);
                st.push(num);
            }else if(it == "+"){
                int prev = st.top();
                st.pop();
                int prev2prev = st.top();
                st.push(prev);
                st.push(prev + prev2prev);
            }else if(it == "D"){
                st.push(2*st.top());
            }else if(it == "C"){
                st.pop();
            }
        }
        
        int sum = 0;
        
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        
        return sum;
    }
};