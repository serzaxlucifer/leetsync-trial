class DSU {
    public:
    vector<int> parent;
    DSU(const vector<int>& p) : parent(p) {}

    int find(int x) {
        return parent[x] == x ? x : (parent[x] = find(parent[x]));
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) {
            return false;
        }

        parent[px] = py;
        return true;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {

        vector<int> initialParent(n);
        iota(initialParent.begin(), initialParent.end(), 0);
        DSU dsu(initialParent);

        int answer = INT_MAX;

        vector<vector<int>> optEdges; 
        int selectedEdges = 0;

        for (int i = 0; i < edges.size(); i++) {
            if (edges[i][3] == 1) {
                if (!dsu.unite(edges[i][0], edges[i][1])) {
                    return -1;
                }
                selectedEdges++;
                answer = min(answer, edges[i][2]);
            } else {
                optEdges.push_back(edges[i]);
            }
        }

        sort(optEdges.begin(), optEdges.end(), [](vector<int>& a, vector<int>& b){
            return a[2] > b[2];
        });

        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto &edge : optEdges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (dsu.unite(u, v)){
                selectedEdges++;
                pq.push(w);
            }
        }

        while (k-- && !pq.empty()) {
            int x = pq.top();
            pq.pop();
            answer = min(answer, 2 * x);
        }

        if (selectedEdges != n - 1) {
            return -1;
        }

        if (!pq.empty()) {
            return min(answer, pq.top());
        }


        return answer;

    }
};