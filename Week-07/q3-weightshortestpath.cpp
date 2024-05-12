#include <bits/stdc++.h>
using namespace std;

int shortest_weigt(int **graph, int ver, int u, int v, int k) {
    if (k <= 0)
        return INT_MAX;
    if (k == 0 && u == v)
        return 0;
    if (k == 1 && graph[u][v] != INT_MAX)
        return graph[u][v];
    int res = INT_MAX;
    for (int i = 0; i < ver; i++) {
        if (graph[u][i] != 0 && u != i && v != i) {
            int recu = shortest_weigt(graph, ver, i, v, k - 1);
            if (recu != INT_MAX)
                res = min(res, graph[u][i] + recu);
        }
    }
    return res;
}

int main() {
    int ver, u, v, k, ans;
    cin >> ver;
    int **graph = (int **)malloc(ver * sizeof(int *));
    for (int i = 0; i < ver; i++)
        graph[i] = (int *)malloc(sizeof(int) * ver);
    for (int i = 0; i < ver; i++)
        for (int j = 0; j < ver; j++)
            cin >> graph[i][j];
    cin >> u >> v >> k;
    ans = shortest_weigt(graph, ver, u - 1, v - 1, k);
    cout << "Weight of shortest path from (" << u
         << "," << v << ") with " << k << " edges :" << ans;
}





// #include<iostream>
// #include<vector>
// #include<queue>
// #include<climits>

// using namespace std;

// void BFS(int n, vector<vector<int>>& a, int s, int d, int k, vector<int>& visited) {
//     vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX)); // 2D array to store shortest distances
//     queue<pair<int, int>> q; // Queue to perform BFS (vertex, edge count)

//     q.push({s, 0}); // Push the source vertex with 0 edges
//     dist[s][0] = 0; // Distance to source with 0 edges is 0

//     while (!q.empty()) {
//         int u = q.front().first; // Current vertex
//         int e = q.front().second; // Number of edges to reach current vertex
//         q.pop();

//         visited[u] = 1; // Mark current vertex as visited

//         // Iterate through all adjacent vertices of u
//         for (int v = 0; v < n; ++v) {
//             // If there is an edge from u to v and the current number of edges plus one is less than k
//             if (a[u][v] && e + 1 <= k) {
//                 // If distance through u to v is shorter than current distance
//                 if (dist[v][e + 1] > dist[u][e] + a[u][v]) {
//                     dist[v][e + 1] = dist[u][e] + a[u][v]; // Update distance
//                     q.push({v, e + 1}); // Push v with incremented edge count
//                 }
//             }
//         }
//     }

//     // Output shortest distance from source to destination with exactly k edges
//     if (dist[d][k] != INT_MAX)
//         cout << "Shortest distance from source to destination with exactly " << k << " edges: " << dist[d][k] << endl;
//     else
//         cout << "No path from source to destination with exactly " << k << " edges." << endl;
// }

// int main() {
//     int n;
//     cout << "Enter the size of the matrix: ";
//     cin >> n;

//     vector<vector<int>> a(n, vector<int>(n));

//     cout << "Enter the adjacency matrix: ";
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cin >> a[i][j];
//         }
//     }

//     int source, destination, k;
//     cout << "Enter the source: ";
//     cin >> source;
//     cout << "Enter the destination: ";
//     cin >> destination;
//     cout << "Enter the number of edges between them: ";
//     cin >> k;

//     vector<int> visited(n, 0);

//     cout << "BFS traversal: ";
//     BFS(n, a, source, destination, k, visited);

//     return 0;
// }

