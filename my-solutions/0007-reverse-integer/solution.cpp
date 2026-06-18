#include <algorithm>
class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN)return 0;
        int flagn=0;

        if(x<0){
            flagn=1;
            x=x*-1;
        }
        string s=to_string(x);
        std::reverse(s.begin(),s.end());
        long long answer=std::stoll(s);
        if(flagn==1){
            answer= -answer;
        }
        if (answer > INT_MAX || answer < INT_MIN) {
            return 0;
        }
        return static_cast<int>(answer);


    
        
    }
};
