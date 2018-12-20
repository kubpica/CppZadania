#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream szyfry;
    ifstream klucze;
    ofstream wynik;
    szyfry.open("sz.txt");
    klucze.open("klucze2.txt");
    wynik.open("wynik.txt");
    string szyfr;
    string klucz;

    while(szyfry >> szyfr){
        klucze >> klucz;
        int i_klucza = 0;
        for(int i = 0; i<szyfr.length() ; i++){
            if(i_klucza == klucz.length()){
                i_klucza = 0;
            }
            int kodslowa = szyfr[i] - (klucz[i_klucza] - 64);
            if(kodslowa < 65){
                kodslowa = kodslowa + 26;
            }
            char znakslowa = kodslowa;
            wynik << znakslowa;
            if(i == szyfr.length()-1){
                wynik << endl;
            }
            i_klucza++;
        }
    }
    szyfry.close();
    wynik.close();
    klucze.close();
    return 0;
}
