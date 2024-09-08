class Solution {
public:
    int jump(vector<int>& nums) {
      int jumps, l ,r ;
      jumps = l = r = 0;
      
      while(r < nums.size()-1){
        int furthest = 0;
        for(int i = l ; i <=r ; i++){
            furthest = max(i+nums[i],furthest);
        }
        l = r+1;
        r = furthest;
        jumps++;
      }  
      return jumps;
    }
};
auto init = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();