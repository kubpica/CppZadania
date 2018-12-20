#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string napis;
    ifstream napisy;
    ofstream rozwiazanie;
    int ile = 0;
    napisy.open("napisy.txt");
    rozwiazanie.open("rozwiazanie.txt");
    cout << "bigos" << endl;

    while(napisy >> napis){
        cout << napis << endl;
        if(napis.length()%2 == 0){
            ile++;
        }
    }

    rozwiazanie << "Jest " << ile << " parzystych napisow!!" << endl;

    return 0;
}
