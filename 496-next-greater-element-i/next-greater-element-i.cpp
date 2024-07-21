class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        stack<int> st;
        unordered_map<int,int> mp;
        for(int i = b.size() - 1; i>=0; i--) {
            while(!st.empty() && st.top() < b[i]) {
                st.pop();
            }
            if(!st.empty()) {
                mp[b[i]] = st.top();
            }
            else {
                mp[b[i]]= -1;
            }
            st.push(b[i]);
        }
        vector<int> ans;
        for(int i : a) {
            ans.push_back(mp[i]);
        }
        return ans;
    }
};