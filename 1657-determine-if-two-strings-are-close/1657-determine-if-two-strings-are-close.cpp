class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int N = word1.size();
        int M = word2.size();
        
        map<char, int> mpp1;
        map<char, int> mpp2;
        
        for(auto it: word1){
            mpp1[it]++;    
        }
        
        for(auto it: word2){
            mpp2[it]++;
        }
        
        vector<int> hash1, hash2;
        for(auto it = mpp1.begin(); it != mpp1.end(); it++){
            hash1.push_back(mpp1[it->first]);
            hash2.push_back(mpp2[it->first]);
        }
        
        sort(hash1.begin(), hash1.end());
        sort(hash2.begin(), hash2.end());

        return hash1 == hash2;
    }
};