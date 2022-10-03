class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int N = colors.length();
        int ans = 0;
        
        for(int i = 0; i<N; ){
            int j = i;
            int mx = neededTime[i];
            int max_index = i;
            
            while(j < N and colors[i] == colors[j]){
                if(neededTime[j] > mx){
                    mx = neededTime[j];
                    max_index = j;
                }
                j++;
            }
            int sum = 0;
            
            for(int k = i; k < j; k++){
                if(k != max_index){
                    sum += neededTime[k];
                }
            }
            
            ans += sum;
            i = j;
        }
        return ans;
    }
};