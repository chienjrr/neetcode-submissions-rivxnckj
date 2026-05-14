class Solution {
public:
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& cur, vector<vector<int>>& res){
        if(cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }
        for(int i = 0; i< nums.size(); i++){
            if(!used[i]){
                used[i] = true;
                cur.push_back(nums[i]);
                backtrack(nums, used, cur, res);
                used[i] = false;
                cur.pop_back();
            }

        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> used(n, false);
        vector<int> cur;
        vector<vector<int>> res;
        backtrack(nums, used, cur, res);
        return res;
    }
};
