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
    cin >> n;
    vector<int> v(1000001), v2(1000001);
    for (int i=1; i<=n; i++){
        cin >> v[i];
    }
    int k = 0;
    for (int i=1; i<=n; i++){
        v2[v[i]] = 1;
        for (k; k<=1000001; k++){
            if (v2[k] == 0){
                cout << k << " ";
                break;
            }
        }
    }
    
}
