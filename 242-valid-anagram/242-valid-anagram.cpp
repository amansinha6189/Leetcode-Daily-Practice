class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mpps;
        map<char, int> mppt;
        
        for(auto it: s){
            mpps[it]++;
        }
        for(auto it: t){
            mppt[it]++;
        }
        int N = s.size();
        int M = t.size();
        if(N != M) return false;
        for(int i = 0; i<N; i++){
            if(mpps[s[i]] != mppt[s[i]]){
                return false;
            }
        }
        return true;
    }
};