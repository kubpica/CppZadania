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
    bool czy_sa_jedynki = false;
    bool czy_sa_zera = false;
    int ile = 0;

    while(slowa >> slowo){
        czy_sa_jedynki = false;
        czy_sa_zera = false;
        for(int i = slowo.length()-1 ; i>=0 ; i--){
            if(slowo[i] == '1'){
                czy_sa_jedynki = true;
                if(czy_sa_zera){
                    break;
                }
            }else if(slowo[i] == '0' && czy_sa_jedynki == true){
                czy_sa_zera = true;
                if(i == 0){
                    ile++;
                }
            }else{
                break;
            }
        }
    }

    wynik << ile << endl;
    slowa.close();
    wynik.close();

    return 0;
}
