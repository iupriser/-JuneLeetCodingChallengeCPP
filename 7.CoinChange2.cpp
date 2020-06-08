class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return cc(coins,0,amount,dp);
    }
    
    int cc(vector<int>&coins, int i, int amount, vector<vector<int>>&dp) {
        if(amount == 0) return 1;
        if(amount < 0 || i == coins.size()) return 0;
        if(dp[i][amount] != -1) return dp[i][amount];
        
        return dp[i][amount] = cc(coins, i, amount - coins[i], dp) + cc(coins, i + 1, amount, dp);
    }
};