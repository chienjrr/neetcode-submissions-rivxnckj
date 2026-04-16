class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& d){
        if(i <0) return 0;
        if(i == 0)return nums[0];
        if(d[i] != -1) return d[i];
        int rob = nums[i] + solve(i-2, nums, d);
        int skip = solve(i-1, nums, d);
        return d[i] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n ==0) return 0;
        vector<int> d(n, -1);
        return solve(nums.size()-1, nums, d);
    }
};
