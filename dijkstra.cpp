#include<bits/stdc++.h> 
using namespace std; 
 
void dijkstra(vector<vector<pair<int, int>>> &graph, int start, vector<int> &vis,vector<int> &pred) { 
    vis[start] = 0; 
    set<pair<int,int>>s; 
    s.insert({0, start}); 
    while(!s.empty()) { 
        auto it = *(s.begin()); 
        int u = it.second; 
        int d = it.first; 
        s.erase(s.begin()); 
        for(auto it: graph[u]) { 
            int v = it.first; 
            int dis = it.second; 
            if(d + dis < vis[v]) { 
                if (vis[v] != INT_MAX) { 
                    s.erase({vis[v], v}); 
                } 
                vis[v] = d + dis; 
                s.insert({vis[v], v}); 
                pred[v] = u; 
            } 
        } 
    } 
} 
void print(vector<int>& pred, int s, int des) { 
    if(s == des) { 
        cout << s << " "; 
        return; 
    } 
    print(pred,s,pred[des]); 
    cout << des << " "; 
} 
int main() {
    int V, E; 
    cout << "Enter the number of vertices and edges:- "; 
    cin >> V >> E; 
    vector<vector<pair<int, int>>> graph(V); 
    vector<int>predecessor (V,-1); 
    cout << "Enter the edges:- "; 
    for(int i=0; i< E; i++) { 
        int u, v, w; 
        cin >> u >> v >> w; 
        graph[u].push_back({v, w});   
        graph[v].push_back({u, w}); 
    } 
    int s, des; 
    cout << "Enter starting city and des city: "; 
    cin >> s >> des; 
    vector<int> distance(V, INT_MAX); 
    dijkstra(graph, s, distance,predecessor); 
    if (distance[des] != INT_MAX) { 
        cout << "Shortest distance from city " << s << " to city " << des << ": " << distance[des] << endl; 
        cout << "Shortest Path :"; 
        print(predecessor, s, des); 
        cout << endl; 
    } else { 
        cout << "No path found from city " << s << " to city " << des << endl; 
    } 
    return 0; 
}