class Solution {
public:
    bool checkString(string s) {
        int n=s.length();
        int flagb=0;
        for(int i=0;i<n;i++){
            if(flagb){
                if(s[i]=='a'){
                    return false;
                }

            }
           else{ 
            if(s[i]=='b'){
                flagb=1;
            }
           }
        }

        return true;
        
    }
};
