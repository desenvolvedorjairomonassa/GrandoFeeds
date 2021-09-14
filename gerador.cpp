//============================================================================
// Name        : gerador.cpp
// Author      : jairo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <cmath>
#include <dos.h>   //for delay()
#include <windows.h>


using namespace std;
string aggressorSeed()  {
	string agressor[2] = {"COMPRADOR","VENDEDOR"};
	int j =  (rand() % (2)) ;
	return agressor[j];
}

string playerSeed()  {
	string buyer[6] = {"BTG","ITAU", "CLEAR","BRADESCO","XP","BTG"};
	int j =  (rand() % (6)) ;
	return buyer[j];
}

string tickerSeed(){
	string tickerOptions[5] = {"PETR4","VALE3", "ALL2","DOLFUT","WDOFUT"};
	int j =  (rand() % (4)) ;
	return tickerOptions[j];
}
double priceSeed(int min, int max){
	double decimalnu = (double)(rand() % 100)/100;
	int j = min + (rand() % (max-min)) ;
    return (double)j+decimalnu;

}
int volumeSeed(int min, int max){
    return  min + (rand() % (max-min));

}
int main() {
	 srand((unsigned)time(NULL)); //inicializar o rand para mudar conforme o tempo


	   time_t now = time(0);

	   tm *ltm = localtime(&now);
	   int mon = 1 + ltm->tm_mon;
	   int year = 1900 + ltm->tm_year;
	   int day = ltm->tm_mday;
	   string datestr = to_string(day)+'/'+to_string(mon)+'/'+to_string(year);


	int i=1;
//	while (i<300) {


	 //  tm *ltm = localtime(&now);
	   int hour =ltm->tm_hour;
	   string hourstr = to_string(hour);
	   hourstr.insert(hourstr.begin(), 2 - hourstr.length(), '0');
	   int min = ltm->tm_min;
	   string minstr = to_string(min);
	   minstr.insert(minstr.begin(),2 -minstr.length(),'0');
	   int seg = ltm->tm_sec;
	   string segstr = to_string(seg);
	   segstr.insert(segstr.begin(),2 -segstr.length(),'0');
	   string timestr  = hourstr+':'+minstr+':'+segstr;
	   double price = priceSeed(1,3000);
	   double volume = volumeSeed(10,4000);

	   string linha =  to_string(i) +','+datestr+' '+timestr+','+to_string((int)volume)+','+to_string(price)+','+tickerSeed()
			   +','+playerSeed()+','+playerSeed()+','+aggressorSeed();

	   cout << linha << endl; // prints gerar dados
	 //  delay(1000);
	   Sleep(2000);
	i++;
//	}
	return 0;
}
