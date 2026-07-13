#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> sequentialDigits(int low, int high) {
        std::vector<int> result;
        
        int low_len = 0, temp_low = low;
        while (temp_low > 0) { low_len++; temp_low /= 10; }
        
        int high_len = 0, temp_high = high;
        while (temp_high > 0) { high_len++; temp_high /= 10; }
        
        for (int len = low_len; len <= high_len; ++len) {
            for (int start_digit = 1; start_digit <= 10 - len; ++start_digit) {
                int num = 0;
                int current_digit = start_digit;
                
                for (int step = 0; step < len; ++step) {
                    num = num * 10 + current_digit;
                    current_digit++;
                }
                
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        return result;
    }
};

