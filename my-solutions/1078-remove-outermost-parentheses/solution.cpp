class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int balance = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (c == '(') {
                if (balance > 0) {
                    result += c;   // not the outermost opening bracket, so keep it
                }
                balance++;
            } else { // c == ')'
                balance--;
                if (balance > 0) {
                    result += c;   // not the outermost closing bracket, so keep it
                }
            }
        }

        return result;
    }
};
