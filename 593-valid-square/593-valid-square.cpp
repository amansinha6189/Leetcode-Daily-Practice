class Solution {
public:
    
    set<int> s;
    bool solve(vector<int> &a, vector<int> &b){
        
        if(a[0] == b[0] and a[1] == b[1]){
            return false;
        }
        int len1 = a[0] - b[0];
        int len2 = a[1] - b[1];
        
        s.insert(len1*len1 + len2*len2);
        return true;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(!solve(p1, p2) || !solve(p2, p3) || !solve(p3, p4) || !solve(p4, p1) || !solve(p1, p3) || !solve(p2, p4)){
            return false;
        }
        
        return s.size() == 2;
    }
};