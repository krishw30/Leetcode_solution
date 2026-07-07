class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplaced = 0;
        int n = fruits.size(); // Store size once for cleaner code
        
        for (int i = 0; i < n; i++) {
            int b = 0;
            
            // 1. Boundary check MUST come first to prevent SegFaults
            while (b < n && baskets[b] < fruits[i]) {
                b++;
            }
            
            // 2. Safe routing: Did we find a basket, or did we go out of bounds?
            if (b < n) {
                // We found a basket! Mark it as used.
                baskets[b] = INT_MIN; 
            } else {
                // We went out of bounds. No basket found.
                unplaced++; 
            }
        }
        
        return unplaced;
    }
};
