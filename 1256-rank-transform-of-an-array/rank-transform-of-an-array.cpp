class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,vector<int>> mp;
        for(int i = 0; i<arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }
        sort(arr.begin(), arr.end());
        int rank = 1;
        vector<int> res(arr.size());
        for(int i = 0; i<arr.size(); i++) {
            while(i+1 < arr.size() && arr[i] == arr[i+1]) {
                res[mp[arr[i]].back()] = rank;
                mp[arr[i]].pop_back();
                i++;
            }
            res[mp[arr[i]].back()] = rank++;
        }
        return res;
    }
};