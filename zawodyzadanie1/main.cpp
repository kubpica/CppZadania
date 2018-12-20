#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream dziennik;
    ofstream wynik;
    dziennik.open("dziennik.txt");
    wynik.open("wynik.txt");
    int dlugosc = 0;
    int poprzednia_dlugosc = 0;
    int iledni = 0;
    int ile = 0;
    int ktory = 0;

    while(dziennik >> dlugosc){
        ktory++;
        if(dlugosc > poprzednia_dlugosc){
            poprzednia_dlugosc = dlugosc;
            iledni++;
        }else{
            poprzednia_dlugosc = dlugosc;
            if(iledni > 3) ile++;
            iledni = 1;
        }
        if(ktory == 310){
            if(iledni > 3) ile++;
        }
    }

    wynik << "Serii dluzszych niz 3 dni: " << ile << endl;
    wynik << "Ile dni: " << ktory << endl;
    dziennik.close();
    wynik.close();
    return 0;
}
