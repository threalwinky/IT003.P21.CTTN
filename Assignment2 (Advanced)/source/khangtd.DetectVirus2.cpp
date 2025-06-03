#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;
const int inf = LLONG_MAX;

vector<int> prefix_func(string s) {
    int n = s.length();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int k = pi[i - 1];
        while (k > 0 && s[i] != s[k])
            k = pi[k - 1];
        pi[i] = (s[i] == s[k]) ? ++k : k;
    }
    return pi;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")) {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }
    
    string s, t;
    cin >> s >> t;
    string tmp = t + '#' + s;
    vector<int> pi = prefix_func(tmp);
    bool flag = 0;
    for (int i = t.size() + 1; i < pi.size(); i++) {
        if (pi[i] == t.size()) {
            flag = 1;
        }
    }
    if (!flag) {
        cout << "NO\n";
        return 0;
    }
    else{
        cout << "YES\n";
    }
    for (int i = t.size() + 1; i < pi.size(); i++) {
        if (pi[i] == t.size()) {
            cout << i - 2 * t.size() + 1 << " ";
        }
    }
}
