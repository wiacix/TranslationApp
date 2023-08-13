#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <ctime>
using namespace std;

bool czyBylaWylosowana( int iLiczba, int tab[], int ile )
{
    if( ile <= 0 )
         return false;
   
    int i = 0;
    do
    {
        if( tab[ i ] == iLiczba )
             return true;
       
        i++;
    } while( i < ile );
   
    return false;
}

int main(){
	
	ifstream wej("test.txt");
	ofstream wyj("result.txt", ios::out | ios::app);
    time_t czas;
    time(&czas);
    srand(time(NULL));
    
	string a;
	int ile=10;
	string * tab_pol = new string[ile];
	string * tab_ang = new string[ile];
	int i=0;
	
	while(!wej.eof() and i<ile){
		wej >> tab_pol[i];
		wej >> a;
		wej >> tab_ang[i];
		i++;
	}
	
	wyj << "************************************\n" << ctime(&czas) << endl << "Dzisiejsze zdania: " << endl << endl;
	
	string wyraz;
	int wynik=0;
	int x;
	int wylosowane[ile];
	int kontrol=0;
	int wylosowanych=0;
	do{
        int liczba = rand()%(ile+1);
       	if( czyBylaWylosowana( liczba, wylosowane, wylosowanych ) == false ){
       	wylosowane[ wylosowanych ] = liczba;
       	wylosowanych++;
    	}
    }while( wylosowanych < 5 );
	do{
    	x = wylosowane[kontrol];
    	cout << "\nPrzetlumacz: " << tab_pol[x] << " - ";
		cin >> wyraz;
		if(wyraz==tab_ang[x]){
			cout << "\nDobrze !!!";
			wyj << tab_pol[x] << " - " << tab_ang[x] << endl;
			kontrol++;
		} 
		else{
		 cout << "\nZle !!!\nPrawidlowo: " << tab_ang[x];
		}
	}while(kontrol<ile);
	
	wyj << endl << "Wynik: " << wynik << "/" << i << "\n************************************\n";
	
	wej.close();
	wyj.close();
	delete [] tab_pol;
	delete [] tab_ang;
	return 0;
}
