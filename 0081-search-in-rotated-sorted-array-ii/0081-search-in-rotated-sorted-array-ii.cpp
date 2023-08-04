class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low=0;
        int high=n-1;
        int pivot =-1;
        for(int i=0; i<n-1; i++)
        {
            if(nums[i+1]<nums[i])
            {
                pivot = i;
                break;
            }
        }
        if(pivot>-1)
        {
            reverse(nums.begin(),nums.begin()+pivot+1);
            reverse(nums.begin()+pivot+1, nums.end());
            reverse(nums.begin(),nums.end());
        }

       
        // binary search
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid]>target) high=mid-1;
            else low= mid+1;
        }
        return false;

    }
};