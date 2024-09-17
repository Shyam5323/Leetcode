class Solution {
public:
    int timeToMinutes(string time) {
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3, 2));
        return hours * 60 + minutes;
    }

    int findDifference(string time1, string time2) {
        int t1 = timeToMinutes(time1);
        int t2 = timeToMinutes(time2);

        int diff = abs(t1 - t2);
        return min(diff, 1440 - diff); 
    }

    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;

        for (const string& time : timePoints) {
            minutes.push_back(timeToMinutes(time));
        }

        sort(minutes.begin(), minutes.end());

        int minDiff = INT_MAX;
        for (int i = 1; i < minutes.size(); i++) {
            minDiff = min(minDiff, minutes[i] - minutes[i-1]);
        }

        minDiff = min(minDiff, 1440 - (minutes.back() - minutes[0]));

        return minDiff;
    }
};
