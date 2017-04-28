#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <iomanip> 
#define debug(x) cout << #x <<":" <<x <<endl;

using namespace std;

void zad1();
void zamien(float *a, float *b);

void zad2();
int maksimum(int *tab,int n);
int minimum(int *tab,int n);
float srednia_arytmetyczna(int *tab,int n);
int ile_mniejszych_od_sredniej(int *tab,int n);

void zad3();
void wczytaj_macierz(float** M, int m, int n);
void wyswietl_macierz(float** M, int m, int n);
void pomnoz_macierz_przez_liczbe(float x, float** M1,float** M2, int m, int n);
bool dodaj_macierze(float** M1, float** M2, float** M3, int m1, int n1, int m2, int n2);
bool pomnoz_macierze(float** M1, float** M2, float** M3, int m1, int n1, int m2, int n2);

void zad4();
void filtruj(float* tab, float* tab_f, int n, int k);
void wyswietl_tablice(float* tab, int n);

void zad5();
double P0 ( double x );
double P1 ( double x );
double P2 ( double x );
double P3 ( double x );
double P4 ( double x );
double P5 ( double x );
double calka_iloczynu(double a,double b, double (*f)(double), double (*g)(double));

int main(){
srand ( time ( NULL ) );
int n;
do{
	cout << "Podaj numer zadania (1-5) (0 zeby zakonczyc):\n"
			<<"1. Zamiana liczb\n"
			<<"2. Rozstep ciagu / ile mniejszych od sredniej\n"
			<<"3. Macierze\n"
			<<"4. Tablice\n"
			<<"5. Calka\n>>";
	cin >> n;
	system("cls");
	switch(n){
		case 1:
			zad1();
			break;
		case 2:
			zad2();
			break;
		case 3:
			zad3();
			break;
		case 4:
			zad4();
			break;
		case 5:
			zad5();
			break;
		case 0:
			break;
		default:
			cout << "Niewlasciwa liczba!\n";
			system("pause");
			system("cls");
			break;	
	}
}while(!(n==0));

return 0;
}

void zad1(){

float a=0, b=0;

cout << "Podaj a=";
cin >> a;
cout << "Podaj b=";
cin >> b;

cout << "Przed zamiana a="<<a<<", zas b="<<b<<endl;
zamien(&a,&b);
cout << "Po zamianie a="<<a<<", zas b="<<b<<endl;

system("pause");
system("cls");
}

void zamien(float *a, float *b){
swap(*a,*b);
}

void zad2(){
int N=0;

do{
cout << "Podaj ilosc elementow\n>> ";
cin >> N;

if(N<1){
	cout << "N musi byc wieksze od 0!\n";
	system("pause");
	system("cls");
}
}while(N<1);

int *tab = new int[N];

for(int i=0; i<N; i++){
	if(N-i==1){
		cout << "Podaj kolejny element (pozostal "<<N-i<<" element)\n>> ";
	}
	else if( N-i > 1 && N-i < 5){
		cout << "Podaj kolejny element (pozostaly "<<N-i<<" elementy)\n>> ";
	}
	else{
		cout << "Podaj kolejny element (pozostalo "<<N-i<<" elementow)\n>> ";
	}
	cin >> tab[i];
	cout << endl;
}

cout << "Rozstep ciagu wynosi:"<<maksimum(tab,N)-minimum(tab,N)<<endl;
cout << "Ilosc elementow mniejszych od sredniej:" << ile_mniejszych_od_sredniej(tab,N)<<endl;

delete []tab;

system("pause");
system("cls");
}

int maksimum(int *tab,int n){
	int m=*tab;
	for(int i=1; i<n; i++){
		if(*(tab+i)>m){
			m=*(tab+i);
		}
	}
	return m;
}

int minimum(int *tab,int n){
	int m=*tab;
	for(int i=1; i<n; i++){
		if(*(tab+i)<m){
			m=*(tab+i);
		}
	}
	return m;
}

float srednia_arytmetyczna(int *tab,int n){
	long long int iSuma= 0;
	
	for(int i=0; i<n; i++){
		iSuma+=*(tab+i);
		//debug(iSuma);
	}
	return (float)iSuma/(float)n;

}

int ile_mniejszych_od_sredniej(int *tab,int n){

long long int iSuma= 0;
int ile=0;
	
	for(int i=0; i<n; i++){
		iSuma=(*tab+i);
	}
	float Srednia=srednia_arytmetyczna(tab,n);
	
for(int i=0; i<n; i++){
		if(*(tab+i)<Srednia){
			ile++;
		}
	}

	return ile;
}

