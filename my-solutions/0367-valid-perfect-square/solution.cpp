class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1 || num == 0) return true;
        
        int start = 0;
        int copy = num / 2;
        
        while(start <= copy){
            int mid = start + (copy - start) / 2;
            
            long long square = (long long)mid * mid; 
            
            if(square == num){
                return true;
            }
            else if(square > num){
                copy = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return false;
    }
};
