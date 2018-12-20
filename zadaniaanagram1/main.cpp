#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    ifstream anagram;
    ofstream wynik;
    anagram.open("anagram.txt");
    wynik.open("wynik.txt");
    string wiersz;
    while(getline(anagram, wiersz)){
        stringstream ss;
        ss << wiersz;
        string slowo;
        int dlugosc = 0;
        bool czy_taka_sama_dlugosc = true;
        while(ss >> slowo){
            if(dlugosc == 0){
                dlugosc = slowo.length();
            } else if(slowo.length() != dlugosc){
                czy_taka_sama_dlugosc = false;
            }
        }
        if(czy_taka_sama_dlugosc){
            wynik << wiersz << endl;
        }
    }

    return 0;
}
