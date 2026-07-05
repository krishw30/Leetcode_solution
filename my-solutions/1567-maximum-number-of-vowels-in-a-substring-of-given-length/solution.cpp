class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0;
        int left = 0;
        int n = s.size();
        
        for(int i = 0; i < k; i++){
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                count++;
            }
        }
        
        int answer = count; 
        
        for(int right = k; right < n; right++){
            if (s[right] == 'a' || s[right] == 'e' || s[right] == 'i' || s[right] == 'o' || s[right] == 'u') {
                count++;
            }
            if (s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' || s[left] == 'u') {
                count--;
            }
            
            answer = max(answer, count); 
            left++;
        }
        
        return answer;
    }
};

