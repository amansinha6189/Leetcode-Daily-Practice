class Solution {
public:
   int dfs(vector<vector<int>>& grid, int i, int j, int n, int m, vector<int> &v){
        if(i == n){
            return j;
        }
        
        int k = j + grid[i][j];
        
        if(k<0 or k>=m or grid[i][j] != grid[i][k]){
            return -1;
        }

        return dfs(grid, i+1, k, n, m, v);
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> v(m);

        for(int i = 0; i<m; i++){
            v[i] = dfs(grid, 0, i, n, m, v);
        }
        
        return v;
    }
};