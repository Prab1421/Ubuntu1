#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> prims(vector<vector<pair<int,int>>>graph, vector<int>&vis, int start) {
    int cst=0;
    vector<pair<int, int>>mst;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0,start,start});
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int charge = it[0];
        int node = it[1];
        int parent = it[2];
        if(vis[node]== 1) continue;
        vis[node] = 1;
        mst.push_back({node, parent});
        cst += charge;
        for(auto it: graph[node]) {
            int adjN= it.first;
            int edgW= it.second;
            if(vis[adjN] != 1) {
                pq.push({edgW, adjN, node});
            }
        }
    }
    cout << "Minimum Cost: " << cst << endl;
    return mst;
}
int main(){
    int V,e;
    cout << "Enter the number of offices and lines: ";
    cin >> V >> e;
    vector<vector<pair<int,int>>> graph(V);
    for(int i=0; i<e; i++) {
        int u,v,w;
        cin >> u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    vector<int> vis(V,0);
    int start=0;
    vector<pair<int, int>> mst= prims(graph, vis, start);
    cout<<"Minimum spanning tree lines: "<<endl; 
    for(auto i : mst){ 
        if(i.first!=i.second) 
            cout<<i.first<<" "<<i.second<<endl; 
    } 
    return 0;
}