class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> m;
        int n = fruits.size();
        int left = 0;
        int answer = 0;
        int fruit;
        for (int right = 0; right < n; right++) {
            fruit = fruits[right];
            m[fruit]++;

            while (m.size() > 2) {
                if (m[fruits[left]] == 1) {
                    m.erase(fruits[left]);
                } else {
                    m[fruits[left]]--;
                }
                left++;
            }
            answer = std::max(answer, (right - left + 1));
        }
        return answer;
    }
};
