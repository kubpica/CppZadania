#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
ofstream wynik;

int bintodec(string liczba){
    int wynik = 0;
    for(int i = liczba.length()-1 ; i>=0 ; i--){
        if(liczba[i] == '1') wynik += pow(2, liczba.length()-1-i);
    }
    return wynik;
}

void dectobin(int liczba){
    if(liczba == 0) return;
    int wynikk;
    wynikk = liczba%2;
    liczba /= 2;
    dectobin(liczba);
    wynik << wynikk;
}

int main()
{
    ifstream liczby;
    liczby.open("liczby.txt");
    wynik.open("wynik.txt");
    string liczba;
    int ile = 0;
    int suma = 0;

    while(liczby >> liczba){
        if(liczba.length() == 9){
            ile++;
            int liczbadec = bintodec(liczba);
            suma += liczbadec;
        }
    }
    wynik << "Ile?: " << ile << endl;
    wynik << "Suma: ";
    dectobin(suma);
    return 0;
}
