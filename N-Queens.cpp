class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n, '.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int>leftRow(n,0),upper(2*n-1,0),lower(2*n-1,0);
        solve(0,board,ans,n,leftRow,upper,lower);
        return ans;
    }
    void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n,vector<int>&leftRow,vector<int>&upper,vector<int>&lower){
        if(col==n){
            ans.push_back(board);
            return ;
        }
        for(int row=0;row<n;row++){
            if(leftRow[row]==0 && lower[row+col]==0 &&upper[n-1+col-row]==0){
                board[row][col]='Q';
                leftRow[row]=1;
                lower[row+col]=1;
                upper[n-1-row+col]=1;
                solve(col+1,board,ans,n,leftRow,upper,lower);
                board[row][col]='.';
                leftRow[row]=0;
                lower[row+col]=0;
                upper[n-1+col-row]=0;
            }
        }
    }

};
