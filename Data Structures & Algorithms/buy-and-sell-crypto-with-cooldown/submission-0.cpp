#include <bits/stdc++.h>
class Solution {
public:
    int cache[5001][2] ;
    int solve(int i, int buying, vector<int>& prices){
        if(i >= prices.size()) return 0;
        if(cache[i][buying] != -1) return cache[i][buying];
        if(buying){
            int buy = -prices[i] + solve(i+1, 0, prices);
            int skip = solve(i+1, 1, prices);
            cache[i][buying] = max(buy, skip);
        }
        else{
            int sell = solve(i+2, 1, prices) + prices[i];
            int skip = solve(i+1,0, prices );
            cache[i][buying] = max(sell, skip);
        }
        return cache[i][buying];
    }

    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        memset(cache, -1, sizeof(cache));
        return solve(0, true, prices);
    }
};
