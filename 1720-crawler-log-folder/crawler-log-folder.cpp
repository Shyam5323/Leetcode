class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        for(string log : logs) {
            if(log == "../") {
                count = max(0 , count-1);
            }
            else if(log != "./") {
                count++;
            }
        }
        return count;
    }
};