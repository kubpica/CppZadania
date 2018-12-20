#include <iostream>
#include <fstream>

using namespace std;

string odwroc_haslo(string haslo){
    string odwrocone;
    for(int i = haslo.length()-1; i>=0 ; i--){
        odwrocone = odwrocone + haslo[i];
    }
    return odwrocone;
}

int main()
{
    ifstream hasla;
    ofstream wynik;
    hasla.open("hasla.txt");
    wynik.open("wynik.txt");
    string haslo;
    string haslo_odwrocone;

    while(hasla >> haslo){
        haslo_odwrocone = odwroc_haslo(haslo);
        if(haslo == haslo_odwrocone){
            wynik << haslo << endl;
        }
    }
    return 0;
}
