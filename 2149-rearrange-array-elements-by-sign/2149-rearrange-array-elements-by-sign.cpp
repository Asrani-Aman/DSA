class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // this is optimal solution with time complexityy O(n)
        int n=nums.size();
        vector<int> ans(n,0);
        int i =0;
        int j = i+1;
        
        for(int k=0; k<n; k++)
        {
            if(nums[k]>0)
            {
                ans[i]=nums[k];
                i+=2;
            }
            else
            {
                ans[j]=nums[k];
                j+=2;
            }
        }
        return ans;

    }
};