#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream slowa;
    ifstream klucze;
    ofstream wynik;
    slowa.open("tj.txt");
    klucze.open("klucze1.txt");
    wynik.open("wynik.txt");
    string slowo;
    string klucz;

    while(slowa >> slowo){
        klucze >> klucz;
        int i_klucza = 0;
        for(int i = 0 ; i<slowo.length() ; i++){
            int kodslowa = slowo[i];
            cout << "kodslowa: " << kodslowa << endl;
            if(i_klucza == klucz.length()){
                i_klucza = 0;
            }
            int kodklucza = klucz[i_klucza] - 64;
            cout << "kodklucza: " << kodklucza << endl;
            int kodszyfru = kodslowa + kodklucza;
            cout << "kodszyfru: " << kodszyfru << endl;
            if(kodszyfru > 90){
                kodszyfru = kodszyfru - 26;
                cout << "odejmuje bo wiecej niz 90 i tera: " << kodszyfru << endl;
            }
            char znakszyfru = kodszyfru;
            cout << "znakszyfru: " << znakszyfru << endl;
            wynik << znakszyfru;
            i_klucza++;
            if(i == slowo.length()-1){
                wynik << endl;
            }
        }
    }
    return 0;
}
