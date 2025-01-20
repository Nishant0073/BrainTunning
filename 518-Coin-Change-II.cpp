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
        vector<vector<int>> dp(amount+1,vector<int>(n,-1));
        return solve(amount,coins.size()-1,coins,dp);

    }
};
