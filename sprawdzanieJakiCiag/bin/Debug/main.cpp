#include <iostream>
#include <fstream> //potrzebne do odczytywania i zapisywania plikow txt
#include <sstream> //potrzebne do stringstream ciag

using namespace std;

int main()
{
    ifstream ciagi;
    ciagi.open("ciagi.txt"); //otwieram plik ciagi.txt
    ofstream wynik;
    wynik.open("wyniki.txt");
    stringstream ciag;
    string ciag_string;
    int liczba1 = 0;
    int liczba2 = 0;
    bool czy_arytmetyczny = false;
    bool czy_monotoniczny = false;
    bool czy_rosnacy = false;
    bool czy_staly = false;
    bool czy_pierwszy_obieg = false;
    int roznica = 0;

    while(getline( ciagi, ciag_string )){ //tu pobieram sobie ca³y 1 wiersz i przypisuje go do ciag_string - petla bedzie dzialac dopóki nie skoncza sie wiersze w ciagi.txt
        ciag.clear(); //czyszcze stringstream musi to byc
        ciag << ciag_string; //przypisuje sobie zawartosc wiersza (czyli ciag) do strumienia ciag dzieki temu latwo bede mogl odczytywac kolejne wyrazy ciagu w nastepnej petli while
        cout << ciag_string << endl;
        czy_arytmetyczny = true; //tu jakby z gory zakladam ze wszytko jest prawdziwe...
        czy_monotoniczny = true;
        czy_rosnacy = true;
        czy_staly = true;
        czy_pierwszy_obieg = true;
        ciag >> liczba1;
        while(ciag >> liczba2){ // ale potem to sprawdzam w tej petli
                //cout << liczba1 << " " << liczba2 << endl;
                if(czy_pierwszy_obieg){
                    roznica = liczba2 - liczba1;
                    if(liczba2 < liczba1) czy_rosnacy = false; else czy_rosnacy = true; //tu sprawdzam po pierwszych 2 wyrazach ciagu czy jest rosnacy czy malejacy...
                    if(liczba2 != liczba1) czy_staly = false; else czy_staly = true; //albo czy staly...
                    czy_pierwszy_obieg = false;
                } else{ //ale co jak ciag nie jest monotoniczny? wiec musze sprawdzic tez pozostale wyrazy ciagu
                    if(roznica != (liczba2 - liczba1)) czy_arytmetyczny = false;
                    if(liczba2 < liczba1 && czy_rosnacy == true){
                        czy_monotoniczny = false; //po 2 pierwszych wyrazach ciagu myslalem ze jest rosnacy a tu nagle liczba2 < liczba1 omg czyli ciag ten jest niemonotoniczny!
                        czy_staly = false; //nie jest wiec tez staly
                    } else //tu nie musi byc tego else ale moze
                    if(liczba2 > liczba1 && czy_rosnacy == false){
                        czy_monotoniczny = false; //po 2 pierwszych wyrazach ciagu myslalem ze jest malejacy a tu nagle liczba2 > liczba1 omg czyli ciag ten jest niemonotoniczny!
                        czy_staly = false;
                    }
                    if(liczba2 == liczba1){
                        czy_monotoniczny = false; //skoro dwa wyrazy w ciagu sa rownie to ciag nie jest ani rosnacy ani malejacy
                    } else czy_staly = false;
                }
                liczba1 = liczba2;
        }
        //wypisanie wyniku do wynik:
        if(czy_arytmetyczny) wynik << "ciag arytmetyczny i "; else wynik << "ciag niearytmetyczny i ";
        if(czy_staly) wynik << "staly" << endl;
        else if(!czy_monotoniczny) wynik << "niemonotoniczny" << endl;
        else if(czy_rosnacy) wynik << "rosnacy" << endl;
        else if(!czy_rosnacy) wynik << "malejacy" << endl;

        //wypisanie wyniku do konsoli:
        if(czy_arytmetyczny) cout << "ciag arytmetyczny i "; else cout << "ciag niearytmetyczny i ";
        if(czy_staly) cout << "staly" << endl;
        else if(!czy_monotoniczny) cout << "niemonotoniczny" << endl;
        else if(czy_rosnacy) cout << "rosnacy" << endl;
        else if(!czy_rosnacy) cout << "malejacy" << endl;
    }
    cin >> roznica; // tak o ¿eby konsola nie znikala
    return 0;
}
