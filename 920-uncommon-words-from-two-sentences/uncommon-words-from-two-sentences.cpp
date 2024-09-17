class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordCount;
        vector<string> result;
        stringstream ss(s1 + " " + s2);  // Combine both sentences with a space in between
        string word;
        
        // Split words from the combined sentences and count their occurrences
        while (ss >> word) {
            wordCount[word]++;
        }
        
        // Collect words that appear exactly once
        for (const auto& entry : wordCount) {
            if (entry.second == 1) {
                result.push_back(entry.first);
            }
        }
        
        return result;
    }
};
