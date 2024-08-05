class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mp;
        for(string i : arr) {
            mp[i]++;
        }
        int k1 = 0;
        for(string i : arr) {
            if(mp[i] == 1) {
                k1++;
                if(k == k1) {
                    return i;
                }
            }
        }
        return "";
    }
};