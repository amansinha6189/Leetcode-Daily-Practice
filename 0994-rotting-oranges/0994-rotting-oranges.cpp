struct node{
    int x; int y; int time;
    node(int _x, int _y, int _time){
        x = _x;
        y = _y;
        time = _time;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        
        queue<node> q;
        int cntOranges = 0;
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                if(grid[i][j] != 0){
                    cntOranges++;
                }
                if(grid[i][j] == 2){
                    q.push(node(i, j, 0));   
                }
            }
        }
        
        int ans = 0;
        int count = 0;
        while(!q.empty()){
            int x = q.front().x;
            int y = q.front().y;
            int time = q.front().time;
            
            q.pop();
            
            int dx[4] = {-1,1,0,0};
            int dy[4] = {0,0,-1,1};
            
            ans = max(ans, time);
            count++;
            for(int dir = 0; dir<4; dir++){
                int newX = x + dx[dir];
                int newY = y + dy[dir];
                if(newX < N and newY < M and newX >= 0 and newY >= 0 and grid[newX][newY] == 1){
                    grid[newX][newY] = 2;
                    q.push(node(newX, newY, time + 1));
                }
            }
        }
        
        if(count == cntOranges) return ans;
        return -1;
    }
};