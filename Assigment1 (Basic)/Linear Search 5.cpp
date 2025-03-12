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
    
    int T;
    cin >> T;
    while (T--){
        vector<int> v;
        int n;
        cin >> n;
        for (int i=1; i<=n; i++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        int a = v[v.size()-1] + v[v.size()-2] - v[0] - v[1];
        int b = v[v.size()-1] - v[0];
        cout << max(a, b) << "\n";
    }
    
}
