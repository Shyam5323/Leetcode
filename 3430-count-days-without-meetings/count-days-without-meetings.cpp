class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int last = meetings[0][1];
        int count = 0;
        if(meetings[0][0] > 1) {
            count+=meetings[0][0]-1;
        }
        for(int i = 1; i<meetings.size(); i++) {
            vector<int> meeting = meetings[i];
            int start = meeting[0];
            int end = meeting[1];
            if(start > last) {
                count += start - last - 1;
            }
            last = max(last, end);
        }
        count += days - last;
        return count;
    }
};