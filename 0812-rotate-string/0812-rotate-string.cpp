class Solution {
public:
    bool rotateString(string s, string goal) {
        // we made two queue
        queue<char> q1,q2; 
        int n = s.size();

        for(int i=0; i<n; i++) q1.push(s[i]);
        for(int i=0; i<n; i++) q2.push(goal[i]);
        if(q1==q2) return true;

        int k =goal.size()-1;
        while(k!=0)
        {
            char ch = q2.front();
            q2.pop();
            q2.push(ch);

            if(q1==q2) return true;
            k--;
        }
        return false;
    }
};