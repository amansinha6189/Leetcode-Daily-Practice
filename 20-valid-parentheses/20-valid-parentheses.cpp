class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> CloseToOpen;
        
        CloseToOpen[')'] = '(';
        CloseToOpen[']'] = '[';
        CloseToOpen['}'] = '{';
        int N = s.length();
        
        for(char ch: s){
            if(CloseToOpen.find(ch) != CloseToOpen.end()){
                if(!st.empty() and st.top() == CloseToOpen[ch]){
                    st.pop();
                }else{
                    return false;
                }
            }else{
               st.push(ch);
            }
        }
        return st.empty() == true;
    }
};