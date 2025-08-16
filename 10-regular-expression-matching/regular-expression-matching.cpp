class Solution {
public:
    bool isMatch(string s, string p) {
        
        int m=s.size();
        int n=p.size();
        s.insert(s.begin(),'#');
        p.insert(p.begin(),'#');
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;
        for(int j=2; j<=n;j+=2){
            if(p[j]=='*' && dp[0][j-2])
                dp[0][j]=true;
        }
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s[i]==p[j] || p[j]=='.')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j]=='*'){
                    if(s[i]!=p[j-1] && p[j-1]!='.'){
                        dp[i][j]=dp[i][j-2];
                    }
                    else dp[i][j]=dp[i][j-2] || dp[i-1][j] || dp[i-1][j-2];
                }
            }
        }
        return dp[m][n];
    }
};