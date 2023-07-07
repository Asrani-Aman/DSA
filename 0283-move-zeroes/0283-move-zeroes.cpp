class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // optima solution appproac two. pointer metho
        int i;
        int n=nums.size();
// find the first zero
        for (int k= 0; k<n; k++)
        {
            if (nums[k]==0 )
            {
                i=k;
                break;
            }
        }

        for (int j= i+1; j<n; j++)
        {
            if(nums[j]!=0)
            {
              //  cout<<"hbshd"<<endl;
                swap(nums[i], nums[j]);
                i++;
                // pointer i is always at zero
            }
        }


    }

};