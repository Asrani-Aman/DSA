class Solution {
public:
    string frequencySort(string s) {
       map<char,int> mpp;
       string ans;
       for(int i = 0; i<s.size(); i++)
       {
           mpp[s[i]]++;
       } 
       vector<pair<char,int>> helper;
       for(auto it : mpp)
       {
           helper.push_back({it.first,it.second});
       } 
       for(auto it : mpp)
       {
           cout<< it.first<<"-"<<it.second<<endl;
       } 
        sort(helper.begin(), helper.end(), [](const pair<char,int>& a, const pair<char,int>& b) {
            return a.second > b.second; // Sort by frequency in descending order
        });
         for(auto it : helper) {
            ans += string(it.second, it.first);
        } 
       return ans;
    }
};