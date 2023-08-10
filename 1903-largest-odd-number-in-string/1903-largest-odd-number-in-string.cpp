class Solution {
public:
    string largestOddNumber(string num) {
            for(int i=num.size(); i>=0; i--) {
              
                if((num[i] - '0') %2 == 1)// way of string conversion into a number
                {
                    return num.substr(0, i+1);
                }
        }
        
        return "";
    }
};