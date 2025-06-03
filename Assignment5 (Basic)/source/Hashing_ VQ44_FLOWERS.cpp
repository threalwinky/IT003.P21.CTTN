
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;


vector<int> get_ans(const vector<int>& A,int K){
	map<int,int> Hash;

    for (int i=0; i<A.size(); i++){
        Hash[A[i]]++;
    }
    vector<int> ans;
    for (auto it : Hash){
        Hash[it.first]--;
        ans.push_back(it.first);
        K--;
        if (K == 0){
            return ans;
        }
    }
    for (auto it : Hash){
        for (int i=0; i<it.second; i++){
            ans.push_back(it.first);
            K--;
            if (K == 0){
                return ans;
            }
        }
    }
	return ans;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
    if (fopen("TASK.INP", "r")){
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }
	cin >> n >> k;
	
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	vector<int> ans = get_ans(a,k);
	
	for (const int& x: ans) cout << x << ' ';
	return 0;
}
