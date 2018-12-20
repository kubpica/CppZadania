#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream hasla;
    ofstream wynik;
    hasla.open("hasla.txt");
    wynik.open("wynik.txt");
    string haslo;

    while(hasla >> haslo){
        for(int i = haslo.length()-1; i>0 ; i--){
        if(haslo[i] + haslo[i-1] == 220){
            wynik << haslo << endl;
            break;
        }
        }
    }

    hasla.close();
    wynik.close();
    return 0;
}
