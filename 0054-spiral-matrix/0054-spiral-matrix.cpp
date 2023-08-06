class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row= matrix.size();
        int column = matrix[0].size();
        int left =0;
        int top=0;
        int right=column-1;
        int bottom =row-1;
        vector<int> ans;


        while(left<=right && top<=bottom)
        {
            // printing left to right
            for(int i=left; i<=right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;

            // printing top to bottom
            
            
                for(int i=top;i<=bottom;i++)
                {
                    ans.push_back(matrix[i][right]);           
                }
                right--;
            
            

            //right to left
            if( top<=bottom)
            {
                for(int i=right;i>=left; i--)
                {
                    ans.push_back(matrix[bottom][i]);   
                    cout<<endl<<  matrix[bottom][right]<<endl;
                }
                bottom--;           
            }

            // printing bottom to top;
            if(right>=left)
            {
                for(int i=bottom; i>=top;i--)
                {
                    ans.push_back(matrix[i][left]);            
                }
                left++;
            }
            

        }
        return ans;

    }
};