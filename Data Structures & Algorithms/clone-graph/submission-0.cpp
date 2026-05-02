/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
/*Kiểm tra điều kiện biên: Nếu node đầu vào là null, trả về null.

Khởi tạo:

Tạo một HashMap để lưu các node đã copy: visited = { original_node : copied_node }.

Tạo bản sao của node đầu tiên và đưa vào HashMap.

Đưa node gốc vào một Queue.

Vòng lặp BFS: Trong khi Queue không trống:

Lấy node hiện tại (curr) ra khỏi Queue.

Duyệt qua tất cả các node láng giềng (neighbor) của curr:

Nếu neighbor chưa có trong HashMap:

Tạo một bản sao mới cho neighbor.

Lưu vào HashMap: visited[neighbor] = new_neighbor_copy.

Đưa neighbor (gốc) vào Queue để tiếp tục duyệt sau này.

Kết nối: Thêm bản sao của neighbor vào danh sách láng giềng của bản sao curr.

visited[curr].neighbors.add(visited[neighbor])

Kết quả: Trả về visited[node].
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;

        unordered_map<Node*, Node*> visited;
        visited[node] = new Node(node->val);
        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            for(Node* neighbor : curr->neighbors){
                if(visited.find(neighbor) == visited.end()){
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                visited[curr]->neighbors.push_back(visited[neighbor]);
            }
            
        }
        return visited[node];
    }
};
