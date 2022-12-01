class Solution {
public:
    bool halvesAreAlike(string s) {
        int count1 = 0;
        int count2 = 0;
        
        int N = s.length();
        
        for(int i = 0; i<N/2; i++){
            if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U'){
                count1++;
            }
        }
        
        for(int i = N/2; i<N; i++){
            if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U'){
                count2++;
            }
        }
        
        return count1 == count2;
    }
};