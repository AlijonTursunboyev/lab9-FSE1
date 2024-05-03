
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int numComp;
void dfs(int u) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}
int main() {
    int a, b;
    cin >> a>> b;
    
    graph.resize(a);
    
    visited.resize(a, false);
    
    numComp= 0;
    for (int i = 0; i < b; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 0; i < a; i++) {
        if (!visited[i]) {
            dfs(i); numComp++;
        }
    }
    cout << numComp << endl;
    return 0;
}
