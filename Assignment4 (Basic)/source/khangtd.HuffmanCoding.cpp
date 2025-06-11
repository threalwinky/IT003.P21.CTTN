#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;
const int inf = LLONG_MAX;

int huffman(string s){
    int n = s.size();
    vector<int> cnt(256, 0);
    for (char c : s) cnt[c]++;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < 256; i++) if (cnt[i]) pq.push(cnt[i]);

    if (pq.size() == 1) return n;

    int ans = 0;
    while (pq.size() > 1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        ans += a + b;
        pq.push(a + b);
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")){
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);}

    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << huffman(s);
    
}