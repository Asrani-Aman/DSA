class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hashmap;
        int n  = nums.size();
        int ans;
        for(int i =0; i<nums.size(); i++)
        {
            hashmap[nums[i]]++;
        }
        for(auto it :hashmap )
        {
            if(it.second>n/2)
            {
                ans = it.first;
                break;
            }           
        }
        return ans;
        
    }
};