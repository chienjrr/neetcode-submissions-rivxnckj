class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto& n : nums){
            pq.push(n);
        }
        int count = 0;
        int ans = -999;
        while(count < k){
            ans = pq.top();
            pq.pop();
            count++;
        }
        return ans;
    }
};
