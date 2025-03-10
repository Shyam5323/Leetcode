class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        auto f = [&](int k) -> long long {
            long long ans = 0;
            int l = 0, consonantCount = 0;
            unordered_map<char, int> vowelCount;
            
            for (char c : word) {
                if (isVowel(c)) {
                    vowelCount[c]++;
                } else {
                    consonantCount++;
                }
                
                // Shrink window from left while conditions are met
                while (consonantCount >= k && vowelCount.size() == 5) {
                    char leftChar = word[l++];
                    if (isVowel(leftChar)) {
                        if (--vowelCount[leftChar] == 0) {
                            vowelCount.erase(leftChar);
                        }
                    } else {
                        consonantCount--;
                    }
                }
                
                // Add number of valid starting positions
                ans += l;
            }
            return ans;
        };
        
        // Count substrings with exactly k consonants by using the difference
        return f(k) - f(k + 1);
    }
    
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
