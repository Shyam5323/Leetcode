class Solution {
public:

    int largestArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int maxArea = 0;
        for(int i=0; i<heights.size(); i++) {
            int start = i;
            while(!st.empty() && st.top().second > heights[i]) {
                pair<int,int> curr = st.top();
                st.pop();
                int height = curr.second;
                int index = curr.first;
                int area = (height) * (i - index);
                maxArea = max(maxArea , area);
                start = index;
            }
            st.push({start , heights[i]});
        }
        while(!st.empty()) {
            pair<int,int> curr = st.top();
            st.pop();
            int height = curr.second;
            int index = curr.first;
            int area = height * (heights.size() - index );
            maxArea = max(maxArea, area);
        }
        // cout<<maxArea<<endl;
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int col = matrix[0].size();
        int maxArea = 0;
        vector<int> heights(col,0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<col; j++) {
                if(matrix[i][j] == '0') {
                    heights[j] = 0;
                }
                else {
                    heights[j]++;
                }
            }
            for(int i : heights) {
                cout<<i<<" ";
            }
            cout<<endl;
            maxArea = max(maxArea , largestArea(heights));
            
        }
        return maxArea;
    }
};