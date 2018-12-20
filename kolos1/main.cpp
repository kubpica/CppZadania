//============================================================================
// Name        : kolokwium.cpp
// Author      : ja
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

void zad1(){
	int tab1[10] = {0,0,0,0,0,0,0,0,0,0};
	for(int i = 0; i<10; i++){
			tab1[i] = 0;
	}
	int tab2[10] = {1,2,3,4,5,6,7,8,9,10};
	int s = 0;
	for(int i = 0; i<10; i++){
		s += tab2[i];
	}
	cout << "Srednia arytmetyczna wartosci tab2 = " << s/10.0 << endl;
	int tab3[10];
	int s2 = 0;
	for(int i = 0; i<10; i++){
		tab3[i]=i;
		s2 += tab3[i];
	}
	double sredniatab3 = s2/10.10;
	int najmn_odl = abs(tab3[0]-sredniatab3);
	int najbl_i = 0;
	for(int i = 0; i<10; i++){
		if(abs(tab3[i]-sredniatab3) < najmn_odl){
			najmn_odl = abs(tab3[i]-sredniatab3);
			najbl_i = i;
		}
	}
	cout << "Numer indeksu wartosci tab3 najblizszej do sredniej arytm tab3 to: " << najbl_i << endl;
}

void zad2(){
	char tab1[15];
	for(int i = 0; i<15; i++){
		tab1[i] = 'z';
	}

	int tab2[3][5];
	for(int i = 0; i<3; i++){
		for(int j = 0; j<5; j++){
			tab2[i][j] = i+j;
			if( (i+j)%2==0 ){
				cout << tab2[i][j] << endl;
			}else{
				cout << " " << endl;
			}
		}
	}
}

//zad3:

struct punkt{
	double x;
	double y;
	double z;
};

struct odcinek{
	punkt punkta;
	punkt punktb;
};

struct trojkat{
	odcinek boka;
	odcinek bokb;
	odcinek bokc;
};

double dlugoscboku(odcinek bok1){
	return pow( pow(bok1.punkta.x-bok1.punktb.x,2)+pow(bok1.punkta.y-bok1.punktb.y,2)+pow(bok1.punkta.z-bok1.punktb.z,2) ,0.5);
}

void zad3(){
	punkt punkt1 = {0, 0, 0};
	punkt punkt2 = {5, 0, 0};

	odcinek bok1 = {punkt1, punkt2};
	double dlugoscboku1 = pow( pow(bok1.punkta.x-bok1.punktb.x,2)+pow(bok1.punkta.y-bok1.punktb.y,2)+pow(bok1.punkta.z-bok1.punktb.z,2) ,0.5);
	cout << "Dlugosc boku bok1 wynosi " << dlugoscboku1 << endl;
	odcinek bok2 = { {4,5,6}, {2,3,5} };
	odcinek bok3 = { {1,2,3}, {4,5,6} };

	trojkat trojkat1 = {bok1, bok2, bok3};
	if( dlugoscboku(trojkat1.boka)+dlugoscboku(trojkat1.bokb)>dlugoscboku(trojkat1.bokc) &&
		dlugoscboku(trojkat1.bokb)+dlugoscboku(trojkat1.bokc)>dlugoscboku(trojkat1.boka) &&
		dlugoscboku(trojkat1.bokc)+dlugoscboku(trojkat1.boka)>dlugoscboku(trojkat1.bokb)){
			cout << "trojkat1 to jest poprawny trojkat" << endl;
	}else{
			cout << "trojkat1 to niepoprawny trojkat - z takich bokow nie mozna utworzyc trojkata" << endl;
	}

}

int main() {

	char a;

	while(1){
		cout << "Wybierz jedno z zadan:" << endl;
		cout << "1 - tablice" << endl;
		cout << "2 - tablica dwuwymiarowa" << endl;
		cout << "3 - struktury" << endl;
		cout << "q lub Q aby wyjsc" << endl;
		cin >> a;

		switch(a){
			case '1':
				zad1();
				break;
			case '2':
				zad2();
				break;
			case '3':
				zad3();
				break;
			default:
				cout << "Nie ma takiego zadania" << endl;
				break;
		}

		if(a == 'q' || a == 'Q'){
			cout << "Wychodze!" << endl;
			break;
		}
	}
	return 0;
}
