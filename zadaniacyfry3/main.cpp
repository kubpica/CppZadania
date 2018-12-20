#include <iostream>
#include <fstream>

using namespace std;

bool czy_rosnacy(string liczba){
        int cyfra = 0;

        for(int i = liczba.length()-1; i>=0 ; i--){
            if(i == liczba.length()-1) cyfra = liczba[i]; else
            if(cyfra > liczba[i]){
                cyfra = liczba[i];
            } else{
                return false;
            }
        }
        return true;
}

int main()
{
    ifstream cyfry;
    ofstream wyniki;
    cyfry.open("cyfry.txt");
    wyniki.open("wyniki.txt");
    string liczba;

    wyniki << "Liczby tworzace ciag rosnacy:" << endl;
    while(cyfry >> liczba){
        if(czy_rosnacy(liczba)){
            wyniki << liczba << endl;
        }
    }

    cyfry.close();
    wyniki.close();

    return 0;
}
