#include <iostream>
#include <cmath>

using namespace std;

int getNumber(char val){
    switch(val){
    case '0': return:
    }
}

void todec(){
    cout << "Podaj z jakiego systemu zamieniasz: " << endl;
    int system;
    cin >> system;
    cout << "Podaj liczbe ktora chcesz zamienic: " << endl;
    string liczba;
    cin >> liczba;
    int power = 0;
    while(liczba != 0){
        liczba += liczba%10 * pow(system, power);
        liczba /= 10;
    }
}

void fromdec(){

}

int main()
{
    cout << "Siema co chesz?" << endl;
    cout << "1. Z innego na dziesietny" << endl;
    cout << "2. Z dziesietnego na inny" << endl;

    int cochesz;
    cin >> cochcesz;
    if(cochesz == 1) todec(); else if (cochcesz == 2) fromdec();
    return 0;
}
