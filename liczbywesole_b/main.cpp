#include <iostream>
#include <cmath>

using namespace std;

int czy_wesola(int n){
    int liczba = 0;
    int suma = 0;
    while(1){
        do{
            liczba = n%10;
            n = n / 10;
            liczba = pow(liczba, 2);
            suma += liczba;
        }while(n != 0);
        cout << suma << endl;
        if(suma == 1) return 1;
        if(suma == 4) return 4;
        n = suma;
        suma = 0;
    }
}

int main()
{
    int n = 0;
    cout << "Podaj liczbe naturalna: " << endl;
    cin >> n;
    int czywesola = czy_wesola(n);
    cout << endl;
    if(czywesola == 4) cout << "4" << endl;
    if(czywesola == 1) cout << "1" << endl;
    cin >> n;
    return 0;
}
