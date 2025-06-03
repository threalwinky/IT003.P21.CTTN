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
int c = 0;
void dfs(int u){
    visited[u] = 1;
    c++;
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
    dfs(0);
    vector<int> ans;
    for (int i=0; i<n; i++){
        if (visited[i] && i != 0){
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end());
    if (ans.size() == 0){
        cout << "KHONG";
        return 0;
    }
    for (auto it : ans){
        cout << it << " ";
    }
    
}