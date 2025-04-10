#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;
const int inf = LLONG_MAX;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    if (fopen("TASK.INP", "r")) {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }
    
    string s;
    cin >> s;
    
    sort(s.rbegin(), s.rend());
    
    int sum = 0;
    for (auto c : s) sum += (c - '0');
    
    if (sum % 3 == 0) {
        cout << s << "\n";
        return 0;
    }
    
    int remainder = sum % 3;
    vector<int> count(10, 0);
    for (auto c : s) count[c - '0']++;
    
    bool removed = false;
    for (int i = remainder; i < 10; i += 3) {
        if (count[i] > 0) {
            count[i]--;
            removed = true;
            break;
        }
    }
    
    if (!removed) {
        int removeCount = 2;
        for (int i = 3 - remainder; i < 10; i += 3) {
            while (count[i] > 0 && removeCount > 0) {
                count[i]--;
                removeCount--;
            }
            if (removeCount == 0) break;
        }
    }
    
    string result = "";
    for (int i = 9; i >= 0; i--) {
        result += string(count[i], '0' + i);
    }
    
    if (result.empty() || result[0] == '0') result = "0";
    cout << result << "\n";
    
    return 0;
}