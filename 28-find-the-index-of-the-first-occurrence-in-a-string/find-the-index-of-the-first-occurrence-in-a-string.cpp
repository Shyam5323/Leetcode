class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int hLen = haystack.length();
        int nLen = needle.length();
        
        int i = 0; 
        int j = 0; 
        
        while (i < hLen) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
                if (j == nLen) {
                    return i - j; 
                }
            } else {
                i = i - j + 1; 
                j = 0; 
            }
        }
        
        return -1; 
    }
};
