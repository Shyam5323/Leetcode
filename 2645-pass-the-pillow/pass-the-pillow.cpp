class Solution {
public:
    int passThePillow(int n, int time) {
        int fullRounds = time / (n - 1);

        int extraTime = time % (n - 1);

        if (fullRounds % 2 == 0) {
            return extraTime + 1;  // Position when moving forward
        } else {
            return n - extraTime;  // Position when moving backward
        }
    }
};