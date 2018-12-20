#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    cout << "Siema, podaj tekst do zaszyfrowania: " << endl;
    string jawny;
    getline(cin, jawny);
    int d = ceil(sqrt(jawny.size()));
    cout << "d = " << d << endl;
    int wiersz = 0;
    int kolumna = 0;

    char tablica[d][d];
    for(int i = 0; i<jawny.size() ; i++){
        tablica[wiersz][kolumna] = jawny[i];
        kolumna++;
        if(kolumna == d){
            kolumna = 0;
            wiersz++;
            if(wiersz == d){
                cout << "FULL" << endl;
                if(i != jawny.size()) cout << "OMG WTF" << endl;
            }
        }
    }
    while(wiersz < d){
        tablica[wiersz][kolumna] = '\0';
        kolumna++;
        if(kolumna == d){
            kolumna = 0;
            wiersz++;
        }
    }

    wiersz = 0;
    kolumna = 0;
    for(int i = 0; i<d*d ; i++){
        if (tablica[wiersz][kolumna] != '\0') cout << tablica[wiersz][kolumna];
        wiersz++;
        if(wiersz == d){
            wiersz = 0;
            kolumna++;
            if(kolumna == d){
                if(i != 24) cout << "OMG WTF2" << endl;
            }
        }
    }

    return 0;
}
