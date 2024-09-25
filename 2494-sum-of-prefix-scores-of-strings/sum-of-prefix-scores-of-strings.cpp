class Solution {
public:
struct TrieNode {
    TrieNode* child[26];
    int numberOfWords = 0;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};

vector<int> sumPrefixScores(vector<string>& words) {
    TrieNode* root = new TrieNode();
    for(string word : words) {
        TrieNode* curr = root;
        for(char c : word) {
            if(curr->child[c - 'a'] != nullptr) {
                curr = curr->child[c - 'a'];
            }
            else {
                curr->child[c - 'a'] = new TrieNode();
                curr = curr->child[c - 'a'];
            }
            curr->numberOfWords++;
        }
        
    }
    vector<int> ans;
    for(string word : words) {
        TrieNode* curr = root;
        int count = 0;
        for(char c : word) {
            curr = curr->child[c-'a'];
            count += curr->numberOfWords;
        }
        ans.push_back(count);
    }
    return ans;
    
}

};