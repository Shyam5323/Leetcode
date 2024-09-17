class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> xors; 
        xors.push_back(arr[0]); 
        
        for(int i = 1; i < arr.size(); i++) {
            xors.push_back(xors[i-1] ^ arr[i]);
        }
        
        vector<int> ans;
        
        for(const auto& query : queries) {
            int left = query[0];
            int right = query[1];
            
            if (left == 0) {
                ans.push_back(xors[right]); 
            } else {
                ans.push_back(xors[right] ^ xors[left-1]); 
            }
        }
        
        return ans;
    }
};
