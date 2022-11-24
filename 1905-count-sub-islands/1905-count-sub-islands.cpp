class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int N = grid1[0].size();
        int M = grid1.size();
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        
        queue<pair<int, int>> q;
        int count = 0;
        
        for(int i = 0; i<M; i++){
            for(int j = 0; j<N; j++){
                if(grid2[i][j] == 1){
                    q.push({i,j});
                    
                    int curr = 1;
                    
                    while(!q.empty()){
                        int X = q.front().first;
                        int Y = q.front().second;
                        grid2[X][Y] = 0;
                        
                        q.pop();
                        
                        if(grid1[X][Y] == 0) curr = 0;
                        
                        for(int d = 0; d < 4; d++){
                            int newX = X + dx[d];
                            int newY = Y + dy[d];
                            
                            if(newX >= 0 and newX < M and newY >= 0 and newY < N and grid2[newX][newY] == 1){
                                grid2[newX][newY] = 0;
                                q.push({newX, newY});
                            }
                        }
                    }
                    count += curr;
                }
            }
        }
        return count;
    }
};