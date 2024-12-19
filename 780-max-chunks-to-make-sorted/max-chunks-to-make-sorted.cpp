class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxYet =0;
        int idx = 0;
        int a = 0;
        while(idx<arr.size()){
            maxYet = max(maxYet, arr[idx]);
            if(maxYet == idx){
                a++;
                maxYet = 0;
            }
            idx++;
        }
        return a;
    }
};