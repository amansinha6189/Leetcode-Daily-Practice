class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        
        vector<int> row(N, 0), col(M, 0);
        
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                row[i] = max(row[i], grid[i][j]);
                col[j] = max(col[j], grid[i][j]);
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                ans += min(row[i], col[j]) - grid[i][j];
            }
        }
        return ans;
    }
};