void zad3(){
int m1,n1,m2,n2; //deklaracja wymiarow macierzy
    //wczytywanie wymiarow macierzy A:
    cout<<"Podaj ilosc wierszy macierzy A: ";
    cin>>m1;
    cout<<"Podaj ilosc kolumn macierzy A: ";
    cin>>n1;
    //alokowanie miejsce dla macierzy A:
    float** A = new float*[m1];
    
    for (int i=0;i<m1;i++) A[i] = new float[n1];
    
    //wczytujemy macierz A:
    
    wczytaj_macierz(A,m1,n1);
    //wczytywanie wymiarow macierzy B:
    cout<<"Podaj ilosc wierszy macierzy B: ";
    cin>>m2;
    cout<<"Podaj ilosc kolumn macierzy B: ";
    cin>>n2;
    //alokowanie miejsce dla macierzy B:
    float** B = new float*[m2];
    for (int i=0;i<m2;i++) B[i] = new float[n2];
    //wczytujemy macierz B:
    wczytaj_macierz(B,m2,n2);
    //wyswietlamy obie macierze:
    cout<<"macierz A:"<<endl;
    wyswietl_macierz(A,m1,n1);
    cout<<"macierz B:"<<endl;
    wyswietl_macierz(B,m2,n2);
    
    
    //wykonujemy obliczenia 0.3*A-1.4*B (o ile to mozliwe),
    //a jesli nie mozliwe wyswietlamy odpowiedni komunikat:
    //- zaalokujmy pamiec na wynik 0.3*A:
    float** A1 = new float*[m1];
    for (int i=0;i<m1;i++) A1[i] = new float[n1];
    //- wykonanie dzialania 0.3*A:
    pomnoz_macierz_przez_liczbe(0.3,A,A1,m1,n1);
    //- wyswietlmy macierz A1:
    cout<<"Macierz 0.3A:"<<endl;
    wyswietl_macierz(A1,m1,n1);
    //- zaalokuj pamiec na wynik -1.4*B:
    float** B1 = new float*[m2];
    for (int i=0;i<m2;i++) B1[i] = new float[n2];
    //- wykonaj dzialanie -1.4*B:
    pomnoz_macierz_przez_liczbe(-1.4,B,B1,m2,n2);
    //- wyswietl macierz B1:
    cout<<"Macierz -1.4B:"<<endl;
    wyswietl_macierz(B1,m2,n2);
    //- zaalokuj pamiec na macierz C=0.3A-1.4B:
    float** C = new float*[m2];
    for (int i=0;i<m2;i++) C[i] = new float[n2];
    //- wykonaj dzialanie, jesli to mozliwe:
    if (dodaj_macierze(A,B,C,m1,n1,m2,n2)) {
         //wyswietl wynik:
         cout<<"macierz C=0.3*A-1.4*B:"<<endl;
         wyswietl_macierz(C,m1,n1);
    } else 
         cout<<"Dzialanie niewykonalne"<<endl;  
         
	float** D = new float*[m1];
	for(int i = 0 ; i < m2 ; i++ ){D[i]=new float[n2];}
    
	if (pomnoz_macierze(A,B,D,m1,n1,m2,n2)) {
         //wyswietl wynik:
         cout<<"Pomnozona macierz:"<<endl;
         wyswietl_macierz(D,m1,n2);
    } else 
         cout<<"Dzialanie niewykonalne"<<endl; 
	
    //zwalniamy pamiec:     
    delete [] A;
    delete [] B;
    delete [] C;
	delete [] D;
    delete [] A1;
    delete [] B1;
 	
 	system("pause");
 	system("cls");
 
}
 
void wczytaj_macierz(float** M, int m, int n) {
     float** end_r = M+m;
     int k = 1;
     for (float** i = M;i<end_r;i++) {
         float* end_c = *i+n;
         int l = 1;
         for (float* j = *i;j<end_c;j++) {
             cout<<"Podaj element z "<<k<<" wiersza i "<<l<<" kolumny: ";
             cin>>*j;
             l++;    
         }
         k++;    
     }
}

void wyswietl_macierz(float** M, int m, int n) {
      float** end_r = M+m;
      int k = 1;
      for (float** i = M;i<end_r;i++) {
          float* end_c = *i+n;
          for (float* j = *i;j<end_c;j++)
              cout<<*j<<" ";
          cout<<endl;   
       }    
}

void pomnoz_macierz_przez_liczbe(float x, float** M1, float** M2, int m, int n) {
     for (int i=0;i<m;i++)
         for (int j=0;j<n;j++)
             M2[i][j] = x*M1[i][j];     
}

bool dodaj_macierze(float** M1, float** M2, float** M3, int m1, int n1, int m2, int n2) {
     if (m1 == m2 && n1 == n2) {
        for (int i=0;i<m1;i++)
            for (int j=0;j<n1;j++)
                M3[i][j] = M1[i][j]+M2[i][j];
        return true;
     } else return false;    
}

bool pomnoz_macierze(float** M1, float** M2, float** M3, int m1, int n1, int m2, int n2){
	if ( n1 == m2 ){	
		for ( int i = 0 ; i < m1 ; i++ ){
			for ( int j = 0 ; j < n2 ; j++ ){
				float fSuma=0;
				for(int p = 0 ; p < m2 ; p++ ){
					fSuma += M1[i][p]*M2[p][j];
				}
				M3[i][j]=fSuma;
			}	
		}
		return true;
	}
	else return false;
}

