#include <iostream>

using namespace std;

int main(){
    int n = 1;
    cin >> n;
    int d = 1;
    int iloczyn = 1;
    while(d <= n/2){
        if(n%d == 0){
            iloczyn = iloczyn * d;
        }
        d++;
    }
    if(iloczyn == n){
        cout << "TAK" << endl;
    }else{
        cout << "NIE" << endl;
    }
    return 0;
}
