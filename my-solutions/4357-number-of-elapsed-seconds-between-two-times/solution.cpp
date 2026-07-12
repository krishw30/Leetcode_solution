class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int start_hour=std::stoi(startTime.substr(0, 2));
        int start_min=std::stoi(startTime.substr(3, 2));
        int start_sec=std::stoi(startTime.substr(6, 2));
        int start=(3600*start_hour)+(60*start_min)+start_sec;

        int end_hour=std::stoi(endTime.substr(0, 2));
        int end_min=std::stoi(endTime.substr(3, 2));
        int end_sec=std::stoi(endTime.substr(6, 2));
        int end=(3600*end_hour)+(60*end_min)+end_sec;

        return end-start;

        
        
    }
};
