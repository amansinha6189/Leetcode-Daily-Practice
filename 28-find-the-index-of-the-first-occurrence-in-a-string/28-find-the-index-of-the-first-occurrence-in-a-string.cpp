class Solution {
public:
    int strStr(string haystack, string needle) {
        int M = needle.size();
        int N = haystack.size();
        
        int i = 0, j = 0;
        
        while(j < N){
            if(j - i + 1 == M){
                string check = haystack.substr(i, j - i + 1);
                
                if(check == needle){
                    return i;
                }else{
                    i++;
                }
            }
            j++;
        }
        return -1;
    }
};