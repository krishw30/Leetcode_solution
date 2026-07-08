class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> count;
        int n=s.size();
        int left=0;
        int maxl=0;
        for(int right=0;right<n;right++){
            count[s[right]]++;
            
            int max_freq=0;
            for (auto const& [ch, freq] : count) {
                max_freq = std::max(max_freq, freq);
                }
            while((right-left+1)-max_freq>k){
                count[s[left]]--;
                left++;
            }
            maxl=std::max((right-left+1),maxl);


        }
        
        return maxl;
    }
};
