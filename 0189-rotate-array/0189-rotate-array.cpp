class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int j = 0;
        vector<int> rotated_elements;
        k=k%n;

        for(int i=n-k; i<n; i++)
        {
            rotated_elements.push_back(nums[i]);
            j++;
        
        }
        for (int j =n-1; j>=k; j-- )
        {
            nums[j]=nums[j-k];
        }
        for(int l=0; l<k; l++)
        {
            nums[l] = rotated_elements[l];
        }

    }
};