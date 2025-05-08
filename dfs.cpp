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
    void add(int p, int q) {
        adj[p].push_back(q);
    }
    vector<int> dfs(int start, int target) {
        vector<bool> vis(V, false);
        stack<int> s;
        vector<int> traversal;
        s.push(start);
        while(!s.empty()) {
            int cur = s.top();
            s.pop();
            if(!vis[cur]) {
                vis[cur]=true;
                traversal.push_back(cur);
                if(cur==target) {
                    cout<<"Target "<<target<< "found in DFS.\n";
                }
                for(auto it=adj[cur].rbegin(); it!= adj[cur].rend(); it++) {
                    if(!vis[*it]) {
                        s.push(*it);
                    }
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
    cout << "DFS..\n";
    vector<int> dfs=g.dfs(start, target);
    for(int n: dfs) {
        cout<<n << " ";
    }
    cout<<endl;
    return 0;
}