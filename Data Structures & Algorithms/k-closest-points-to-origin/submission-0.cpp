class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> ans;
        for(auto& p : points){
            int d = p[0]*p[0] + p[1]*p[1];
            ans.push({d, p});
            if(ans.size() > k) ans.pop();
        }
        vector<vector<int>> res;
        while(!ans.empty()){
            res.push_back(ans.top().second);
            ans.pop();
        }
        return res;
    }
};
