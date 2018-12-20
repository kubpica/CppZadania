#include <iostream>
#include <fstream>

using namespace std;

bool czy_odbicie(string slowo, string slowo2){
    if(slowo.length() != slowo2.length()){
        return false;
    }
    for(int i = 0; i<slowo.length(); i++){
        if(slowo[i] != slowo2[slowo2.length() - 1 - i]){
            return false;
        }
    }
    return true;
}

int main()
{
    ifstream slowa;
    ifstream slowa2;
    slowa.open("slowa.txt");
    ofstream wynik;
    wynik.open("wynik5.txt");
    int ile_n_literowych[12];

    for(int i = 0; i<12; i++){
        ile_n_literowych[i] = 0;
    }
    int dlugosc = 0;
    string slowo;
    while( slowa >> slowo ){
        dlugosc = slowo.length();
        ile_n_literowych[dlugosc-1]++;
    }
    for(int i = 0; i<12; i++){
        cout << i+1 << ": " << ile_n_literowych[i] << endl;
    }

    wynik << "5.1." << endl;
    for(int i = 0; i<12; i++){
        wynik << i+1 << " " << ile_n_literowych[i] << endl;
    }
    wynik << endl;
    wynik << "5.2." << endl;

    slowa.close();
    slowa.open("nowe.txt");
    string slowo2;

    int iletakichsamych = 0;
    int ileodbic = 0;
    while( slowa >> slowo ){
        slowa2.open("slowa.txt");
        while( slowa2 >> slowo2 ){
            if(slowo == slowo2){
                iletakichsamych++;
            }
            if(czy_odbicie(slowo, slowo2)){
                ileodbic++;
            }
        }
        wynik << slowo << " " << iletakichsamych << " " << ileodbic << endl;
        slowa2.close();
        iletakichsamych = 0;
        ileodbic = 0;
    }


    return 0;
}
