#include <iostream>

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

    cout << "Podaj 1 liczbe: " << endl;
    cin >> liczba1;
    cout << "Podaj 2 liczbe: " << endl;
    cin >> liczba2;

    if(czy_anagram_cyfrowy(liczba1, liczba2)){
        cout << "TAK" << endl;
    }else{
        cout << "NIE" << endl;
    }

    return 0;
}
