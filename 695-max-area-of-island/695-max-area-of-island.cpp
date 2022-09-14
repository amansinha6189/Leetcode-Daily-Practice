class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        int ans = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M ;j++){
                if(grid[i][j] == 1){
                    int count = 0;
                    
                    q.push({i,j});
                    grid[i][j] = 0;
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        
                        q.pop();
                        count++;
                        
                        int dx[4] = {-1,0,1,0};
                        int dy[4] = {0,1,0,-1};

                        for(int dir = 0; dir<4; dir++){
                            int newX = x + dx[dir];
                            int newY = y + dy[dir];
                            if(newX >= 0 and newX < N and newY >= 0 and newY < M and grid[newX][newY] == 1){
                                // if(grid[newX][newY] == 1){
                                    q.push({newX, newY});
                                    grid[newX][newY] = 0;
                                // }
                            }
                        }
                    }
                    ans = max(ans, count);
                }
            }
        }
        return ans;
    }
};