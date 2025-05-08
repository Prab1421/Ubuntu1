#include<bits/stdc++.h>
using namespace std;
class Graph {
    int V;
    vector<vector<int>> adj;
    public:
    Graph(int v) {
        V = v;
        adj.resize(v);
    }
    void add(int p,  int q) {
        adj[p].push_back(q);
    }
    vector<int> bfs(int start, int target) {
        vector<bool> vis(V, false);
        queue<int> q;
        vector<int> traversal;
        q.push(start);
        vis[start] = true;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            traversal.push_back(cur);
            if(cur==target) {
                cout<<"Target " << target << "found in BFS.\n";
            }
            for(int neighbor: adj[cur]) {
                if(!vis[neighbor]) {
                    vis[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return traversal;
    }
};
int main() {
    Graph g(6);
    g.add(0,1);
    g.add(0,2);
    g.add(1,3);
    g.add(1,4);
    g.add(2,5);
    int start=0;
    int target=5;
    cout<<"BFS Traversal:\n";
    vector<int> bfs= g.bfs(start, target);
    for(int node: bfs) {
        cout<< node<< " ";
    }
    cout<< endl;
    return 0;
}

