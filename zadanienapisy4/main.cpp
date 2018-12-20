#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream napisy;
    ofstream wynik;
    napisy.open("napisy.txt");
    wynik.open("wynik.txt");
    int wyniki[15] = {};
    string napis;

    while(napisy >> napis){
        for(int i = 2; i<=16 ; i++){
            if(napis.length() == i){
                wyniki[i - 2]++;
                break;
            }
        }
    }

    for(int i = 0 ; i<15 ; i++){
        wynik << i+2 << "-wyrazowych napisow jest: " << wyniki[i] << endl;
    }


    return 0;
}
