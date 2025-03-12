#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;
const int inf = LLONG_MAX;

string rev(string s){
    string tmp = s;
    for (int i=0; i<s.length(); i++){
        tmp[s.length() - i -1] = s[i];
    }
    return tmp;
}

string split(string s, int k){
    // cout << k << "\n";
    string tmp1, tmp2;
    for (int i=0; i<k; i++){
        tmp1 += s[i];
    }
    for (int i=k; i<s.length(); i++){
        tmp2 += s[i];
    }
    return rev(tmp1) + (tmp2);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")){
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);}
    
    string s;
    cin >> s;
    int n = s.length();
    vector<int> v;
    for (int i=1; i<=n ;i++){
        if (n % i == 0){
            v.push_back(i);
        }
    }
    
    for (int i = 0; i < v.size(); i++){
        s = split(s, v[i]);
    }
    cout << s;
}