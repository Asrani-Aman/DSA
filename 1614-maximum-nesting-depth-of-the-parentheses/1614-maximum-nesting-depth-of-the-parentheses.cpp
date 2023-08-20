class Solution {
public:
    int maxDepth(string s) {
        int prev_count =0;
        int count =0;

        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(') prev_count = max(prev_count,++count);
            else if(s[i]==')') count--;        
        }
        return prev_count;
    }
};