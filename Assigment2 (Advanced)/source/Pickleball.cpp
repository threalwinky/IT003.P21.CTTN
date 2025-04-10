const int N = 1e6 + 9;
signed main() {
    int n, d;
    cin >> n >> d;
    vector<int> a(N), p(N);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= d; i++){
        p[a[i]]++;
    }
    int ans = 0;
    for (int i = d+1; i <= n; i++) {
        int c = 0, tmp = 0, tmp1 = -1, tmp2 = -1;
        for (int j = 0; j <= 200; j++) {
            c += p[j];
            if (tmp1 == -1 && c >= (d+1)/2){
                tmp1 = j;
            }
            if (tmp2 == -1 && c >= (d/2)+1){
                tmp2 = j;
            }
            if (tmp1 != -1 && tmp2 != -1) break;
        }

        if (d&1){
            tmp = tmp2 * 2;
        }
        else{
            tmp = tmp1 + tmp2;
        }

        if (a[i] >= tmp) ans++;
        p[a[i - d]]--; p[a[i]]++;  
    }
    cout << ans;
}
