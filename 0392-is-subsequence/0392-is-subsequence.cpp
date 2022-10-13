class Solution {
public:
    bool isSubsequence(string s, string t) {
        int N = s.length();
        int M = t.length();
        
        int j = 0;
        for(int i = 0; i < M and j < N; i++ ){
            if(s[j] == t[i]){
                j++;
            }
        }
        return (j == N);
    }
};