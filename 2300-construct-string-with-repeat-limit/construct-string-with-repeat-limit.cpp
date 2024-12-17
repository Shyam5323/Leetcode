class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        string res = "";
        int last = 25; 
        
        while (last >= 0) {
            while (last >= 0 && freq[last] == 0) last--;
            if (last < 0) break; 
            
            int count = min(freq[last], repeatLimit);
            for (int i = 0; i < count; i++) {
                res += 'a' + last;
            }
            freq[last] -= count;

            if (freq[last] > 0) {
                int next = last - 1;
                while (next >= 0 && freq[next] == 0) next--;
                if (next < 0) break; 
                
                res += 'a' + next; 
                freq[next]--;    
            }
        }
        
        return res;
    }
};
