class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    void backtrack(vector<int>& nums, int i){
        if(i == nums.size()){
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[i]);
        backtrack(nums, i+1);

        cur.pop_back();
        backtrack(nums, i +1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};
