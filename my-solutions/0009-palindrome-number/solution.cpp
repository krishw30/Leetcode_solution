class Solution {
public:
    bool isPalindrome(int x) {
        bool result=true;
        string s=to_string(x);
        int low=0;
        int high=s.length()-1;
        while(high>low){
            if(s[low]!=s[high]){
                return false;
            }
            low++;
            high--;

        }
        return true;
        
    }
};
