class Solution {
public:
    int stepsBetweenChar(int ringIndex, int keyIndex, string ring) {
        int step1 = abs(ringIndex - keyIndex);
        int step2 = ring.length() - step1;
        return min(step1,step2);
    }

    int findMinStep(string ring, string key, int minSteps, int keyIndex, int ringIndex ,  unordered_map<int, unordered_map<int, int>> &dp ) {
        if(keyIndex == key.length()) {
            return 0;
        }
        if(dp[ringIndex][keyIndex])  {
            return dp[ringIndex][keyIndex];
        }
        for(int i = 0; i<ring.length(); i++) {
            if(key[keyIndex] == ring[i]) {
                int steps = stepsBetweenChar(ringIndex, i, ring) + 1 +findMinStep(ring,key,INT_MAX, keyIndex+1, i, dp);
                minSteps = min(minSteps, steps);
                dp[ringIndex][keyIndex] = minSteps;
            }
        }
        return minSteps;
    }
    int findRotateSteps(string ring, string key) {
        unordered_map<int, unordered_map<int, int>> dp;
        return findMinStep(ring,key, INT_MAX, 0, 0 ,dp);
    }
    
};