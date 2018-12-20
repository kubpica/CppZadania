#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream slowa;
    ofstream wynik;
    slowa.open("slowa.txt");
    wynik.open("wynik.txt");
    string slowo;
    int dlugosc = 0;

    while(slowa >> slowo){
        int licznik = 0;
        for(int i = slowo.length()-1 ; i>=0 ; i--){
            if(slowo[i] == '0'){
                licznik++;
                if(i == 0){
                    if(licznik > dlugosc) dlugosc = licznik;
                    licznik = 0;
                }
            }else{
                if(licznik > dlugosc) dlugosc = licznik;
                licznik = 0;
            }
        }
    }

    wynik << "Dlugosc najdluzszego blok zlozony z samych zer: " << dlugosc << endl;
    wynik << "Slowa zawierajace taki najdluzszy blok:" << endl;

    slowa.close();
    slowa.open("slowa.txt");

    while(slowa >> slowo){
        int licznik = 0;
        for(int i = slowo.length()-1 ; i>=0 ; i--){
            if(slowo[i] == '0'){
                licznik++;
                if(i == 0){
                    if(licznik == dlugosc){
                    wynik << slowo << endl;
                    }
                    licznik = 0;
                }
            }else{
                if(licznik == dlugosc){
                    wynik << slowo << endl;
                }
                licznik = 0;
            }
        }
    }

    slowa.close();
    wynik.close();

    return 0;
}
