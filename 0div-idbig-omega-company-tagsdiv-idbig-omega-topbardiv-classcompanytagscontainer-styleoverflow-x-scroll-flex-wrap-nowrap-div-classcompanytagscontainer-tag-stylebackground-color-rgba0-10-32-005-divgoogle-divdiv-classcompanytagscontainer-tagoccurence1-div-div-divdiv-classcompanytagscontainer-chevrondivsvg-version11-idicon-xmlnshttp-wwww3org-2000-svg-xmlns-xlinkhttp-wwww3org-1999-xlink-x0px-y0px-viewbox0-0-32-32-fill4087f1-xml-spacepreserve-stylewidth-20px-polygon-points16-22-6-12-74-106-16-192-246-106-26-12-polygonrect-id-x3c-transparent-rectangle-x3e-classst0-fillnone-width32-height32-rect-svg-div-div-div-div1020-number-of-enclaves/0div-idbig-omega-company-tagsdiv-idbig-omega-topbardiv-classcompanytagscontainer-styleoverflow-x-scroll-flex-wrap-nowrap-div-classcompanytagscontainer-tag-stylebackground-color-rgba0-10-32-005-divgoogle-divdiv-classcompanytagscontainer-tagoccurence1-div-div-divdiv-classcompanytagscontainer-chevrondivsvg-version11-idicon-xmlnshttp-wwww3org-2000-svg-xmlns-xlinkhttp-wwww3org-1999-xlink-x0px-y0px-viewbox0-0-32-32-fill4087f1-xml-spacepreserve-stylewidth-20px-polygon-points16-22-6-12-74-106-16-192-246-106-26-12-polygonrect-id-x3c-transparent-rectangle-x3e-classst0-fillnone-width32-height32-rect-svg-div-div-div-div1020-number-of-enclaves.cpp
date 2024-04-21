// class Solution {
// private:
//     void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int& count,int row,int col, int drow[],int dcol[] )
//     {
//         int rows = grid.size();
//         int cols = grid[0].size();
//         for(int i=0; i<4; i++)
//         {
//             int nrow = row + drow[i];
//             int ncol = col + dcol[i];
//             if(vis[nrow][ncol]!=1 && grid[nrow][ncol]==1 && nrow>=0 && nrow<rows && ncol>=0 && ncol<cols )
//             {
//                 vis[nrow][ncol]=1;
//                 count--;
//                 dfs(grid,vis,count,nrow,ncol,drow,dcol);      
//             }
//         }
//     }
// public:
//     int numEnclaves(vector<vector<int>>& grid) {
//         int rows = grid.size();
//         int cols = grid[0].size();
//         vector<vector<int>> vis(rows, vector<int>(cols,0));
//         int drow[] = {-1,0,+1,0};
//         int dcol[]= {0,+1,0,-1};
//         int count =0;
//         // here i count number of 1's
//         for(int i =0; i<rows; i++)
//         {
//             for(int j=0; j<cols; j++)
//             {
//                 if(grid[i][j]==1)
//                 {
//                     count++;
//                 }
//             }
//         }
//         for(int row = 0; row <rows; row++)
//         {
//             // first col
//             if(grid[row][0]==1)
//             {
//                 if(vis[row][0] != 1)
//                 {
//                     vis[row][0] = 1;
//                     count--;
//                     dfs(grid,vis,count,row,0,drow,dcol);
//                 }
                
                
//             }
//             // last col
//             if(grid[row][cols-1]==1)
//             {
//                 if(vis[row][cols-1] != 1)
//                 {
//                     vis[row][cols-1] = 1;
//                     count--;
//                     dfs(grid,vis,count,row,cols-1,drow,dcol);
//                 }
                  
//             }
//         }
//         for(int col =0; col<cols; col++)
//         {
//             //first row
//             if(grid[0][col]==1)
//             {
//                 if(vis[0][col]!=1)
//                 {
//                     vis[0][col]=1;
//                     count--;
//                     dfs(grid,vis,count,0,col,drow,dcol);
//                 }
//             }
//             if(grid[rows-1][col]==1)
//             {
//                 if(vis[rows-1][col]!=1)
//                 {
//                     vis[rows-1][col]=1;
//                     count--;
//                     dfs(grid,vis,count,rows-1,col,drow,dcol);
//                 }
//             }
//         }
//         return count;
//     }
// };



class Solution {
public:
     void dfs(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& vis, int& count, int row, int col, int drow[], int dcol[]) {
        vis[row][col] = 1;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && vis[nrow][ncol] != 1 && grid[nrow][ncol] == 1) {
                dfs(grid, vis, count, nrow, ncol, drow, dcol);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> vis(rows, vector<int>(cols,0));
        int drow[] = {-1,0,+1,0};
        int dcol[]= {0,+1,0,-1};
        int count =0;
        // here i count number of 1's
        // for(int i =0; i<rows; i++)
        // {
        //     for(int j=0; j<cols; j++)
        //     {
        //         if(grid[i][j]==1)
        //         {
        //             count++;
        //         }
        //     }
        // }
        for(int row = 0; row <rows; row++)
        {
            // first col
            if(grid[row][0]==1 && vis[row][0] != 1)
                {
                    dfs(grid,vis,count,row,0,drow,dcol);
                }
            // last col
            if(grid[row][cols-1]==1 && vis[row][cols-1] != 1)
                {
                  
                    dfs(grid,vis,count,row,cols-1,drow,dcol);
                }
        }
        for(int col =0; col<cols; col++)
        {
            //first row
            if(grid[0][col]==1 && vis[0][col]!=1)
                {
                    
                    dfs(grid,vis,count,0,col,drow,dcol);
                }
            
            if(grid[rows-1][col]==1 && vis[rows-1][col]!=1)
                {
                   
                    dfs(grid,vis,count,rows-1,col,drow,dcol);
                }
          
            
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1 && vis[i][j] != 1) {
                    count++;
                }
            }
        }
        return count;
    }
};