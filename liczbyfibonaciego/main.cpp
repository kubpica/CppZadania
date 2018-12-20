#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool czy_fibonacciego(int liczba){
    int fib1 = 0;
    int fib2 = 1;
    int suma = 0;

    do{
        suma = fib1 + fib2;
        if(suma == liczba){
            return true;
        }
        fib1 = fib2;
        fib2 = suma;
    }while(suma < liczba);
    return false;
}

int main()
{
    ifstream dane;
    ofstream wynik;
    ofstream liczbyfib;
    liczbyfib.open("liczbyfib.txt");
    dane.open("dane.txt");
    wynik.open("wynik.txt");
    int liczba = 0;
    int najwieksza = 0;
    int najmniejsza = -1;

    wynik << "a) " << endl;
    while(dane >> liczba){
        if(czy_fibonacciego(liczba)){
            if(najmniejsza == -1) najmniejsza = liczba;
            if(liczba < najmniejsza) najmniejsza = liczba;
            if(liczba > najwieksza) najwieksza = liczba;
            wynik << liczba << endl;
            liczbyfib << liczba << endl;
        }
    }

    wynik << "b) " << endl;
    wynik << "Najwieksza: " << najwieksza << endl;
    wynik << "Najmniejsza: " << najmniejsza << endl;

    liczbyfib.close();
    ifstream lfib;
    lfib.open("liczbyfib.txt");

    int liczba1 = 0;
    int liczba2 = 0;
    int najdl = 0;
    int dl = 1;
    vector < int > ciag;
    vector < int > ciag_najdl;
    lfib >> liczba1;
    while(lfib >> liczba2){
        if(liczba2 > liczba1){
            dl++;
            if(dl == 2) ciag.push_back(liczba1);
            ciag.push_back(liczba2);
        }else{
            if(dl > najdl){
                najdl = dl;
                ciag.swap(ciag_najdl);
            }
            ciag.clear();
            dl = 1;
        }
        liczba1 = liczba2;
    }

    wynik << "c) " << endl;
    for(size_t i = 0; i < ciag_najdl.size(); i++){
        wynik << ciag_najdl[i] << endl;
    }
    wynik << "dlugosc: " << najdl << endl;
    return 0;
}
