class Solution {
private:
    bool solveMem(string &s,string &p,int i,int j,vector<vector<int>> &dp)
    {
        //base case
        if(i==0 && j==0) return true;

        if(i>0 && j==0) return false;

        if(i==0 && j>0)
        {
            for(int k=1;k<=j;k++)
            {
                if(p[k-1]!='*') return false;
            }
            return true;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        //match
        if(s[i-1]==p[j-1] || p[j-1]=='?')  return dp[i][j]=solveMem(s,p,i-1,j-1,dp);
        else if(p[j-1]=='*') 
            return dp[i][j]=( solveMem(s,p,i-1,j,dp)|| solveMem(s,p,i,j-1,dp));
        else return false;
    }    

public:
    bool isMatch(string s, string p) {

         int n=s.length();
         int m=p.length();

         vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
         return solveMem(s,p,n,m,dp);
    }

};