class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        int dist[n];
        double time[n];
        int fleet=0;
        double recent=0;
        vector<pair<int, double>> cars;
        for(int i=0;i<n;i++){
            dist[i]=target-position[i];
        }
         for(int i=0;i<n;i++){
            time[i]=(double)dist[i]/speed[i];
        }
        for (int i = 0; i < n; i++) {
    
    cars.push_back({position[i], time[i]});
}
    sort(cars.begin(),cars.end());
    
    for(int i=n-1;i>=0;i--){
        if(cars[i].second>recent){
            fleet++;
            recent=cars[i].second;
        }
    }
    return fleet;
    }
};

