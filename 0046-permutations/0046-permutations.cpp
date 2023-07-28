class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        vector<vector<int>> ans;
        recursivePermutaion(nums, ans, index);
        return ans;
    }

    void recursivePermutaion(vector<int>& nums, vector<vector<int>>& ans, int index) {
        int n = nums.size();
        if (index == n) {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < n; i++) {
            swap(nums[index], nums[i]);
            recursivePermutaion(nums, ans, index + 1);
            swap(nums[index], nums[i]); // Backtrack to undo the swap for other permutations
        }
    }
};



