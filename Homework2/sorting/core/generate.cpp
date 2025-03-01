#include<random>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<iomanip>

using namespace std;
random_device dev;
mt19937 rng(dev());
int generate_integer(){
    uniform_int_distribution<mt19937::result_type> dist6(-INT_MAX+10,INT_MAX-10);
    return dist6(rng) ;
}
double generate_float(){
    uniform_real_distribution<> dis(0, 1.0);
    double decimal = dis(rng);
    return generate_integer() + decimal;
}
int main(){
    const int real_numbers_count = 1000000;
    for (int test_file_index=1; test_file_index<=10; test_file_index++){
        vector<double> real_numbers(real_numbers_count + 1);
        for (int index=1; index<=real_numbers_count; index++){
            real_numbers[index] = generate_float();
        }
        if (test_file_index == 1){
            sort(real_numbers.begin()+1, real_numbers.end());
        }
        if (test_file_index == 2){
            sort(real_numbers.begin()+1, real_numbers.end(), greater<double>());
        }
        string file_name = "testcases/test" + to_string(test_file_index) + ".txt";
        freopen(file_name.c_str(), "w", stdout);
        for (int index=1; index<=real_numbers_count; index++){
            cout << fixed << setprecision(20) << real_numbers[index] << " ";
        }
    }
    return 0;
}                                                                                                                                                             
