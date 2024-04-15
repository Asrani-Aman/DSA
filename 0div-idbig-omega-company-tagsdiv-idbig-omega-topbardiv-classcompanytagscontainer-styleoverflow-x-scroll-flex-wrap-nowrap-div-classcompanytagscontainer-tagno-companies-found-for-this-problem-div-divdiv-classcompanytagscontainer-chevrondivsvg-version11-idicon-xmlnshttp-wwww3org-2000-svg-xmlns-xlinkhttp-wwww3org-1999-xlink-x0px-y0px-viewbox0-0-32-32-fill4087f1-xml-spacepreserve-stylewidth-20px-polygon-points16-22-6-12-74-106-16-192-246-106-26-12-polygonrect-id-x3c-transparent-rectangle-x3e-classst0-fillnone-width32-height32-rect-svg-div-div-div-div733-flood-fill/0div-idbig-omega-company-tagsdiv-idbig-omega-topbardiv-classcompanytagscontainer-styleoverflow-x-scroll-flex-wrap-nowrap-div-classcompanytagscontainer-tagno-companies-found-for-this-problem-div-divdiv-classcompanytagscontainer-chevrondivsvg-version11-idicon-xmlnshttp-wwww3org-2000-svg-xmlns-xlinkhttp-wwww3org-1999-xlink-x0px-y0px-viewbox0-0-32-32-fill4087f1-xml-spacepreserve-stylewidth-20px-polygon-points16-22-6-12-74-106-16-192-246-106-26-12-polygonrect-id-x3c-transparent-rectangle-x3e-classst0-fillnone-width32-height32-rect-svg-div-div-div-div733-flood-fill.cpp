#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        int srcColor = image[sr][sc];
        vis[sr][sc] = color;
        if(srcColor == color) return image;

        // Doing BFS
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols &&
                    vis[nrow][ncol] == 0 && image[nrow][ncol] == srcColor) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = color;
                }
            }
        }
        for (int i =0; i<rows; i++){
            for(int j=0; j<cols; j++)
            {
                if(vis[i][j]==0 && image[i][j]!=0)
                {
                    vis[i][j]=image[i][j];
                }
            }
        }        
        return vis;
    }
};
