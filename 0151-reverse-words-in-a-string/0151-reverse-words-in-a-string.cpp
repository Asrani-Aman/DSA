class Solution {
public:
    string reverseWords(string s) {
    int n = s.size();
    string ans = "";
    int i = 0;
    while (i < n) {
        while (i < n && s[i] == ' ') i++;
        if (i >= n) break;
        int j = i + 1;
        while (j < n && s[j] != ' ') j++;
        string sub = s.substr(i, j - i);
        //cout << "sub is:" << sub << " ans is:" << ans << endl;
        if(ans.length() == 0) ans = sub;
        else
        {
            if(ans.length()>0 )ans=sub+" "+ans;
            else ans=sub+ans;
        }
        i = j + 1;
    }
    return ans; 
}

};