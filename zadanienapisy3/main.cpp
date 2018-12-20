#include <iostream>
#include <fstream>

using namespace std;

bool czytylkoztychznakow(string napis, char znak){
    int licznik = 0;
    for(int i = napis.length()-1 ; i>=0 ; i--){
        if(napis[i] != znak){
            return false;
        }
    }
    return true;
}

int main()
{
    ifstream napisy;
    ofstream wynik;
    napisy.open("napisy.txt");
    wynik.open("wynik.txt");
    string napis;
    int ile_samych_zer = 0;
    int ile_samych_jedynek = 0;

    while(napisy >> napis){
        if(czytylkoztychznakow(napis, '0')){
            ile_samych_zer++;
        }
        if(czytylkoztychznakow(napis, '1')){
            ile_samych_jedynek++;
        }
    }

    wynik << "Napisow z samych zer: " << ile_samych_zer << endl;
    wynik << "Napisow z samych jedynek: " << ile_samych_jedynek << endl;
    napisy.close();
    wynik.close();

    return 0;
}