void zad4(){
	//1) wczytujemy rozmiar tablicy n i parametr k:
	int n=0, k=0;
	 do{
 	cout << "Podaj rozmiar tablicy n:\n>>";
 	cin >> n;
 	cout << "Podaj parametr k:\n>>";
 	cin >> k;
 	if(n<1){
	 cout << "Zly rozmiar n!\n";
		system("pause");
		system("cls");
	 }
 	else if(!(n>2*k)){
		cout << "Zly prametr k!\n";
		system("pause");
		system("cls");
	}
 }while(n<1 || !(n>2*k));
 
    //2) alokujemy miejsce w pamieci na tablice tab i tab_f:
 	float *tab = new float[n];
 	float *tab_f = new float [n-2*k];
 	
    //3) wypelniamy tablice tab losowymi wartosciami z przedzialu [-1,1]:
    for (int i=0;i<n;i++)
        *(tab+i) = (rand() % 101)*0.01;
        
	 cout << "Tablica tab:\n"; //komunikat, ktora tablice wyswietlamy
    wyswietl_tablice(tab,n); //wyswietlamy tablice tab
    //3) wywolujemy funkcje filtruj:
    filtruj(tab,tab_f,n,k);
 
    //4) wyswietlamy obie tablice:
    cout << "Tablica tab:\n"; //komunikat, ktora tablice wyswietlamy
    wyswietl_tablice(tab,n); //wyswietlamy tablice tab
    cout << "Tablica tab_f:\n"; //komunikat, ktora tablice wyswietlamy
    wyswietl_tablice(tab_f,n-2*k); //wyswietlamy tablice tab_f
 
    //5) zwalniamy pamiec zarezerwowana na tablice tab i tab_f:
    delete []tab;
    delete []tab_f;

	system("pause");
	system("cls");
}

void filtruj(float* tab, float* tab_f, int n, int k) {
     //w petli for wyznaczamy i-ty element tablicy tab_f
     //jako srednia z elementow tab[i-k], tab[i-k+1], ..., tab[i], 
     //tab[i+1], tab[i+2], ..., tab[i+k]
     for (int i=k; i<n-k;i++) {
         //wyznaczamy srednia elementow odpowiednich 
         //elementow tablicy tab i zapisujemy ja jako
         //i-ty element tablicy tab_f
         float suma = 0; //ustawiamy poczatkowa wartosc sumy
         for (int j=-1*k;j<=k;j++){
             suma += tab[i+j]; //zwiekszamy sume o kolejny element tablicy tab
         }
         tab_f[i-k] = suma/(float)(2*k+1); //zapisujemy srednia do tablicy tab_f   
     }
}

void wyswietl_tablice(float* tab, int n) {
     cout<<"[";
     for (int i=0;i<n;i++) 
         if (i != n-1)
            cout<<tab[i]<<", ";
         else
            cout<<tab[i]<<"]"<<endl;    
}

void zad5(){
	double (*f[6])(double) = {P0, P1, P2, P3, P4, P5};
	double (*g[6])(double) = {P0, P1, P2, P3, P4, P5};
	double wynik=0;
	cout << "|   i   |   j   | wynik |\n"
		 << "=========================\n";
for ( int i = 0 ; i < 6 ; i++ ){
	for ( int j = 0 ; j < 6 ; j++){
		if(abs(calka_iloczynu(-1 , 1 , f[i], g[j] )) < 0.00001){
			wynik = 0;
			cout << "|   "<<i<<"   |   "<<j<<"   |   "<<setprecision(0)<<wynik<<"   |\n"; 
		}
		else{
			wynik = calka_iloczynu(-1 , 1 , f[i], g[j] );
			cout << fixed;
			cout << "|   "<<i<<"   |   "<<j<<"   | "<<setprecision(3)<<wynik<<" |\n"; 
		}
	}
}
cout << "=========================\n";

system("pause");
system("cls");

}

double P0 ( double x ){
	return 1;
}

double P1 ( double x ){
	return x;
}

double P2 ( double x ){
	return (3.*(x*x)-1.)/2.;
}

double P3 ( double x ){
	return (5.*(x*x*x)-3.*x)/2.;
}

double P4 ( double x ){
	return (35.*(x*x*x*x)-30.*(x*x)+3)/8.;
}

double P5 ( double x ){
	return (63.*(x*x*x*x*x)-70.*(x*x*x)+15.*x)/8.;
}

double calka_iloczynu(double a,double b, double (*f)(double), double (*g)(double)){
	double wynik = 0;
	double przedzial = (b - a) / 10000.;
	double x1,x2,c,d;
	for(int i = 0 ; i < 10000 ; i++){
		wynik+= 0.5*przedzial*(f(a+przedzial*i)*g(a+przedzial*i)+f(a+przedzial*(i+1))*g(a+przedzial*(i+1)));
	}
	return wynik;
}


