class Solution {
public:
    void evaluate(stack<long long int> &st, string op){
        long long int num1 = st.top();
        st.pop();
        
        long long int num2 = st.top();
        st.pop();
        
        if(op == "+"){
            st.push(num2 + num1);
        }else if(op == "-"){
            st.push(num2 - num1);
        }else if(op == "*"){
            st.push(num2 * num1);
        }else{
            if(num1 != 0){
                st.push(num2 / num1);
            }
        }
    }
    int evalRPN(vector<string>& tokens) {
        stack<long long int> st;
        
        for(auto it: tokens){
            if(it != "+" and it != "-" and it != "/" and it != "*"){
                long long int num = stoi(it);
                st.push(num);
            }else{
                evaluate(st, it);
            }
        }
        return st.top();
    }
};