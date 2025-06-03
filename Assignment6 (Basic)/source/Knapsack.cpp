#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;
const int inf = LLONG_MAX;



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")){
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);}

    int n;
    int M;
    cin >> n >> M;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++){
        cin >> w[i] >> v[i];
    }
    vector<vector<int>> f(n + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= M; j++){
            f[i][j] = f[i - 1][j];
            if (j >= w[i - 1]){
                f[i][j] = max(f[i][j], f[i - 1][j - w[i - 1]] + v[i - 1]);
            }
        }
    }
    cout << f[n][M];
    
}