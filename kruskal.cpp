#include<bits/stdc++.h> 
using namespace std; 
class UnionFind { 
    public: 
    vector<int> parent, rank; 
    UnionFind(int n) { 
        parent.resize(n); 
        rank.resize(n); 
        for(int i=0; i<n; i++) { 
            rank[i] = 0; 
            parent[i] = i; 
        } 
    } 
    int find(int x) { 
        if(x != parent[x]) { 
            parent[x] = find(parent[x]); 
        } 
        return parent[x]; 
    } 
    void unite(int x, int y) { 
        int X = find(x); 
        int Y = find(y); 
        if(X != Y) { 
            if(rank[X] < rank[Y]) { 
                parent[X] = Y; 
            } else if(rank[Y] < rank[X]) { 
                parent[Y] = X; 
            } else { 
                parent[X] = Y; 
                rank[X]++; 
            } 
        } 
    } 
}; 
vector<pair<int, pair<int, int>>> kruskal(vector<pair<int, pair<int, int>>> &edges, int V) {
    vector<pair<int, pair<int, int>>> mst; 
    sort(edges.begin(), edges.end()); 
    UnionFind uf(V); 
    for(auto edge: edges) { 
        int weight = edge.first; 
        int u = edge.second.first; 
        int v = edge.second.second; 
        if(uf.find(u) != uf.find(v)) { 
            mst.push_back({weight, {u, v}}); 
            uf.unite(u, v); 
        } 
    } 
    return mst; 
} 
int main() { 
    int V, E; 
    cout << "Enter the number of vertices and edges:- "; 
    cin >> V >> E; 
    vector<pair<int, pair<int, int>>> edges(E); 
    cout << "Enter the edges:- "; 
    for(int i=0; i< E; i++) { 
        int u, v, w; 
        cin >> u >> v >> w; 
        edges[i] = {w, {u, v}}; 
    } 
    vector<pair<int, pair<int, int>>> mst = kruskal(edges, V); 
    int totalCost = 0; 
    cout << "Minimum spanning tree lines: " << endl; 
    for(auto edge : mst) { 
        totalCost += edge.first; 
        cout << edge.second.first << " " << edge.second.second << endl; 
    } 
    cout << "Minimum Cost : " << totalCost << endl; 
    return 0; 
}