class Solution {
private:
    void dfs(vector<vector<char>>& board,vector<vector<int>>& vis,int row,int col,  int drow[],int dcol[])
    {
        int rows = board.size();
        int cols = board[0].size();
        vis[row][col] =1;
        for(int i=0; i<4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(ncol <cols && nrow<rows && ncol>=0 && nrow>=0 && !vis[nrow][ncol] && board[nrow][ncol] == 'O' )
            {
                dfs(board,vis,nrow,ncol,drow,dcol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> vis(rows, vector<int>(cols,0));
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
    

        // first col and last col (boundary conditions)
        for(int col =0; col<cols; col++)
        {
            // first row
            if(board[0][col] == 'O')
            {
                dfs(board,vis,0,col,drow,dcol);
            }
            // last row
            if(board[rows - 1][col] == 'O')
            {
                dfs(board,vis,rows-1,col,drow,dcol);
            }
        }
        for(int row =0; row<rows; row++)
        {
            // first col
            if(board[row][0] == 'O')
            {
                dfs(board,vis,row,0,drow,dcol);
            }
            // lastcol
            if(board[row][cols-1]=='O')
            {
                dfs(board,vis,row,cols-1,drow,dcol);
            }
        }
        for(int i =0; i< rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(vis[i][j] == 1)
                {
                    board[i][j]='O';
                }
                else
                {
                    board[i][j]='X';
                }
            }
        }

    }
};