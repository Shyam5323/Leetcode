class Solution {
public:

    vector<int> frequencySort(vector<int>& nums) {
            
        unordered_map<int,int> mp;
        for(int i : nums) {
            mp[i] ++;
        }
        auto compare = [&mp](int num1, int num2) {
            if (mp[num1] == mp[num2])
                return num1 > num2; 
            return mp[num1] < mp[num2]; 
        };
        sort(nums.begin(), nums.end(), compare);
        return nums;

    }
};