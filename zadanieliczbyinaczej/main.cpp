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
        if(liczba[liczba.length()-1] == '0'){
            ile++;
        }
    }

    wynik << "Liczb parzystych jest: " << ile << endl;
    wynik.close();
    liczby.close();
    return 0;
}
