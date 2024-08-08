class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        ans.push_back({rStart, cStart});
        int rCurr = rStart;
        int cCurr = cStart;
        int loop = 0;
        while(ans.size() < rows * cols) {
            loop++;
            for(int i = 0; i<loop; i++) {
                cCurr++;
                if(rCurr >= 0 && rCurr<rows && cCurr>=0 && cCurr<cols) {
                    ans.push_back({rCurr, cCurr});
                }
            }

            for(int i = 0; i<loop; i++) {
                rCurr++;
                if(rCurr >= 0 && rCurr<rows && cCurr>=0 && cCurr<cols) {
                    ans.push_back({rCurr, cCurr});
                }
            }
            loop++;
            for(int i = 0; i<loop; i++) {
                cCurr--;
                if(rCurr >= 0 && rCurr<rows && cCurr>=0 && cCurr<cols) {
                    ans.push_back({rCurr, cCurr});
                }
            }
            for(int i = 0; i<loop; i++) {
                rCurr--;
                if(rCurr >= 0 && rCurr<rows && cCurr>=0 && cCurr<cols) {
                    ans.push_back({rCurr, cCurr});
                }
            }
        }
        return ans;
    }
};