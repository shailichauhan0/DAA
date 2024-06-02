#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void DFS(vector<vector<int>>& graph, int v, vector<bool>& visited) {
    stack<int> stk;
    stk.push(v);
    visited[v] = true;

    while (!stk.empty()) {
        int curr = stk.top();
        stk.pop();

        for (int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                stk.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int findMotherVertex(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    int mother = -1;
    for (int v = 0; v < n; v++) {
        if (!visited[v]) {
            DFS(graph, v, visited);
            mother = v; 
        }
    }

    for (int v = 0; v < n; v++) {
        visited.assign(n, false);
        DFS(graph, mother, visited);

        if (!visited[v]) {
            return -1; 
        }
    }
    return mother;
}

int main() {
    int n;
    cout << "Enter the number of vertices in the graph: ";
    cin >> n;

    vector<vector<int>> graph(n);
    cout << "Enter the adjacency list for each vertex:" << endl;
    
    for (int v = 0; v < n; v++) {
        int neighbors;
        cout << "Enter the number of neighbors for vertex " << v << ": ";
        cin >> neighbors;
        cout << "Enter the neighbors of vertex " << v << ": ";

        for (int i = 0; i < neighbors; i++) {
            int neighbor;
            cin >> neighbor;
            graph[v].push_back(neighbor);
        }
    }

    int mother = findMotherVertex(graph);
    if (mother != -1) {
        cout << "The mother vertex in the graph is: " << mother << endl;
    } else {
        cout << "No mother vertex found in the graph." << endl;
    }

    return 0;
}
