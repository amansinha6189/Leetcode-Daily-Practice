class Solution {
public:
    map<char, int> mpp;
    
    string frequencySort(string s) {
        for(auto it: s){
            mpp[it]++;
        }
        
        sort(s.begin(), s.end(), [&](char a, char b){
            if(mpp[a] > mpp[b]){
                return mpp[a] > mpp[b];
            }else if(mpp[a] == mpp[b]){
                return a < b;
            }else{
                return mpp[b] < mpp[a];
            }
        });
        
        return s;
        
    }
};