class Solution {
public:
    bool canJump(vector<int>& nums) {
       int goal = nums.size() - 1;
       int n = nums.size();
       for(int i = n -2; i >= 0; i--){
        if(i + nums[i] >= goal){
            goal = i;
        }
       }
       return goal == 0;
    }
};
