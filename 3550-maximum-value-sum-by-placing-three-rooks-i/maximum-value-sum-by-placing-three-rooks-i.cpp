#define ll long long
class Solution {
public:
    ll maximumValueSum(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<pair<int, int>>>v(n);
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                v[i].push_back({board[i][j], j});
            }
            sort(v[i].rbegin(), v[i].rend());
            while(v[i].size() > 3) v[i].pop_back();
        }
        ll ans = -3e9;
        for(int i1 = 0; i1 < n; i1 ++){
            for(int j1 = 0; j1 < 3; j1 ++){
                int val1 = v[i1][j1].first;
                int col1 = v[i1][j1].second;
                for(int i2 = i1 + 1; i2 < n; i2 ++){
                    for(int j2 = 0; j2 < 3; j2 ++){
                        int val2 = v[i2][j2].first;
                        int col2 = v[i2][j2].second;
                        for(int i3 = i2 + 1; i3 < n; i3 ++){
                            for(int j3 = 0; j3 < 3; j3 ++){
                                int val3 = v[i3][j3].first;
                                int col3 = v[i3][j3].second;
                                if(col1 != col2 && col2 != col3 && col1 != col3){
                                    ll sum = (ll)val1 + (ll)val2 + (ll)val3;
                                    ans = max(ans, sum);
                                }
                            }
                        } 
                    }
                }  
            }
        }
        return ans;
    }
};