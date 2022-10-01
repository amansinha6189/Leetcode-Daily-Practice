class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int temp = 0;
        for(auto it: s){
            if(it != ' '){
                temp++;
                ans = temp;
            }
            if(it == ' '){
                temp = 0;
            }
        }
        return ans;
    }
};