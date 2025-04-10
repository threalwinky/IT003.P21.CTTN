#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;
const int inf = LLONG_MAX;

int solve(vector<int> a, int x) {
    int n = a.size();
    int maxSum = -1;
    pair<int, int> ans = {-1, -1};

    vector<int> b = a;
    sort(b.begin(), b.end());

    int i = 0, j = n - 1;
    while (i < j) {
        int sum = b[i] + b[j];
        
        if (sum <= x) {
            if (sum > maxSum) {
                maxSum = sum;
                ans = {b[i], b[j]};
            }
            i++;
        } else {
            j--;
        }
    }
    
    return ans.first + ans.second;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")){
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);}
    int n, x;
    cin >> n >> x;

    vector<int> v;
    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    cout << solve(v, x);
    
}
