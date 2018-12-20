#include <iostream>
#include <fstream>

using namespace std;

int ileznakow(string napis, char znak){
    int licznik = 0;
    for(int i = napis.length()-1 ; i>=0 ; i--){
            cout << "napis[" << i << "]: " << napis[i] << " znak: " << znak << endl;
        if(napis[i] == znak){
            cout << "tru" << endl;
            licznik++;
        }
    }
    return licznik;
}

int main()
{
    ifstream napisy;
    ofstream wynik;
    napisy.open("napisy.txt");
    wynik.open("wynik.txt");
    string napis;
    int ile = 0;
    int ile_z_brakiem_tez = 0;

    while(napisy >> napis){
        int ilejedynek = ileznakow(napis, '1');
        int ilezer = ileznakow(napis, '0');
        if(ilejedynek == ilezer){
            ile_z_brakiem_tez++;
            if(ilejedynek != 0 || ilezer != 0) ile++;
        }
    }

    wynik << "Napisow z taka sama iloscia 1 co 0 jest: " << ile << endl;
    wynik << "No chyba ¿e zakladamy ze jak jest zero 1 i zero 0 to te¿ sie liczy - wtedy: " << ile_z_brakiem_tez << endl;
    napisy.close();
    wynik.close();
    cin >> ile;

    return 0;
}
