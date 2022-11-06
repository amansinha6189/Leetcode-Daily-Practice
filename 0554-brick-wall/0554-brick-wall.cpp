class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int N = wall.size();
        map<int,int> mpp;
        
        int part = 0;
        for(int i = 0; i<N; i++){
            int a = 0;
            for(int j = 0; j < wall[i].size() - 1; j++){
                a += wall[i][j];
                mpp[a]++;
                part = max(part, mpp[a]);
            }
        }
        return N - part;
    }
};