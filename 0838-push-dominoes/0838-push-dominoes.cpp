class Solution {
public:
    string pushDominoes(string dominoes) {
        int N = dominoes.size();
        int right=-1;
        
        for(int i=0;i<N;i++){
            if(dominoes[i]=='L'){
                if(right==-1){
                    for(int j=i-1;j>=0 and dominoes[j]=='.';j--){
                        dominoes[j]='L';
                    }
                }else{
                    int j=i-1;
                    int k=right+1;
                    while(k<j){
                        dominoes[k]='R';
                        dominoes[j]='L';
                        k++; j--;
                    }
                right=-1;
            }
        }else if(dominoes[i]=='R'){
                if(right!=-1){
                    for(int k=right+1;k<i;k++)
                        dominoes[k]='R';
                }
            right=i;
            }
        }
    
    

    if(right!=-1){
        for(int j =right+1;j<N;j++){
            dominoes[j]='R';
        }
    }
    return dominoes;
}
};