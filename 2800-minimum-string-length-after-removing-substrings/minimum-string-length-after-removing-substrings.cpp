class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        int count = 0;
        for(char c : s ){
             if(c == 'B') {
                if(!st.empty() && st.top() == 'A') {
                    count+=2;
                    st.pop();
                }else {
                st.push(c);
            }
            }
            else if(c == 'D') {
                if(!st.empty() && st.top() == 'C') {
                    count+=2;
                    st.pop();
                }else {
                st.push(c);
            }
            } else {
                st.push(c);
            }
        }
        return s.length() - count;
    }
};