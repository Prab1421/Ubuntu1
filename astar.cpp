#include <bits/stdc++.h> 
using namespace std; 
// A class representing a node in the search space 
class Node { 
    public: 
        string name; 
        Node* parent; 
        double g; // Cost from start 
        double h; // Heuristic to goal 
        double f; // Total cost 
        Node(string n, Node* p = nullptr, double g_cost = 0, double h_cost = 0) 
            : name(n), parent(p), g(g_cost), h(h_cost), f(g_cost + h_cost) {} 
        bool operator<(const Node& other) const { 
            return f > other.f;  // Min-heap 
        } 
    }; 
    vector<string> a_star( 
        const unordered_map<string, unordered_map<string, double>>& graph, 
        const unordered_map<string, double>& heuristic, 
        const string& start, const string& goal 
    ) { 
        priority_queue<Node> open_list; 
        set<string> closed; 
        Node start_node(start, nullptr, 0, heuristic.at(start)); 
        open_list.push(start_node); 
        while (!open_list.empty()) { 
            Node current = open_list.top(); 
            open_list.pop(); 
            if (current.name == goal) { 
                vector<string> path; 
                Node* temp = new Node(current); 
                while (temp != nullptr) { 
                    path.push_back(temp->name); 
                    temp = temp->parent; 
                }
                reverse(path.begin(), path.end()); 
                return path; 
            } 
            closed.insert(current.name); 
            for (const auto& neighbor : graph.at(current.name)) { 
                string neighbor_name = neighbor.first; 
                double cost = neighbor.second; 
                if (closed.find(neighbor_name) != closed.end()) continue; 
                double g_new = current.g + cost; 
                double h_new = heuristic.at(neighbor_name); 
                Node* parent = new Node(current); 
                Node neighbor_node(neighbor_name, parent, g_new, h_new); 
                open_list.push(neighbor_node); 
            } 
        } 
        return {};  // No path found 
    } 
    int main() { 
        int n, e; 
        cout << "Enter number of nodes: "; 
        cin >> n; 
        vector<string> nodes(n); 
        unordered_map<string, unordered_map<string, double>> graph; 
        unordered_map<string, double> heuristic; 
        cout << "Enter node names:\n"; 
        for (int i = 0; i < n; ++i) { 
            cin >> nodes[i]; 
        } 
        cout << "Enter number of edges: "; 
        cin >> e; 
        cout << "Enter edges in format: from to cost\n"; 
        for (int i = 0; i < e; ++i) { 
            string from, to; 
            double cost; 
            cin >> from >> to >> cost; 
            graph[from][to] = cost; 
            graph[to][from] = cost; // If undirected 
        } 
        cout << "Enter heuristic values for each node:\n"; 
        for (int i = 0; i < n; ++i) { 
            double h; 
            cout << "Heuristic for " << nodes[i] << ": "; 
            cin >> h; 
            heuristic[nodes[i]] = h; 
        } 
        string start, goal; 
        cout << "Enter start node: "; 
        cin >> start; 
        cout << "Enter goal node: "; 
        cin >> goal; 
        vector<string> path = a_star(graph, heuristic, start, goal); 
        if (path.empty()) { 
            cout << "No path found from " << start << " to " << goal << ".\n"; 
        } else { 
            cout << "Path: "; 
            for (const string& node : path) { 
                cout << node << " "; 
            } 
            cout << endl; 
        } 
        return 0; 
    }
