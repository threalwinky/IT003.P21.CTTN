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
    
    vector<int> v1(1000001), v2;
    int n;
    cin >> n;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        v1[i] = x;
    }
    int k;
    cin >> k;
    for (int i=1; i<=n; i++){
        if (v1[i] == k){
            v2.push_back(i);
            // cout << i-1 << " " << i << "\n";
        }
    }
    cout << v2.size() << "\n";
    for (auto i : v2){
        cout << i-1 << " " << i << "\n";
    }
    
}
