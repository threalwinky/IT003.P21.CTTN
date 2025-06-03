#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;
const int inf = LLONG_MAX;

int a[N], p[N];

int supow(int a, int b, int m){
    int res = 1;
    while (b){
        if (b & 1) res = res * a % m;
        a = a*a % m;
        b >>= 1;
    }
    return res;
}

int C(int k, int n){
	return p[n]*supow(p[k],mod-2,mod)%mod*supow(p[n-k],mod-2,mod)%mod;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")){
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);}
    int n, k;
    cin >> n >> k;
	for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
	sort(a+1, a+n+1);
	p[0] = 1;
	for(int i = 1; i <= n; i++) {
		p[i] = p[i-1] * i % mod;
	}
    int ans = 0;
	sort(a+1, a+n+1, greater<int>());
    for (int i = 1; i <= n; i ++){
        if (n - i >= k - 1){
            ans = (ans + a[i] * C(k - 1, n - i) % mod) % mod;
        }
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i ++) 
    	if (n - i >= k - 1)
        	ans = (ans - a[i] * C(k - 1, n - i) % mod + mod) % mod;
    cout << (ans + mod) % mod;	
}
