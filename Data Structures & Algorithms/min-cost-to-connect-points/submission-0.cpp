class Solution {
public:
    struct Edge{
        int u, v, w;
        bool operator<(const Edge& other) const{
            return w < other.w;
        }
    };
    struct DSU{
        vector<int> parent;
        vector<int> rank;
        DSU(int n){
            parent.resize(n);
            rank.assign(n, 0);
            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
        }
        int find(int i){
            if(parent[i] == i) return i;
            return parent[i] = find(parent[i]);
        }
        bool unite(int i, int j){
            int root_i = find(i);
            int root_j = find(j);
            if(root_i != root_j){
                if(rank[root_i] < rank[root_j]){
                    parent[root_i] = root_j;
                }
                else if(rank[root_j] < rank[root_i]){
                    parent[root_j] = root_i;
                }
                else{
                    parent[root_i] = root_j;
                    rank[root_j]++;
                }
                return true;
            }
            return false;
        }
    };
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edge> edges;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int dist =abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                edges.push_back({i, j, dist});
            }
        }
        sort(edges.begin(), edges.end());
        DSU dsu(n);
        int totalcost = 0;
        int edgesUsed = 0;
        for(const auto& edge : edges){
            if(dsu.unite(edge.u, edge.v)){
                totalcost += edge.w;
                edgesUsed++;
            }
            if(edgesUsed == n-1) break;
        }
        return totalcost;
    }
};
