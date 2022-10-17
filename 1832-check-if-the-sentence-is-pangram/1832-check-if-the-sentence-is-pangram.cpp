class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char>words;
        for(char p: sentence)
            words.insert(p);

        return words.size() == 26;
    }
    
};