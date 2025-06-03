#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;
const int inf = LLONG_MAX;

vector<int> v(N), a, b;
int n, X;
void mitm1(int i, int sum){
    if (sum > X) return;
    if (i > n/2){
        a.push_back(sum);
        return;
    }
    mitm1(i+1, sum);
    mitm1(i+1, sum + v[i]);
}

void mitm2(int i, int sum){
    if (sum > X) return;
    if (i > n){
        b.push_back(sum);
        return;
    }
    mitm2(i+1, sum);
    mitm2(i+1, sum + v[i]);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")){
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);}

    cin >> n >> X;    
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }

    mitm1(1, 0);
    mitm2(n/2+1, 0);
    sort(b.begin(), b.end());
    int ans = 0;
    for (int i = 0; i < a.size(); i++){
        ans += upper_bound(b.begin(), b.end(), X - a[i]) - lower_bound(b.begin(), b.end(), X - a[i]);
    }
    cout << ans;
}