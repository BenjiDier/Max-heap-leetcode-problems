#include <vector>
#include <queue>
// Solution to Last Stone Weight leetcode problem.
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end()); // Use a priority queue as its the same as max heap 

        while (pq.size() > 1) {
            int y = pq.top(); 
            pq.pop(); // largest stone
            int x = pq.top(); 
            pq.pop(); // second largest stone

            if (y != x) {
                pq.push(y - x);
            }
        }

        if (pq.empty())
            return 0;
        else return pq.top();
    }
};
