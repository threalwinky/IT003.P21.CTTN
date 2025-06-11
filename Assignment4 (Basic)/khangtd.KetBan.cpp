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

    int n, m;
    cin >> n >> m;
    vector<int> prev(n + 1, 0);
    vector<int> next(n + 1, 0);

    for (int i = 1; i <= n; i++){
        prev[i] = i - 1;
        next[i] = i + 1;
    }
    prev[1] = n;
    next[n] = 1;

    while (m--){
        int x, y;
        cin >> x >> y;

        int a = prev[x];
        int b = next[x];

        next[a] = b;
        prev[b] = a;

        next[x] = next[y];
        prev[next[y]] = x;
        prev[x] = y;
        next[y] = x;

    }
    int tmp = 1;
    for (int i = 1; i <= n; i++){
        cout << tmp << " ";
        tmp = next[tmp];
    }
}