class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(int num : nums) {
            mp[num]++;
        }
        for (const auto& pairs : mp) {
        if (mp.find(pairs.first - 1) == mp.end()) { 
            int current_num = pairs.first;
            int temp = 1;

            while (mp.find(current_num + 1) != mp.end()) {
                current_num++;
                temp++;
            }

            ans = std::max(ans, temp);
        }
    }
        return ans;
    }
};