class Solution {
public:
    void insertPrefix(int i, unordered_set<int>& prefixes) {
        int t = i;
        while(t > 0) {
            prefixes.insert(t);
            t /= 10;
        }
    }
    int lengthOfnum(int i) {
        return i == 0 ? 1 : (int)log10(i) + 1;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;
        for(int i : arr1) {
            insertPrefix(i, prefixes);
        }
        int ans = 0;
        for(int i : arr2) {
            int t = i;
            int count = lengthOfnum(i);
            while(t > 0) {
                if(count < ans) {
                    break;
                }
                if(prefixes.find(t) != prefixes.end()) {
                    ans = max(ans, count);
                }
                t /= 10;
                count--;
            }
        }
        
        return ans;
    }
};
