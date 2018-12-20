#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int bintodec(string liczba_bin){
    int wynik = 0;
    for(int i = liczba_bin.length()-1 ; i>=0 ; i--){
        if(liczba_bin[i] == '1'){
            wynik += pow(2, liczba_bin.length()-1-i);
        }
    }
    return wynik;
}

int main()
{
    ifstream liczby;
    ofstream wynik;
    liczby.open("liczby.txt");
    wynik.open("wynik.txt");
    string liczba_bin;
    int najwieksza_dec = 0;
    string najwieksza_bin;

    while(liczby >> liczba_bin){
        int liczba_dec = bintodec(liczba_bin);
        if(liczba_dec > najwieksza_dec){
            najwieksza_dec = liczba_dec;
            najwieksza_bin = liczba_bin;
        }
    }
    wynik << "Najwieksza w dziesietnym: " << najwieksza_dec << endl;
    wynik << "w binarnym / dwojkowym: " << najwieksza_bin << endl;
    return 0;
}
