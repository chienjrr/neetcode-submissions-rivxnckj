class Solution {
public:
    int uniquePaths(int m, int n) {
       int step = m + n -2;
       int k = min(n-1, m-1);
       long long ans = 1;
       for(int i = 1; i <= k ; i++){
        ans = ans * (step - k + i) / i ;
       }
       return ans;
    }
};
