class Solution {
public:
    int convert(vector<int>& mapping, vector<int>& nums, int idx) {
        int num = nums[idx]; // 0
        int ans = 0;
        int mul = 1;
        if(num == 0) {
            return mapping[0];
        }
        while (num > 0) {
            int m = num % 10;
            int map = mapping[m];
            ans = ans + map * mul;
            mul = mul * 10;
            num = num / 10;
        }

        return ans;
    }
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> mp(nums.size());
        for(int i = 0; i<nums.size(); i++) {
            mp[i].first = nums[i];
            mp[i].second = convert(mapping, nums, i);
        } 
        auto compare = [](auto pair1, auto pair2) {
            return pair1.second < pair2.second;
        };
        sort(mp.begin(), mp.end(), compare);
        vector<int> ans;
        for(auto pair : mp) {
            ans.push_back(pair.first);
        }
        return ans;
    }
};