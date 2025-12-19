#include<unordered_map>
#include<queue>
// Top K Frequent Elements problem
// i think i got the hang of heaps now...

// first : Put all values a frequency hash map
// second : Put all frequencies into max heap to extract all top values
// finally : Display the top value 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> frequency_map; // Map to store frequency of occuring nums
        for(int num : nums){ // for num in nums
            frequency_map[num]++; // Increments the frequency of the num in the map.
        }

        priority_queue<pair<int, int>> top_frequencies; // Priority queue to pull the greatest frequency from the map.
        for (auto& [num, freq] : frequency_map){
            top_frequencies.push({freq,num});  // Make sure to push frequencies first, so that it will push the greatest frequencies first
        }
        vector<int> result;
        while (k--) { // Use size to push all frequencies to result.
            result.push_back(top_frequencies.top().second);
            top_frequencies.pop();
        }
        return result;
    }
};
