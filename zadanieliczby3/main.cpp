#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    ifstream liczby;
    ofstream wynik;
    liczby.open("liczby.txt");
    wynik.open("wynik.txt");
    string liczba;
    int najwieksza = 0;
    int najmniejsza = 0;
    int ile = 0;

    while(liczby >> liczba){
        for(int i = liczba.length()-1 ; i>0 ; i--){
            if((liczba[i] - '0') >= (liczba[i-1] - '0')){
                if(i == 1){
                    ile++;
                    int liczbaint;
                    stringstream ss;
                    ss << oct << liczba;
                    ss >> liczbaint;
                    if(liczbaint > najwieksza){
                        najwieksza = liczbaint;
                    }
                    if(liczbaint < najmniejsza || najmniejsza == 0){
                        najmniejsza = liczbaint;
                    }
                }
            }else{
                break;
            }
        }
    }

    wynik << "Ile: " << dec << ile << endl;
    wynik << "Najmniejsza: " << oct << najmniejsza << endl;
    wynik << "Najwieksza: " << oct << najwieksza << endl;
    liczby.close();
    wynik.close();

    return 0;
}
