#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream cyfry;
    ofstream wynik;
    cyfry.open("cyfry.txt");
    wynik.open("wynik.txt");
    string liczba;
    string liczba_najmniejsza;
    string liczba_najwieksza;
    int najwieksza = 0;
    int najmniejsza = 0;

    while(cyfry >> liczba){
        int ile = 0;
        for(int i = liczba.length() - 1; i >=0 ; i--){
            ile += liczba[i];
        }
        if(ile > najwieksza){
            najwieksza = ile;
            liczba_najwieksza = liczba;
        }
        if(najmniejsza == 0){
            najmniejsza = ile;
        }
        if(ile < najmniejsza){
            najmniejsza = ile;
            liczba_najmniejsza = liczba;
        }
    }

    wynik << "Liczba ktorej suma cyfr jest Najwieksza: " << liczba_najwieksza << " Najmniejsza: " << liczba_najmniejsza << endl;

    return 0;
}
