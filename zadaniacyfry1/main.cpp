#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream cyfry;
    ofstream wynik;
    cyfry.open("cyfry.txt");
    wynik.open("wynik.txt");
    int ile = 0;

    int cyfra;

    while(cyfry >> cyfra){
        if(cyfra%2 == 0){
            ile++;
        }
    }

    wynik << "Tyle jest parzystych: " << ile << endl;
    return 0;
}
