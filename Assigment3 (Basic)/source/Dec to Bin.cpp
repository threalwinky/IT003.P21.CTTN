#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;
const int inf = LLONG_MAX;

string dectobin(int n){
    if (n == 0) return "";
    dectobin(n / 2);
    return dectobin(n / 2) + to_string(n % 2);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")){
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);}
    
    int n;
    cin >> n;
    string s = dectobin(n);
    cout << s;
    
}
