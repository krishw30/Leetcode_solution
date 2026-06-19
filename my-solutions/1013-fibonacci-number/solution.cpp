class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        
        // Only allocate memory for the last two numbers
        int prev2 = 0; // Represents fib(n-2)
        int prev1 = 1; // Represents fib(n-1)
        int current;
        
        for (int i = 2; i <= n; i++) {
            current = prev1 + prev2; // Calculate the new number
            
            // Slide the memory window forward
            prev2 = prev1; 
            prev1 = current;
        }
        
        return current;
    }
};
