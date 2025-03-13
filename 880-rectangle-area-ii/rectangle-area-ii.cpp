class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        const int MOD = 1e9 + 7;
        set<int> x;
        set<int> y;
        for(auto r : rectangles) {
            x.insert(r[0]);
            x.insert(r[2]);
            y.insert(r[1]);
            y.insert(r[3]);
        }
        unordered_map<int, int> mpx;
        int index = 0;
        unordered_map<int, int> mpy;
        for(auto it : x) {
            mpx[it] = index++;
        }
        index = 0;
        for(auto it : y) mpy[it] = index++;

        vector<int> xv(x.begin(), x.end());
        vector<int> yv(y.begin(), y.end());

        vector<vector<bool>> vis(x.size(), vector<bool>(y.size() , false));
        long long ans = 0;
        for(auto v : rectangles) {
            for(int startx = mpx[v[0]] ; startx< mpx[v[2]]; startx++) {
                for(int starty = mpy[v[1]]; starty < mpy[v[3]]; starty++) {
                    if(!vis[startx][starty]) {
                        vis[startx][starty] = true;
                        long long width = xv[startx + 1] - xv[startx];
                        long long height = yv[starty+1] - yv[starty];
                        ans += (width * height)%MOD;
                        ans %= MOD;
                    }
                }
            } 
        }
        return (int)ans;
    }
};