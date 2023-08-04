class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low =0;
        int high =n-1;
        while(low<=high)
        {
            int mid =low+(high-low)/2;
            if(target ==nums[mid])
            {
                return mid;
            }
            // check if left part is sorted
            if(nums[mid]>=nums[low])
            {
                // check elememt is present in left part of the sorted arrray
                if(target<nums[mid] && target>=nums[low])
                {
                    // element is in lesft part of the sorted array
                    high = mid-1;
                }
                // else elmement is in unsorrted part
                else low = mid+1;
            }
            // else right part is sorted;
            else
            {
                if(target>nums[mid] && target<=nums[high])
                {
                    // element is in right part of the sorted array
                    low = mid+1;
                }   
                else high = mid-1;
            }
        }
        return -1;
    }
};