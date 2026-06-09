class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int l = heights.size();
        vector<int> left(l, 0);
        vector<int> right(l, 0);
        stack<int> index;

        for(int i = 0; i < l; i++){
            while(index.size() > 0 && heights[index.top()] >= heights[i]){
                index.pop();
            }
            left[i] = index.empty() ? -1 : index.top();
            index.push(i);
        }
        
        while(!index.empty()){
            index.pop();
        }
        
        for(int i = l - 1; i > -1; i--){
            while(index.size() > 0 && heights[index.top()] >= heights[i]){
                index.pop();
            }
            right[i] = index.empty() ? l : index.top();
            index.push(i);
        }

    
        int area = 0;
        for(int i = 0; i < l; i++){
            int h = heights[i];
            int w = right[i] - left[i] - 1; 
            area = max(area, h * w);
        }
        return area;
    }
};
