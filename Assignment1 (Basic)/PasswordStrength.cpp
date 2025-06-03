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
    
    vector<char> ban = {'.', '\\', '/', ' ', ','};
    vector<char> spec = {'!' , '@' , '#' , '$' , '%' , '^' , '&' , '*' , '?' , '_' , '~'};

    string s;
    getline(cin, s);
    if (s.length() < 8){
        cout << "KhongHopLe";
        return 0;
    }
    for (int i=0; i<s.length(); i++){
        if (find(ban.begin(), ban.end(), s[i]) != ban.end()){
            cout << "KhongHopLe";
            return 0;
        }
    }

    int BaseScore = 40;
    int Bonus_Excess = 3;
    int Bonus_Upper = 4;
    int Bonus_Number = 5;
    int Bonus_Symbols = 5;
    int Bonus_Combo = 0;
    int Bonus_FlatLower = 0;
    int Bonus_FlatNumber = 0;
    int Number_Execess = 0;
    int Number_Upper = 0;
    int Number_Numbers = 0;
    int Number_Symbols = 0;    
    int Number_Lower = 0;
    Number_Execess = s.length() - 8;

    for (int i=0; i<s.length(); i++){
        if (s[i] >= 'A' && s[i] <= 'Z'){
            Number_Upper += 1;
        }
        if (s[i] >= 'a' && s[i] <= 'z'){
            Number_Lower += 1;
        }
        if (s[i] >= '0' && s[i] <= '9'){
            Number_Numbers += 1;
        }
        if (find(spec.begin(), spec.end(), s[i]) != spec.end()){
            Number_Symbols += 1;
        }
    }
    
    int check = (Number_Upper > 0) + (Number_Numbers > 0) + (Number_Symbols > 0);
    if (check == 3){
        Bonus_Combo = 25;
    }
    else if (check == 2){
        Bonus_Combo = 15;
    }
    
    if (Number_Lower == s.length()){
        Bonus_FlatLower = -15;
    }

    if (Number_Numbers == s.length()){
        Bonus_FlatNumber = -35;
    }

    int score = BaseScore + (Number_Execess*Bonus_Excess) + (Number_Upper*Bonus_Upper)+ (Number_Numbers*Bonus_Number) + (Number_Symbols*Bonus_Symbols) +Bonus_Combo + Bonus_FlatLower + Bonus_FlatNumber;

    if (score < 50) cout << "Yeu";
    else if (score < 75) cout << "Vua";
    else if (score < 100) cout << "Manh";
    else cout << "RatManh";
}
