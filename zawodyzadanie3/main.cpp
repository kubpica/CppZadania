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
    int najwdni = 0;
    int ile = 0;
    int dl_w_pierwszy_dzien_serii = 0;
    int o_ile_sie_poprawil = 0;

    while(dziennik >> dlugosc){
        if(dlugosc > poprzednia_dlugosc){
            poprzednia_dlugosc = dlugosc;
            if(iledni == 0){
                dl_w_pierwszy_dzien_serii = dlugosc;
            }
            iledni++;
        }else{
            if(iledni > najwdni){
                najwdni = iledni;
                o_ile_sie_poprawil = poprzednia_dlugosc - dl_w_pierwszy_dzien_serii;
            }
            iledni = 1;
            poprzednia_dlugosc = dlugosc;
            dl_w_pierwszy_dzien_serii = dlugosc;
        }
    }

    wynik << "Najdluzsza seria trwala " << najwdni << "dni i poprawil sie podczas niej o " << o_ile_sie_poprawil << endl;

    return 0;
}
