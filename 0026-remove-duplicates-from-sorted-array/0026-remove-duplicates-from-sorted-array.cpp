class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        int i = 0;
        int j=i+1;
        int unique =1;
        while(j<n)
        {
            if(nums[i]!= nums[j])
            {
                unique++;
                i++;
                nums[i]=nums[j];
                j++;
            }
            else
            {
                j++;
            }
        }
        return unique;
    
        
    }
};