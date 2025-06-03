#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
    int result = system("python3 --version > /dev/null 2>&1");
    if (result == 0) {
        cout << "[*] Python3 is installed." << endl;
        system("python3 sorting.py");
    } else cout << "[*] Python3 is not installed. Please install it." << endl;
    return 0;
}
