class Solution {
public:
    void helper(vector<string>& v,int n,int op,int cp,string s)
    {
        if(op==n && cp ==n)
        {
            v.push_back(s);
        }
        if(op<n) helper(v,n,op+1,cp,s+"(");
        if (op>cp) helper(v,n,op,cp+1,s+")");
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        int op =0;
        int cp =0;
        helper(v,n,op,cp,"");
        return v;
    }
};