class Solution {
public:
    string removeOccurrences(string s, string part) {
        string curr;
        for(char c : s) {
            curr+=c;
            if(curr.length() >= part.length()) {
                if(curr.substr(curr.size() - part.size() , part.size()) == part) {
                    curr = curr.substr(0, curr.length() - part.length());
                }
            }
        }
        return curr;
    }
};