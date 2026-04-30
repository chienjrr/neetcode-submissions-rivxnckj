class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    
    void backtrack(vector<int>& nums, int target, int i){
        if(target == 0){
            ans.push_back(cur);
            return;
        }
        if(target < 0 || i >= nums.size()) return;
        cur.push_back(nums[i]);
        backtrack(nums, target-nums[i], i);
        cur.pop_back();
        
        backtrack(nums, target, i+1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums, target, 0);
        return ans;

    }
};
