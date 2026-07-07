class Solution {
public:
    long long sumAndMultiply(int n) {
        // Handle edge case upfront
        if (n == 0) return 0;

        long long sum = 0;
        long long non_zero_num = 0;
        long long place_value = 1;
        int num = n;

        // Process digits from right to left
        while (num > 0) {
            int digit = num % 10;
            
            // 1. Calculate sum of digits
            sum += digit;
            
            // 2. Build the new number without zeros
            if (digit != 0) {
                non_zero_num = digit * place_value + non_zero_num;
                place_value *= 10; // Move to the tens, hundreds place, etc.
            }
            
            num /= 10;
        }

        return non_zero_num * sum;
    }
};

