class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
       priority_queue<pair<int, int>> pq;
       unordered_map<int, int> cnt;
       vector<int> res;
       for(int i : nums){
            cnt[i]++;
       }
       for(auto const [val, freq] : cnt){
            pq.push({freq, val});
       }
       while(k > 0 && !pq.empty()){
            int ans = pq.top().second;
            res.push_back(ans);
            pq.pop();
            k--;
       }
       
        return res;
    }
};
