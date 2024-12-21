#include<bits/stdc++.h>
using namespace std;
const int N = 200;
vector<int> adj[N + 1], Path;
bool visited[N + 1];
int trace[N + 1];
int n, m, S, T;
void dfs(int u) {
    visited[u] = true;
    for (auto v : adj[u]) {
        if (visited[v] == false) {
            trace[v] = u;
            dfs(v);
        }
    }
}
void find_path(int t) {
    int x = t;
    while (true) {
        Path.push_back(x);
        if (x == S) {
            break;
        }
        x = trace[x];
    }
    for (int i = Path.size() - 1; i >= 0; i--) {
        cout << Path[i] << " ";
    }
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m >> S >> T;
    memset(visited, false, sizeof (visited));
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(S);
    if (visited[T] == false) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << "\n";
    find_path(T);
    return 0;
}
