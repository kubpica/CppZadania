#include <iostream>
#include <cmath>
#include <fstream>

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
        //cout << suma << endl;
        if(suma == 1) return 1;
        if(suma == 4) return 4;
        n = suma;
        suma = 0;
    }
}

int main()
{
    ifstream dane;
    dane.open("wes_dane.txt");
    ofstream wynik;
    wynik.open("wes_odp.txt");
    int liczba = 0;
    int ilosc = 0;
    int czywesola = 0;
    dane >> ilosc;

    while(dane >> liczba){
        czywesola = czy_wesola(liczba);
        wynik << liczba << " " << czywesola << endl;
    }

    dane.close();
    wynik.close();
    return 0;
}
