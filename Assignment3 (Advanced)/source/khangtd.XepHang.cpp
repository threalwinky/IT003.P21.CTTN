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
    
    int n, m;
    cin >> n >> m;
    stack<int> st;
    map<int, int> mp;
    for (int i=n; i>=1; i--){
        st.push(i);
    }
    for (int i=0; i<m; i++){
        int x;
        cin >> x;
        st.push(x);
    }
    while (!st.empty()){
        if (!mp[st.top()]){
            cout << st.top() << " ";
            mp[st.top()] = 1;
        }
        st.pop();
    }
    
}
