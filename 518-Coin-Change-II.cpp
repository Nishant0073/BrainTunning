class Solution {
public:
    int solve(int amount,int i,vector<int> &coins,vector<vector<int>> &dp){

        if(amount==0)
            return 1;
        if(i<0)
            return 0;

        int n1 = 0;
        int n2 = 0;
        if(dp[amount][i]!=-1)
            return dp[amount][i];

        if(amount - coins[i]>=0)
            n1 = solve(amount-coins[i],i,coins,dp);
        n2 = solve(amount,i-1,coins,dp);
        return dp[amount][i] = n1+n2;

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        //vector<vector<int>> dp(amount+1,vector<int>(n+1,-1));
        //return solve(amount,coins.size()-1,coins,dp);
        vector<vector<uint64_t>> dp(n+1,vector<uint64_t>(amount+1,0));

        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
               if(j-coins[i-1]>=0){
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
               }
               else{
                  dp[i][j]+=dp[i-1][j];
               }
            }
        }
        return dp[n][amount];

    }
};
