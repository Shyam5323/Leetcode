class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0; // If needle is empty, return 0
        int hLen = haystack.length();
        int nLen = needle.length();
        
        int i = 0; // Pointer for haystack
        int j = 0; // Pointer for needle
        
        while (i < hLen) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
                if (j == nLen) {
                    return i - j; // Found the needle, return the starting index
                }
            } else {
                i = i - j + 1; // Move i back to the next position after the last start position
                j = 0; // Reset j to start of the needle
            }
        }
        
        return -1; // Needle not found
    }
};
