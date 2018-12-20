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
            stringstream ss;
            ss << wiersz;
            string slowo_pierwsze;
            string slowo_next;
            ss >> slowo_pierwsze;
            bool czy_anagramy = true;
            while(ss >> slowo_next){
                for(int i = slowo_next.length()-1 ; i>=0 ; i--){
                bool czy_istnieje_taki_znak = false;
                    for(int j = slowo_pierwsze.length()-1 ; j>=0 ; j--){
                        if(slowo_pierwsze[j] == slowo_next[i]){
                            czy_istnieje_taki_znak = true;
                        }
                    }
                if(czy_istnieje_taki_znak == false){
                    czy_anagramy = false;
                }
                }
            }
            if(czy_anagramy == true){
                wynik << wiersz << endl;
            }
        }
    }

    return 0;
}
