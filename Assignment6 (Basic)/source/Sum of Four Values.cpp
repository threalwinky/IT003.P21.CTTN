#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")) {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }

    int n, X;
    cin >> n >> X;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    map<int, pair<int, int>> m;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int need = X - v[i] - v[j];
            if (m.count(need)) {
                auto [x, y] = m[need];
                if (x != i && x != j && y != i && y != j) {
                    cout << x + 1 << " " << y + 1 << " " << i + 1 << " " << j + 1 << "\n";
                    return 0;
                }
            }
        }
        for (int j = 0; j < i; j++) {
            m[v[i] + v[j]] = {j, i};
        }
    }

    cout << "IMPOSSIBLE\n";
}
