class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        // this question should be done by hashing
        if(s.size()!= t.size())  return false;
        int n = s.size();

        vector<int> hashS(26,0);
        vector<int> hashT(26,0);
        for(int i=0; i<n; i++)
        {
            hashS[s[i]-'a']++;
            hashT[t[i]-'a']++;
        }
        for(int i=0; i<26; i++)
        {
            if(hashS[i]!=hashT[i]) return false;
        }
        return true;

        

    }
};