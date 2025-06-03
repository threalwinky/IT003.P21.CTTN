#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;
const int inf = LLONG_MAX;

vector<int> g[N];
vector<int> visited(N, 0);
vector<int> ans;
void dfs(int u){
    visited[u] = 1;
    ans.push_back(u);
    for (int v : g[u]){
        if (!visited[v]){
            dfs(v);
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")){
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);}

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int q;
    cin >> q;
    dfs(q);
    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for (int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
}