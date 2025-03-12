#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;
const int inf = LLONG_MAX;

vector<string> v;
int ans = 0;
int bs(vector<string> A, int n, string T){
    int L = 0;
    int R = n - 1;
    while (L <= R){
        int m = (L + R) >> 1;
        // cout << m << "\n" 
        if (A[m] < T){
            L = m + 1;
        }
        else if (A[m] > T){
            R = m - 1;
        }
        else return m;
        ans += 1;
    }
    return -1;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")){
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);}
    
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        string x;
        cin >> x;
        v.push_back(x);
    }
    string k;
    cin >> k;
    int res = bs(v, v.size(), k);
    if (res == -1){
        cout << res;
    }
    else{
        cout << res  << "\n";
        cout << ans + 1;
    }
}
