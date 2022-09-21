class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        
        vector<vector<bool>> vis(R, vector<bool> (C, false));
        
        int ans = 0;
        for(int i = 0; i<R; i++){
            for(int j = 0; j<C; j++){
                if(vis[i][j] == false and grid[i][j] == '1'){
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    ans++;
                    while(!q.empty()){
                        int X = q.front().first;
                        int Y = q.front().second;
                        
                        q.pop();
                        
                        int dx[4] = {-1,0,1,0};
                        int dy[4] = {0,1,0,-1};
                        
                        for(int dir = 0; dir<4; dir++){
                            int newX = X + dx[dir];
                            int newY = Y + dy[dir];
                            
                            if(newX >= 0 and newX < R and newY >= 0 and newY < C and vis[newX][newY] == false and grid[newX][newY] == '1'){
                                q.push({newX, newY});
                                vis[newX][newY] = true;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};