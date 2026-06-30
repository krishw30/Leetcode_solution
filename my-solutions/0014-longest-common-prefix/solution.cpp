class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string result = "";
        int i = 0;
        
        while (i < strs[0].length()) {
            char c = strs[0][i];
            int x = 0;
           
            while (x < strs.size() && i < strs[x].length() && strs[x][i] == c) {
                x++;
            }
            
            if (x == strs.size()) {
                result += c; 
                i++;
            } else {
                break; 
            }
        }
        return result;
    }
};

