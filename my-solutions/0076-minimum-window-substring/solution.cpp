class Solution {
public:
    string minWindow(string s, string t) {
        // Tracker: 128 slots covers all ASCII characters (uppercase & lowercase)
        vector<int> map(128, 0);
        
        // 1. Set the Initial Debt (What do we need?)
        for (char c : t) {
            map[c]++;
        }
        
        int required = t.size(); // Total characters we still need to find
        int left = 0;
        int min_len = INT_MAX;
        int min_start = 0;
        
        // 2. The Explorer marches forward
        for (int right = 0; right < s.size(); right++) {
            
            // If the map says we need this character (value > 0), cross it off our list
            if (map[s[right]] > 0) {
                required--;
            }
            // Add to window (Decreasing the value means we "have" it. Surpluses become negative)
            map[s[right]]--; 
            
            // 3. The Fixer activates ONLY when we have all required characters
            while (required == 0) {
                
                // Record the window if it's the smallest one we've seen
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_start = left;
                }
                
                // Shrink the window from the left
                map[s[left]]++; // Taking it out of our window (increasing the "need")
                
                // If taking it out means we now NEED it again, our rule is broken!
                if (map[s[left]] > 0) {
                    required++; 
                }
                
                left++; // Snap the left side forward
            }
        }
        
        // If min_len never changed, we found nothing. Otherwise, extract the string.
        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};
