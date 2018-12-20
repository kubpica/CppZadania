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
    int najdluzszy = 0;
    int najkrotszy = 99999;
    int ktory = 0;
    int ktory_najdl = 0;
    int ktory_najkr = 0;

    while(dziennik >> dlugosc){
        ktory++;
        if(dlugosc > najdluzszy){
            najdluzszy = dlugosc;
            ktory_najdl = ktory;
        }
        if(dlugosc < najkrotszy){
            najkrotszy = dlugosc;
            ktory_najkr = ktory;
        }
    }

    wynik << "Najdluzszy: " << najdluzszy << " uzyskany w " << ktory_najdl << " dniu." << endl;
    wynik << "Najkrutszy: " << najkrotszy << " uzyskany w " << ktory_najkr << " dniu." << endl;
    return 0;
}
