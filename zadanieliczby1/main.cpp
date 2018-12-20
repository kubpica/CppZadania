#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream liczby;
    ofstream wynik;
    liczby.open("liczby.txt");
    wynik.open("wynik.txt");
    string liczba;
    int ile = 0;

    while(liczby >> liczba){
        if(liczba[0] == liczba[liczba.length()-1]) ile++;
    }

    wynik << ile;

    liczby.close();
    wynik.close();

    return 0;
}
