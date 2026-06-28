#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Step 1: Initialize two candidates and their respective vote counters
        int element1 = 0, element2 = 0;
        int count1 = 0, count2 = 0;
        
        // --- FIRST PASS: Find the top two potential candidates ---
        for (int i = 0; i < nums.size(); i++) {
            // Rule A: If current number matches candidate 1, increment its count
            if (nums[i] == element1) {
                count1++;
            } 
            // Rule B: If current number matches candidate 2, increment its count
            else if (nums[i] == element2) {
                count2++;
            } 
            // Rule C: If candidate 1 slot is free, claim it and reset count
            else if (count1 == 0) {
                element1 = nums[i];
                count1 = 1;
            } 
            // Rule D: If candidate 2 slot is free, claim it and reset count
            else if (count2 == 0) {
                element2 = nums[i];
                count2 = 1;
            } 
            // Rule E: If it matches neither candidate and slots are full, decrease both votes
            else {
                count1--;
                count2--;
            }
        }
        
        // --- SECOND PASS: Verify if the candidates actually meet the > n/3 condition ---
        count1 = 0; 
        count2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == element1) {
                count1++;
            } 
            // 'else if' handles edge cases where element1 might equal element2
            else if (nums[i] == element2) { 
                count2++;
            }
        }
        
        // Define the final return vector and the threshold constraint
        vector<int> result;
        int threshold = nums.size() / 3;
        
        // If a candidate strictly exceeds floor(n / 3) occurrences, add it to the final result
        if (count1 > threshold) result.push_back(element1);
        if (count2 > threshold) result.push_back(element2);
        
        return result;
    }
};

