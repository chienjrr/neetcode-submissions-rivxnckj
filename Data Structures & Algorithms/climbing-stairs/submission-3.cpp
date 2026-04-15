class Solution {
public:
    int d[46] = {0};
    int climbStairs(int n) {
      if( n== 1) return 1;
      else if(n == 2) return 2;
      else if(d[n] != 0) return d[n];
      else{
        d[n] = climbStairs(n-1) + climbStairs(n-2);
        return d[n];
      }
    }
};
