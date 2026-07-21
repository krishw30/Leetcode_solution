#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string answer = "";

        int right = n - 1;
        while (right >= 0 && s[right] == ' ') {
            right--;
        }

        int start = 0;
        while (start < n && s[start] == ' ') {
            start++;
        }

        for (int left = right; left >= start; left--) {
            if (s[left] != ' ') {
                continue;
            }

            int temp = left + 1;
            while (temp <= right) {
                if (s[temp] != ' ') {
                    answer += s[temp];
                }
                temp++;
            }
            if (right >= left + 1) {
                answer += ' ';
            }
            right = left - 1;
        }

        int temp = start;
        while (temp <= right) {
            if (s[temp] != ' ') {
                answer += s[temp];
            }
            temp++;
        }

        return answer;
    }
};
