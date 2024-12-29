class Solution {
public:
        long long numberOfSubsequences(vector<int>& nums) {
        unordered_map<double, long long> freq;
        long long ans = 0, q = 2;
        for(int r = 4; r < nums.size(); ++r){
            for(; q < r-1; ++q){
                for(int p = 0; p < q-1; ++p) freq[(double)nums[p]/(double)nums[q]]++;
            }
            for(int s = r + 2; s < nums.size(); ++s) ans += freq[(double)nums[s]/(double)nums[r]];
        }
        return ans;
    }
};