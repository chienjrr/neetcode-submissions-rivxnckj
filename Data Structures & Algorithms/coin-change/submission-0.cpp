class Solution {
public:
    int d[10001];

    int dfs(vector<int>& coins, int amount){
        if(amount == 0) return 0;
        if(amount < 0) return 1e9;
        if(d[amount] != -1) return d[amount];
        
        int min_coin = 1e9;
        
        for(int coin : coins){
            int res = dfs(coins, amount-coin);
            if(res != 1e9){
                min_coin = min(min_coin, 1 + res);
            }
        }
        return d[amount] = min_coin;
    }

    int coinChange(vector<int>& coins, int amount) {
        fill(begin(d), end(d), -1);
        int result = dfs(coins, amount);
        return (result >= 1e9) ? -1 : result;
    }
};
