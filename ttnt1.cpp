#include<bits/stdc++.h>
using namespace std;
const int N = 200;
vector<int> adj[N + 1], Path;
bool visited[N + 1];
int n, m, S, T, L[N + 1], trace[N + 1];
void bfs(int s) {
    memset(visited, false, sizeof (visited));
    queue<int> q;
    q.push(s);
    L[s] = 0;
    visited[s] = true;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (visited[v] == false) {
                L[v] = L[u] + 1;
                trace[v] = u;
                q.push(v);
                visited[v] = true;
            }
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
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        // t?c v k? u
        adj[v].push_back(u);
        // t?c u k? v
    }
    memset(L, -1, sizeof (L));
    bfs(S);
    cout << L[T] << '\n';
    if (L[T] == -1) {
        return 0;
    }
    find_path(T);
    return 0;
}
