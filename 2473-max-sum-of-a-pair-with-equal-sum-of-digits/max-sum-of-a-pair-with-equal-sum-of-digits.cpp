class Solution {
public:
    int countDigitSum(int num) {
        int sum = 0;
        while(num > 0) {
            sum += num%10;
            num/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
       unordered_map<int, priority_queue<int>> mp; 
        unordered_set<int> digitSum;

        for (int i : nums) {
            int d = countDigitSum(i);
            digitSum.insert(d);
            mp[d].push(i);
        }

        int ans = -1;
        for (int d : digitSum) {
            if (mp[d].size() < 2) continue; 

            int first = mp[d].top(); mp[d].pop();
            int second = mp[d].top();         

            ans = max(ans, first + second);
        }

        return ans;
        }
};