#include <iostream>
#include <queue>
#include <limits>
#include <vector>

using namespace std;

vector<vector<int>> graphic;
vector<int> distance;
void bfs(int source) {
    queue<int> q;
    
    q.push(source);
    distance[source] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop(); 
        for (int v : graphic[u]) {
            if (distance[v] == -1) {
                distance[v] = distance[u] + 1;
                q.push(v); }
        }
    }
}
int main() {
    int a, b;
    cin >> a >> b;
    graphic.resize(a);
    distance.resize(a, -1);
    for (int i = 0; i < b; i++) {
        int u, v;
        cin >> u >> v;
        graphic[u].push_back(v);
        graphic[v].push_back(u);
    }
    bfs(0);
    for (int i = 0; i < a; i++) {
        if (distance[i] == -1) {
            cout << -1 << " ";
        }
        else { cout << distance[i] << " ";
        }
    }
    return 0;
}
