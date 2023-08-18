class Solution {
public:
         //1. agr ek live(1) node hai or 2 se kam uske live neighbors hai to use 0 krdo
                     //2. agr ek live(1) node hai or uske 2 ya 3 neighbors hai to use 1 hi rkho


                //3. agr ek live(1) node hai or uske 3 se jyada live neighbors hai to use 0 bna do
         //4. agr ek dead(0) or agr uske 3 live(1) neighbors hai to use 1 bna do
    int solve(vector<vector<int>>&mt,int m,int n,int i,int j){
    int count=0;
    if(i>0){
         if(mt[i-1][j]==1)count++;
    }
    if(i<m-1){
         if(mt[i+1][j]==1)count++;
    }
    if(j>0){
         if(mt[i][j-1]==1)count++;
    }
    if(j<n-1){
         if(mt[i][j+1]==1)count++;
    }
    if(i>0 && j>0){
         if(mt[i-1][j-1]==1)count++;
    }
    if(i>0 && j<n-1){
        if(mt[i-1][j+1]==1)count++;
    }
    if(i<m-1 && j>0){
         if(mt[i+1][j-1]==1)count++;
    }
    if(i<m-1 && j<n-1){
         if(mt[i+1][j+1]==1)count++;
    }
    return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int row=board.size();
        int col=board[0].size();
        vector<vector<int>>mt=board;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){

                int ans=solve(mt,row,col,i,j);
                if(board[i][j]==0){
                       if(ans==3) board[i][j]=1;

                }
                else if(board[i][j]==1){
                    if(ans<2 || ans>3) board[i][j]=0;
                }  
            }
        }
                        
    }
};
