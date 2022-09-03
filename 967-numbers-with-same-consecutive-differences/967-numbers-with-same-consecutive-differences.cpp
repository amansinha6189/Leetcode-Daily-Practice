class Solution {
public:
//     void sove(vector<int> &ans, string temp, int index){
        
//     }
    vector<int> numsSameConsecDiff(int n, int k) {
        queue<int> q;
        vector<int> ans;
        for(int i = 1; i<10; i++){
            q.push(i);
        }
        
        for(int i = 1; i<n; i++){
            int size = q.size();
            while(size--){
                int topNum = q.front();
                q.pop();
                
                int unitDigit = topNum%10;
                
                if(unitDigit + k < 10){
                    q.push(10*topNum + unitDigit + k);
                }
                if(unitDigit - k >= 0 and k != 0){
                    q.push(10*topNum + unitDigit - k);
                }
            }
        }
        while(!q.empty()){
            int num = q.front();
            ans.push_back(num);
            q.pop();
        }
        
        return ans;
    }
};