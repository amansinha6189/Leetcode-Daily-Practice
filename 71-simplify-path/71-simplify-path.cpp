class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string temp = "";
        path += "/";
        for(char ch: path){
            if(ch == '/'){
                if(temp == ".."){
                    if(!st.empty()){
                        st.pop();
                    }
                }else if(temp != "" and temp != "."){
                    // if temp is neither empty nor . ---> we can not ignore this. temp is some file here.
                    st.push(temp);
                }
                temp = "";
            }else{
                temp += ch;
            }
        }
        
        string ans = "";
        
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        
        if(ans.length() == 0){
            ans = "/";
        }
        return ans;
    }
};