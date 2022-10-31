class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();
        
        for(int i = 0; i<N-1; i++){
            for(int j = 0; j<M-1; j++){
                if(matrix[i][j] != matrix[i+1][j+1]){
                    return false;
                }
            }
        }
        return true;
    }
};