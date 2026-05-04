class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> car;
        for(int i = 0; i<position.size(); i++){
            car.push_back({position[i], speed[i]});
        }
        sort(car.begin(), car.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
        });
        stack<double> st;
        double time_1 = (target - car[0].first) / car[0].second;
        st.push(time_1);
        for(int i = 1; i < car.size();i++){
            double time = (double)(target - car[i].first) / car[i].second;
            if(time > st.top() || st.empty()) 
            {
                st.push(time);
            }
        }
        return st.size();

    }
};
