class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i : nums) {
            mp[i]++;
            if(mp[i] == nums.size()/3 + 1) {
                ans.push_back(i);
            } 
        }
        return ans;
    }
};