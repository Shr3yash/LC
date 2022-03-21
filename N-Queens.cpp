class Solution {
public:
    bool safe(int row, int col, vector<string> board, int n){
        int trow=row;
        int tcol=col;
        while(row>=0&&col>=0)
        {
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        row=trow;
        col=tcol;
        
        while(col>=0){
            if(board[row][col]=='Q')return false;
            col--;
        }
        col=tcol;
        while(row<n&&col>=0){
            if(board[row][col]=='Q')return false;
            row++;
            col--;
        }
        return true;
    }
public:
    
        void check(int col, vector<vector<string>>& ans, vector<string>& board, int n)
        {
            if(col==n)
            {
                ans.push_back(board);
                return;
            }
            for(int row=0; row<n; row++){
                if(safe(row, col, board, n))
                {
                    board[row][col]='Q';
                    check(col+1, ans, board, n);
                    board[row][col]='.';
                }
            }
        }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.'); 
        for(int i = 0;i<n;i++) {
            board[i] = s; 
        }
         
        check(0, ans, board, n);
        return ans;
        
    }
};
