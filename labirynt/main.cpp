#include <iostream>
#include <fstream>

using namespace std;

int nwd(int l1, int l2){
    int najw_dzielnik = 0;
    int i = 1;
    while(1){
        if(l1%i == 0 && l2%i == 0){
            if(i > najw_dzielnik){
                najw_dzielnik = i;
            }
        }
        i++;
        if(l1<i || l2<i){
            break;
        }
    }
    return najw_dzielnik;
}

int main()
{
    ifstream dane;
    ofstream wynik;
    dane.open("dane.txt");
    wynik.open("wynik.txt");
    int ile_wierszy = 0;
    int ile_liczb_w_wierszu = 0;
    dane >> ile_wierszy;
    dane >> ile_liczb_w_wierszu;
    cout << "wierszy: " << ile_wierszy << endl;
    cout << "kolumn: " << ile_liczb_w_wierszu << endl;
    int liczba = 0;
    int ktory_wiersz = 0;
    int ktora_kolumna = 0;

    int labirynt[ile_wierszy][ile_liczb_w_wierszu];
    while(dane >> liczba){
        labirynt[ktory_wiersz][ktora_kolumna] = liczba;
        ktora_kolumna++;
        if(ktora_kolumna == ile_liczb_w_wierszu){
            ktora_kolumna = 0;
            ktory_wiersz++;
            if(ktory_wiersz == ile_wierszy){
                break;
            }
        }
    }

    int krul_wiersz = 0;
    int krul_kolumna = 0;
    int krul = labirynt[krul_wiersz][krul_kolumna];
    wynik << krul << " ";
    int zamek = labirynt[ile_wierszy-1][ile_liczb_w_wierszu-1];
    do{
        if( nwd(krul, labirynt[krul_wiersz+1][krul_kolumna]) == 1 ){
            krul_wiersz++;
            krul = labirynt[krul_wiersz][krul_kolumna];
            wynik << krul << " ";
        } else if( nwd(krul, labirynt[krul_wiersz][krul_kolumna+1]) == 1 ){
            krul_kolumna++;
            krul = labirynt[krul_wiersz][krul_kolumna];
            wynik << krul << " ";
        } else {
            cout << "RIP" << endl;
            break;
        }
    }while( !(krul_wiersz == ile_wierszy-1 && krul_kolumna == ile_liczb_w_wierszu-1) );

    cin >> liczba;
    return 0;
}
