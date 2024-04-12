class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        for(int start = 0; start<height.size() - 1; start++) {
            int sum = 0;
            int maxE = INT_MIN;
            int found = 0;
            if(height[start] <= height[start+1]) {
                continue;
            }
            for(int end = start+1; end<height.size(); end++) {
                if(height[end] < height[start]) {
                    sum += height[start] - height[end];
                }
                else if(height[end] >= height[start]) {
                    ans+=sum;
                    found = 1;
                    start = end - 1;
                    break;
                }
                maxE = max(maxE, height[end]);
            }
            if(found == 0) {
                sum = 0;
                for(int end = start + 1; end<height.size(); end++) {
                    if(height[end] < height[start]) {
                        sum += maxE - height[end];
                    }
                    if(height[end] == maxE) {
                        cout<<sum<<" "<<end<<endl;
                        ans+=sum;
                        start = end - 1;
                        break;
                    }

                }
            }
        }
        return ans;
    }
};