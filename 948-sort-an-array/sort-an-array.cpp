

class Solution {
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        int maxE = *max_element(nums.begin(), nums.end());
        int minE = *min_element(nums.begin(), nums.end());

        std::vector<int> arr(maxE - minE + 1);
        for(int i : nums) {
            arr[i - minE]++;
        }
        
        std::vector<int> ans;
        for(int i = 0; i < arr.size(); i++) {
            while(arr[i] > 0) {
                ans.push_back(i + minE); 
                arr[i]--;
            }
        }
        return ans;
    }
};
