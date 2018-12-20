#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

unsigned int silnia(unsigned int z){
    if(z==1) return 1;
    else return z * silnia(z-1);
}

class Macierz {
public:
    double ** dane;
    unsigned int m, n;
    Macierz(int, int);
    ~Macierz();
    void wpisz();
    void wypelnij();
    double wyznacznik();
    Macierz& operator*(double);
    Macierz& operator*(const Macierz&);
    double* operator[](int);
    friend ostream& operator<<(ostream&,const Macierz&);
    friend istream& operator>>(istream&, Macierz&);
    bool operator==(const Macierz&);
};

void Macierz::wypelnij(){
    srand( time( NULL ) );
    for(int i = 0; i<m ; i++)
        for(int j = 0; j<n ; j++){
            dane[i][j] = rand() % 10;
        }
}

Macierz::~Macierz(){
    cout << "destruktor" << endl;
    for(int i = 0; i<m ; i++) delete[] dane[i];
}

bool Macierz::operator==(const Macierz& mac){
    if(m != mac.m || n != mac.n) return false;

    for(int i = 0; i<m ; i++){
        for(int j = 0; j<n ; j++)
            if(mac.dane[i][j] != dane[i][j]) return false;
    }

    return true;
}

double Macierz::wyznacznik(){
    if(n != m){
        cout << "nie mozna obliczyc wyznacznika dla nie kwadratowej macierzy" << endl;
        return 0;
    }

    if(n==2) return (double) dane[0][0] * dane[1][1] - dane[0][1] * dane[1][0];
    else if(n==1) return dane[0][0];
    else{
        int temp = 0;
        for(int k = 0; k<m ; k++){
            Macierz tempmac(m-1,n-1);
            for(int i = 0; i<m ; i++){
                if(i == k) continue;
                for(int j = 1; j<n ; j++){
                    if(i>k) tempmac.dane[i-1][j-1] = dane[i][j];
                    else tempmac.dane[i][j-1] = dane[i][j];
                }
            }
            temp += pow( -1, k+1+1 ) * dane[k][0] * tempmac.wyznacznik();
        }
        return temp;
    }
}

istream& operator>>(istream& in,Macierz& mac){
    mac.wpisz();
    return in;
}

double* Macierz::operator[](int i){
    return dane[i];
}

ostream& operator<<(ostream& out,const Macierz& mac){
    cout << endl;
    int m = mac.m;
    int n = mac.n;
    for(int i = 0; i<m ; i++){
        for(int j = 0; j<n ; j++) cout << mac.dane[i][j] << " ";
        cout << endl;
    }
    return out;
}
void Macierz::wpisz(){
    int temp = 0;
    for(int i = 0; i<m ; i++)
        for(int j = 0; j<n ; j++){
            cout << "Wprowadz element[" << i << "][" << j << "]: ";
            cin >> temp;
            dane[i][j] = temp;
        }
}

Macierz& Macierz::operator*(const Macierz& mac2){
    const Macierz* mac1 = this;
    int x = m;
    int y = mac2.n;
    int temp = 0;
    Macierz* wynik = new Macierz(x, y);
    if(mac1->n != mac2.m){
        cout << "Nie mozna pomnozyc macierzy o takich wymiarach" << endl;
        return *this;
    }
    for(int i = 0; i<x ; i++){
        for(int j = 0; j<y ; j++){
            temp = 0;
            for(int k = 0; k<n ; k++){
                temp = temp + (this->dane[i][k]) * (mac2.dane[k][j]);
            }
            wynik->dane[i][j] = temp;
        }
    }
    return *wynik;

}

Macierz::Macierz(int m, int n){
    dane = new double* [m];
    this->m = m;
    this->n = n;
    for(int i = 0; i<m ; i++) dane[i] = new double [n];
    for(int i = 0; i<m ; i++)
        for(int j = 0; j<n ; j++)
            dane[i][j] = 0;
}

Macierz& Macierz::operator*(double liczba){
    Macierz* mac = new Macierz(m, n);
    for(int i = 0; i<m ; i++)
        for(int j = 0; j<n ; j++)
            mac->dane[i][j] = dane[i][j] * liczba;
    return *mac;
}

int main() {
    cout << "Z jakiej liczv chcesz policzyc silnie?: " << endl;
    int sil = 0;
    cin >> sil;
    cout << "Silnia z " << sil << " = " << silnia(sil) << endl;

    Macierz e(2,2);
    cin >> e;
    Macierz f(2,2);
    cin >> f;

    if(e==f){
        cout << "TAAAK!" << endl;
    } else cout << "NIEEE" << endl;

    Macierz a(2,2);
    a.wpisz();
    cout << "Macierz a: " << a << endl;
    a = a * 2;
    cout << "Macierz a: " << a << endl;
    a[0][1] = 9;
    cout << "Macierz a: " << a << endl;
    Macierz b(2,5);
    b.wypelnij();
    cout << "Macierz b: " << b << endl;
    cout << "Macierz a*b: " << a*b << endl;

    cout << "Macierz a: " << a << endl;
    cout << "Wyznacznik a: " << a.wyznacznik() << endl;

    Macierz c(3,3);
    cin >> c;
    cout << "Macierz c: " << c << endl;
    cout << "Wyznacznik c: " << c.wyznacznik() << endl;

    Macierz d(4,4);
    cin >> d;
    cout << "Macierz d: " << d << endl;
    cout << "Wyznacznik d: " << d.wyznacznik() << endl;
}
