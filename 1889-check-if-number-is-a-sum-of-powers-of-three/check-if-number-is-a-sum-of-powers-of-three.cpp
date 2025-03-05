class Solution {
public:
    bool checkPowersOfThree(int n) {
        int highest = log(n) / log(3);

        cout<<highest;
        while(n > 0 && highest >= 0) {
            if(pow(3, highest) <= n) {
                n -= pow(3, highest);
            }
            highest--;
            
        }
        if(n == 0) return true;
        return false;
    }
};