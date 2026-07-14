class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int answer=0;
        if(n<(long long)k*m)return -1;
        int minw=*std::min_element(bloomDay.begin(),bloomDay.end());
        int maxw=*std::max_element(bloomDay.begin(),bloomDay.end());
        while(minw<=maxw){
            int wait=minw+(maxw-minw)/2;
            int count=0;
            int window=0;
            for(int i=0;i<n;i++){
                 if(bloomDay[i]<=wait){
                    window++;
                 }
                 else{
                    window=0;
                 }
                 if(window==k){
                    count++;
                    window=0;
                 }
            }
            if(count>=m){
                answer=wait;
                maxw=wait-1;
            }
            else{
                minw=wait+1;
            }
        }
        return answer;

        
    }
};
