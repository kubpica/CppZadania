#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    ifstream dane;
    ofstream wynik;
    dane.open("dane.txt");
    wynik.open("wynik.txt");
    int liczba1;
    int liczba2;
    int sumadzielnikow1 = 0;
    int sumadzielnikow2 = 0;
    int liczba_dzielnikow = 0;
    int najmniejdzielnikow = -1;
    int liczba1_najmniejdz;
    int liczba2_najmniejdz;
    int zaprzyjaznionych = 0;
    while(dane >> liczba1){
        dane >> liczba2;
        liczba_dzielnikow = 0;
        sumadzielnikow1 = 0;
        sumadzielnikow2 = 0;
        for(int i = liczba1-1; i>0 ; i--){
            if(liczba1%i == 0){
                sumadzielnikow1 += i;
                liczba_dzielnikow++;
            }
        }
        for(int i = liczba2-1; i>0 ; i--){
            if(liczba2%i == 0){
                sumadzielnikow2 += i;
                liczba_dzielnikow++;
            }
        }
        if(sumadzielnikow1 == liczba2 && sumadzielnikow2 == liczba1){
            zaprzyjaznionych++;
            if(najmniejdzielnikow == -1){
                najmniejdzielnikow = liczba_dzielnikow;
                liczba1_najmniejdz = liczba1;
                liczba2_najmniejdz = liczba2;
            }
            if(liczba_dzielnikow < najmniejdzielnikow){
                najmniejdzielnikow = liczba_dzielnikow;
                liczba1_najmniejdz = liczba1;
                liczba2_najmniejdz = liczba2;
            }
        }

    }

    wynik << "a) " << zaprzyjaznionych << endl;
    wynik << "b) " << "Najmniej dzielnikow, bo " << najmniejdzielnikow << " posiada para liczb " << liczba1_najmniejdz << " i " << liczba2_najmniejdz << endl;
    wynik << "dzielniki " << liczba1_najmniejdz << ": ";
    for(int i = liczba1_najmniejdz-1; i>0 ; i--){
        if(liczba1_najmniejdz%i == 0){
            wynik << i << " ";
        }
    }
    wynik << endl;
    wynik << "dzielniki " << liczba2_najmniejdz << ": ";
    for(int i = liczba2_najmniejdz-1; i>0 ; i--){
        if(liczba2_najmniejdz%i == 0){
            wynik << i << " ";
        }
    }

    return 0;
}
