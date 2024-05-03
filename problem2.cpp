#include <iostream>
#include <vector>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;

    vector<vector<int>> graph(a);

    for (int i = 0; i < b; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); }
    int queue;
    cin >> queue;
    for (int i = 0; i < queue; i++) {
        int x, y;
        cin >> x >> y;
        bool found = false;
        for (int j = 0; j < graph[x].size(); j++) {
            if (graph[x][j] == y) {
                found = true;
                break;
            }
        }
        if (found){
            cout << "YES" << endl;
        }
        else { cout << "NO" << endl; }
    }
    return 0; }
