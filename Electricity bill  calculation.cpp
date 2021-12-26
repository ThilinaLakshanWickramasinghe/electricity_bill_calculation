#include <iostream.h>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

int main()
	{
		HANDLE a = GetStdHandle (STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(a, 5 | FOREGROUND_INTENSITY);
    
    	cout<<"                 ***************************************************************************"<<endl;
    	cout<<"                 ***************************************************************************"<<endl;
    	cout<<"                 **                                                                       **"<<endl;
    	cout<<"                 **                           ELECTRICITY BILL                            **"<<endl;
    	cout<<"                 **                             CALCULATION                               **"<<endl;
    	cout<<"                 **                                                                       **"<<endl;
    	cout<<"                 ***************************************************************************"<<endl;
    	cout<<"                 ***************************************************************************"<<endl;
    	cout<<endl;
    	  
    	SetConsoleTextAttribute(a, 15 | FOREGROUND_INTENSITY);	
		
    	float total,balance,gtotal,vat;	// total- this month bill
										//balance-last month balance ammount 
										// gtotal- Grand total for this month bill
										//vat- vat value
	
		int cunit,lunit,helper,billn; 	//cunit-current month reading 
										//lunit-last month reading
										//helper- excess units
 		string name,month,add;
 	
		cout<<"  Enter your bill number : ";
		cin>>billn;
	
		cout<<"  Enter your name : ";
		cin>>name;
	
		cout<<"  Enter your address : ";
		cin>>add;
		
		cout<<"  Enter month : ";
		cin>>month;
		cout<<endl;
	
		SetConsoleTextAttribute(a, 3 | FOREGROUND_INTENSITY);
		
		cout<<"  Enter your current month Reading(units) : ";
		cin>>cunit;
		
		cout<<"  Enter your last month Reading(units) : ";
		cin>>lunit;
	
		cout<<"  Enter Your last month balance ammount : ";
		cin>>balance;
	
		int unit= cunit-lunit; 		// number of consumed units for this month
	
		cout<<"  Current month Usage(Units) : "<<unit<<endl;
	
		int fixed=90; 				// monthly fixed cost
		float vp=0.15;				// vat percentage
						
		if(60>=unit)
			{
				total = (unit*7.85) +fixed;
				cout<<"  This month your bill ammount(without vat 15%) : "<<total<<endl;
				vat=total*vp;
				cout<<"  VAT ammount : "<<vat<<endl;
			
				SetConsoleTextAttribute(a, 4 | FOREGROUND_INTENSITY);
				gtotal=total+vat+ balance;
				cout<<"  Grand total of Your bill(with vat 15%) : "<<gtotal;
				cout<<endl;
			}
		
		else if(90>=unit)
			{
				helper = unit-60 ;
				total = (60*7.85) +fixed+ (helper*10);
				cout<<"  This month your bill ammount(without vat 15%) : "<<total<<endl;
				vat=total*vp;
				cout<<"  VAT ammount : "<<vat<<endl;
			
				SetConsoleTextAttribute(a, 4 | FOREGROUND_INTENSITY);
		
				gtotal=total+vat+ balance;
				cout<<"  Grand total of Your bill(with vat 15%) : "<<gtotal;
				cout<<endl;
			}
		
		else
			{
				helper = unit-90 ;
				total = (60*7.85) + (30*10)  + fixed + (helper*27.75);
				cout<<"  This month your bill ammount(without vat 15%) : "<<total<<endl;
				vat=total*vp;
				cout<<"  VAT ammount : "<<vat<<endl;
		
				SetConsoleTextAttribute(a, 4 | FOREGROUND_INTENSITY);
		
				gtotal=total+vat+ balance;
				cout<<"  Grand total of Your bill(with vat 15%) : "<<gtotal;
				cout<<endl;
			}
	
		char text[500];
  		fstream file;
  		file.open ("bill.txt", ios::out | ios::in );
		cin.getline(text, sizeof(text)); 
		 
		file <<"****************************************"<< endl;
		file <<"*- - - - - - - -ELECTRICITY BILL- - - - - - - - *"<< endl;
		file <<"****************************************"<< endl;
	 	file <<"* Bill number = "<<billn<< endl;
		file <<"* Name = "<<name<<endl;
		file <<"* Address = "<<add<<endl;
		file <<"* Month = "<<month<<endl;
		file <<"* Current month Reading (Units) = "<<cunit<< endl;
		file <<"* Last month Reading(Units) = "    <<lunit<< endl;
		file <<"* Current month Usage(Units) = "   <<unit<< endl;
		file <<"* Last month balance ammount = "   <<balance<< endl;
		file <<"* This month bill Value(without vat 15%) = "<<total<< endl;
		file <<"* VAT ammount = "<<vat<< endl;
		file <<"* Grand total of your bill(With VAT 15%) = "<<gtotal<< endl;
		file <<"* - - - - - - - - - - - - -END - - - - - - - - - - - *"<< endl;
	
 		file.close();
  	return 0;
	}
