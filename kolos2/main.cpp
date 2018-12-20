//============================================================================
// Name        : kolos2.cpp
// Author      : ja
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <ctime>
using namespace std;

class Macierz{
private:
	int m, n;
	double **data;
public:
	Macierz(int, int, int);
	~Macierz();
	Macierz& operator-(const Macierz&);
	friend istream& operator>>(istream&, Macierz&);
	void wyswietl();
	void wypelnij(int, int);
	unsigned int getm() const {return m;}
	unsigned int getn() const {return n;}
	double getwar(unsigned int m,unsigned int n) const{
		if(m>this->m || n>this->n) return -1;
		return data[m][n];
	}
};

Macierz::Macierz(int m, int n = 1, int war = 0){
	this->m = m;
	this->n = n;
	data = new double*[m];
	for(int i = 0; i < m; i++) data[i] = new double[n];

	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			data[i][j] = war;
}

Macierz::~Macierz(){
	for(int i = 0; i < m; i++)
		delete[] data[i];
    delete[] data;
}

istream& operator>>(istream& in, Macierz& mac){
	int temp = 0;
	for(int i = 0; i < mac.m; i++)
			for(int j = 0; j < mac.n; j++){
				cout << "Podaj element[" << i << "]" << "[" << j << "]: ";
				cin >> temp;
				mac.data[i][j] = temp;
			}
	return in;
}

Macierz& Macierz::operator-(const Macierz& mac){
	if(mac.m != m || mac.n != n){cout << "Blad! Mozna odejmowac tylko macierze tych samych rozmiarow!" << endl; return *this;}
	Macierz* wynik = new Macierz(m, n);
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			wynik->data[i][j] = data[i][j] - mac.data[i][j];
	return *wynik;
}

void Macierz::wyswietl(){
	for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++) cout << data[i][j] << " ";
			cout << endl;
	}
	cout << endl;
}

void Macierz::wypelnij(int min = 1, int max = 10){
	srand(time(NULL));
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			data[i][j] = rand()%(max-min+1) +min;
}

class Zwierze{
private:
    int masa;
	public:
		Zwierze(int);
		virtual void polowanie(){cout << "Zwierze poluje" << endl;}
		virtual ~Zwierze();
	};

	Zwierze::Zwierze(int m){
        this->masa = m;
	}

	Zwierze::~Zwierze(){
	}

	class Lew: public Zwierze{
	    private:
		int silaryku;
		public:
			Lew(int silaryku, int masa):Zwierze(masa){this->silaryku = silaryku;}
			void polowanie(){cout << "Lew poluje" << endl;}
			~Lew();
		};

    Lew::~Lew(){

    }

	class Lis: public Zwierze{
	    private:
            int punktysptytu;
        public:
				Lis(int punktysptytu, int masa):Zwierze(masa){this->punktysptytu = punktysptytu;}
				void polowanie(){cout << "Lis poluje" << endl;}
				~Lis();
			};

     Lis::~Lis(){

    }

	class Wilk: public Zwierze{
	    private:
		int punktyglodu;
			public:
				Wilk(int punktyglodu, int masa):Zwierze(masa){this->punktyglodu = punktyglodu;}
				void polowanie(){cout << "Wilk poluje" << endl;}
				~Wilk();
			};

    Wilk::~Wilk(){

    }

int main() {

	cout << "halo halo" << endl;
	Macierz* a = new Macierz(4,1,3);
	Macierz* b = new Macierz(4);
	cout << "Macierz bmnieja:" << endl;
	Macierz bmnieja = *b - *a;
	bmnieja.wyswietl();
	Macierz c = (Macierz) 3;
	cout << "Macierz c:" << endl;
	c.wyswietl();

	Macierz d(3,4);
	d.wypelnij(1, 10);
	cout << "Macierz d:" << endl;
	d.wyswietl();
	cout << "dM: " << d.getm() << endl;
	cout << "dN: " << d.getn() << endl;
	cout << "d(0, 1): " << d.getwar(0,1) << endl;
	cout << "d(1, 6): " << d.getwar(1,6) << endl;

	Macierz d2(3,4);
	cin >> d2;
	cout << "Macierz d2" << endl;
	d2.wyswietl();

	Wilk wilczur(1,2);
	Zwierze * wskdozw;
	wskdozw = &wilczur;
	wskdozw->polowanie();
	Lis * wskdoLis = new Lis(1,5);
	wskdozw = wskdoLis;
	wskdozw->polowanie();

	while(1){
        Macierz* inf = new Macierz(2,2,2);
        delete inf;
	}

	return 0;
}
