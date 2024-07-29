class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        for(int i=0; i<rating.size(); i++){
            for(int j=i; j<rating.size(); j++) {
                for(int k =j; k<rating.size();  k++) {
                    if((rating[i] > rating[j] && rating[j] > rating[k]) || (rating[i] < rating[j] && rating[j] < rating[k])) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};