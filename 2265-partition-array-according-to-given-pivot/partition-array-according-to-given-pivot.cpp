class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smaller;
        vector<int> greater;
        int count = 0;
        for(int i : nums) {
            if(i < pivot) {
                smaller.push_back(i);
            }
            else if(i > pivot) {
                greater.push_back(i);
            }
            else {
                count++;
            }
        }
        vector<int> ans;
        for(int i : smaller) {
            ans.push_back(i);
        }
        for(int i = 0; i<count; i++) {
            ans.push_back(pivot);
        }
        for(int i : greater) {
            ans.push_back(i);
        }
        return ans;
    }
};