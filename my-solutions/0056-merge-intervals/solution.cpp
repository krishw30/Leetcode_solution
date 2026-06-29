class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        std::sort(intervals.begin(),intervals.end());
        vector<vector<int>> answer;
        for(int j=0;j<n;j++){
            int start=intervals[j][0];
            int end=intervals[j][1];
            int i=j;
            while(i+1<n&&end>=intervals[i+1][0]){
                end=max(end,intervals[i+1][1]);
                i++;
            }
                answer.push_back({start,end});

        j=i;
        }
        return answer;
        
    }
};
