
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> pq;
        unordered_set<long> seen;
        pq.push(1);
        seen.insert(1);
        
        long current_ugly = 1;
        for (int i = 0; i < n; ++i) {
            current_ugly = pq.top();
            pq.pop();
            
            if (seen.insert(current_ugly * 2).second) {
                pq.push(current_ugly * 2);
            }
            if (seen.insert(current_ugly * 3).second) {
                pq.push(current_ugly * 3);
            }
            if (seen.insert(current_ugly * 5).second) {
                pq.push(current_ugly * 5);
            }
        }
        
        return current_ugly;
    }
};
