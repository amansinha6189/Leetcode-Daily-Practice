class Solution {
public:
    bool checkValidString(string s) {
        stack<int> opening, star;
        
        int N = s.length();
        for(int i = 0; i < N; i++){
            char ch = s[i];
            if(ch == '('){
                opening.push(i);
            }else if(ch == '*'){
                star.push(i);
            }else{ // closing brackets only
                if(!opening.empty()){
                    opening.pop();
                }
                else if(!star.empty()){
                    star.pop();
                }else{ // niether ( nor * is left to balance ) so return false
                    return false;
                }
            }
        }
        
        while(!opening.empty()){
            if(star.empty()){ // only opening brackets left, no star is left to balance opening brackets
                return false;
            }else if(star.top() > opening.top()){ // if index of star is greater then index of opening bracket can balance opening bracket
                star.pop();
                opening.pop();
            }else{ // if index of star is less then index of opening bracket can balance opening bracket
                return false;
            }
        }
        return true;
    }
};