class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> map; 
        
        int maxcount = 0;
        int left = 0; 

        for(int i = 0; i < n; i++) {
            char c = s[i];
            
          
            if(map.find(c) != map.end() && map[c] >= left) {
                left = map[c] + 1;
            }
            
            map[c] = i;
            
           
            int current_length = i - left + 1;
            
            maxcount = std::max(maxcount, current_length);
        }
        
        return maxcount;
    }
};
