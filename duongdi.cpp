#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> vt[1001];
bool visited[1001];
int parent[1001];
void init(){
    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int x, y;
        cin >> x >> y;
        vt[x].push_back(y);
        vt[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));

}
void dfs(int u){
    visited[u] = true;
    for (auto v:vt[u]){
        if (!visited[v]){
            dfs(v);
            parent[v] = u;
        }
    }
}
void bfs(int u){
    queue<int> qu;
    qu.push(u);
    visited[u] = true;
    while (!qu.empty()){
        int u = qu.front();
        qu.pop();
        for (auto x:vt[u]){
            if (!visited[x]){
                visited[x] = true;
                qu.push(x);
                parent[x] = u;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int s, t;
    cin >> s >> t;
    dfs(s);
    if (!visited[t]){
        cout << "Khong co duong di";
    }
    else{
        vector<int> ans;
        while (s!=t){
            ans.push_back(t);
            t = parent[t];
        }
        ans.push_back(s);
        reverse(ans.begin(), ans.end());
        for (auto x:ans) cout << x << ' ';
    }
}
