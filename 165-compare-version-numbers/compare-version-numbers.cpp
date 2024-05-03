class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1 = 0;
        int v2 = 0;
        while (v1 < version1.length() || v2 < version2.length()) {
            string currVer1 = "";
            string currVer2 = "";
            while (v1 < version1.length() && version1[v1] != '.') {
                currVer1 += version1[v1++];
            }
            while (v2 < version2.length() && version2[v2] != '.') {
                currVer2 += version2[v2++];
            }
            cout<<currVer1 << " ";
            cout<<currVer2 << " ";
            int ver1 = currVer1.empty() ? 0 : stoi(currVer1);
            int ver2 = currVer2.empty() ? 0 : stoi(currVer2);
            if (ver1 > ver2) {
                return 1;
            } 
            if (ver2 > ver1) {
                return -1;
            }
            v1++;
            v2++;
        }
        return 0;
    }
};
