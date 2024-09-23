

class Solution {
public:
    int recurse(string s, int index, unordered_set<string>& dict, std::unordered_map<int, int>& memo) {
        if (memo.find(index) != memo.end()) {
            return memo[index];
        }

        if (index == s.length()) {
            return 0; 
        }

        int minExtra = 1 + recurse(s, index + 1, dict, memo);

        for (int end = index; end < s.length(); ++end) {
            string substring = s.substr(index, end - index + 1);
            if (dict.find(substring) != dict.end()) {
                minExtra = std::min(minExtra, recurse(s, end + 1, dict, memo));
            }
        }

        memo[index] = minExtra;
        return minExtra;
    }

    int minExtraChar(string s, vector<string>& dictionary) {    
        unordered_set<string> dict(dictionary.begin(), dictionary.end()); 
        std::unordered_map<int, int> memo; 
        return recurse(s, 0, dict, memo);
    }
};
