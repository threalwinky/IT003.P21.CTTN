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
        freopen("TASK.OUT", "w", stdout);
    }
    
    string sb, se;
    cin >> sb >> se;
    int lsb = sb.length();
    int lse = se.length();
    
    string ans = "";
    int lans = lsb + lse;  
    
    for (int i = 0; i < lsb; i++) {
        for (int j = 0; j <= lse; j++) {
            if (sb.substr(i) == se.substr(0, lse - j)) {
                string tmp = sb + se.substr(lse - j);
                if (tmp.length() < lans) {
                    lans = tmp.length();
                    ans = tmp;
                }
            }
        }
    }

    if (lans == lsb + lse) {
        cout << lans << "\n" << sb + se;
    } else {
        cout << lans << "\n" << ans;
    }

    return 0;
}