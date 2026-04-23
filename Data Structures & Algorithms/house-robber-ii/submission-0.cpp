class Solution {
public:
    int dfs(int i, vector<int>& nums, vector<int>&d, int start){
        if(i < start) return 0;
        if(i == start) return nums[start];
        if(d[i] != -1) return d[i];
        int rob = nums[i] + dfs(i-2, nums, d, start);
        int skip = dfs(i -1, nums, d, start);
        return d[i] = max(rob, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n ==1) return nums[0];
        vector<int> d1(n, -1);
        vector<int> d2(n, -1);
        return max(dfs(nums.size()-1, nums, d1, 1), dfs(nums.size()-2, nums, d2, 0));
    }
};
