class Solution {
public:
    bool isPrefixAndSuffix(string str1, string str2) {
        if((str2.substr(0, str1.length()) == str2.substr(str2.length() - str1.length() , str1.length())) && (str1 == str2.substr(0, str1.length()))) {
            return true;
        }
        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for(int i = 0; i<words.size(); i++) {
            for(int j = i+1; j<words.size(); j++) {
                if(i != j && words[i].size() <= words[j].size() && isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        return count;
    }
};