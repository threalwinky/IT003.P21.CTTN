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
    
    string s;
    cin >> s;
    stack<int> st;
    bool flag = 0;

    for (int i=0; i<s.length(); i++){
        if (s[i] == ']'){
            if (!st.empty() && st.top() == '['){
                st.pop();
            }
            else{
                flag = 1;
                break;
            }
        }
        if (s[i] == ')'){
            if (!st.empty() && st.top() == '('){
                st.pop();
            }
            else{
                flag = 1;
                break;
            }
        }
        if (s[i] == '}'){
            if (!st.empty() && st.top() == '{'){
                st.pop();
            }
            else{
                flag = 1;
                break;
            }
        }
        if (s[i] == '[' || s[i] == '{' || s[i] == '('){
            st.push(s[i]);
        }
    }

    if (!st.empty() || flag){
        cout << 0;
    }
    else cout << 1;
    
}
