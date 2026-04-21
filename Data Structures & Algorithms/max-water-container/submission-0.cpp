class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0;
        int j = n-1;
        int max_water = 0;
        int cur_water = 0;
        while(i<j){
            cur_water = (j-i) * min(heights[i], heights[j]);
            max_water = max(max_water, cur_water);
            if( heights[i] > heights[j]) j--;
            else i++;
        }
        return max_water;
    }
};
