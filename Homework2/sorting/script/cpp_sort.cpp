#include<random>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<iomanip>
#include<chrono>

using namespace std;
const int cnt = 1000000;
double real_numbers[cnt + 1];

void cpp_sort(int cnt){
    sort(real_numbers+1, real_numbers+cnt+1);
}

int main(int arvc, char *argv[]){
    freopen(argv[1], "r", stdin);
    for (int index=1; index<=cnt; index++){
        cin >> real_numbers[index];
    }
    auto start_time = chrono::steady_clock::now();
    cpp_sort(cnt);
    auto end_time = chrono::steady_clock::now();
    auto result = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
    
    cout << result.count();
    return 0;
}