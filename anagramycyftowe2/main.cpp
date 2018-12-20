#include <iostream>
#include <fstream>

using namespace std;

bool czy_anagram_cyfrowy(string liczba1, string liczba2){
    if(liczba1.length() != liczba2.length()){
        return false;
    }

    int cyfry1[liczba1.length()];
    int cyfry2[liczba2.length()];
    for(int i = liczba1.length(); i>0 ; i--){
        cyfry1[i-1] = (int) liczba1[i-1] - 48;
    }
    for(int i = liczba2.length(); i>0 ; i--){
        cyfry2[i-1] = (int) liczba2[i-1] - 48;
    }

    /*cout << liczba1 << " na cyfry:" << endl;
    for(int i = liczba1.length(); i>0 ; i--){
        cout << cyfry1[i-1] << " ";
    }
    cout << endl;
    cout << liczba2 << " na cyfry:" << endl;
    for(int i = liczba2.length(); i>0 ; i--){
        cout << cyfry2[i-1] << " ";
    }
    cout << endl;*/

    bool czy_bylo = false;
    for(int i = liczba1.length(); i>0 ; i--){
            czy_bylo = false;
           for(int j = liczba2.length(); j>0 ; j--){
                if(cyfry1[i-1] == cyfry2[j-1]){
                    cyfry2[j-1] = -1;
                    czy_bylo = true;
                    break;
                }
           }
           if(czy_bylo==false) return false;
    }
    return true;
}

int main()
{
    string liczba1;
    string liczba2;
    ifstream dane;
    dane.open("dane.txt");
    ofstream wynik;
    wynik.open("anagramy.txt");
    int ilosc = 0;
    dane >> ilosc;
    while(dane >> liczba1){
        dane >> liczba2;
        wynik << liczba1 << " ";
        wynik << liczba2 << " ";
        if(czy_anagram_cyfrowy(liczba1, liczba2)){
        wynik << "tak" << endl;
        }else{
        wynik << "nie" << endl;
        }
    }

    dane.close();
    wynik.close();

    return 0;
}
