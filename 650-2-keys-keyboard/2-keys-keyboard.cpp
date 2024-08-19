class Solution {
public:
   int minSteps(int n) {
       int ans = 0, sqroot = sqrt(n);
       for(int d = 2; d <= sqroot; d++) {
           while(n % d == 0) {
               ans += d;
               n /= d;
           }
       }
       if(n > 1)
           ans += n;
       return ans;
   }
};