class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>answer;
        vector<int>copy=arr;
        unordered_map<int,int>rank;
        std::sort(copy.begin(),copy.end());
        int index=1;
        for(int i=0;i<arr.size();i++){
            if(rank.find(copy[i])==rank.end()){
                rank[copy[i]]=index;
                index++;
                }
        }
        for(int i=0;i<arr.size();i++){
            answer.push_back(rank[arr[i]]);
        }
        return answer;
        
    }
};
