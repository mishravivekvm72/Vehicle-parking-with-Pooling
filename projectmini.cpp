#include<iostream>
using namespace std;
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdio.h>
#include<fstream>
class car
{
	public:
	int vno;
	float count;
	char  dname[15],x,l[50];
	void input()
	{
			int d;
		cout<<"\n\n\t\tEnter the name of driver : ";
		cin>>dname;
		cout<<"\n\n\t\tEnter the car no : ";
		cin>>vno;
		cout<<"\n\n\t\tEnter the no of hours of stay : ";
		cin>>count;
		cout<<"\n\n\t\tEnter the time slot : ";
		cin>>l;
		if(d<20&&count<8)
   			{
   				cout<<"\n\n\t\tParking available you can park your car ";
   			}
   			else
   				cout<<"\n\n\t\t Parking not possible";
   			cout<<"\n\n\t\tCar got parked";
		
	}
	void cal()
	{
			
		cout<<"\n\t\n\tAre you a V.I.P: y/n ";
		cin>>x;
		if(x=='y')
	{
		cout<<"\n\t\n\tThe total expense during parking  ";
		cout<<count*20<<" rupees";
	}
	else 
	{
		cout<<"\n\t\n\tThe total expenses during parking  ";
		cout<<count*25<<" rupees";
		
	}
}	
	void output()
	{
		cout<<"\n\n\t\tThe Driver Name : "<<dname<<endl;
		cout<<"\n\n\t\tThe Car No : "<<vno<<endl;
		cout<<"\n\n\t\tThe Hours Of Stay : " <<count;
		cout<<"\n\n\t\tThe Time Slot Of Parking : " <<l;
	
	}
	

		
}a,a1;
void delete_record()
{
	int n;
	cout<<"\n\n\t\tEnter the car no you want to get depart : ";
	cin>>n;
	ifstream inFile;
    inFile.open("parking3.dat", ios::binary);
	ofstream outFile;
    outFile.open("temp.dat", ios::out | ios::binary);
    while(inFile.read((char*)&a, sizeof(a)))
    {
        if(a.vno!= n)
        {	
        	
            outFile.write((char*)&a, sizeof(a));
        }
         
    }
    cout<<"\n\n\t\t Parking Record Deleted";

    inFile.close();
    outFile.close();
    
    remove("parking3.dat");
    rename("temp.dat", "parking3.dat");
}

int main()
{

	int choice,vno1,d;
	while(1) {
		

     cout << "\n\n\t\t ====== CAR PARKING RESERVATION SYSTEM ======";
     cout <<"\n\n                                          ";
     cout << "\n\n";
     cout<<" \n\t\t\t======================";
     cout << "\n\n\t\t\t  1. Arrival of a Car";
     cout << "\n\n\t\t\t  2. Total no of cars Arrived";
     cout << "\n\n\t\t\t  3. Total parking charges of all cars with details";
     cout << "\n\n\t\t\t  4. Departure of the car";
     cout << "\n\n\t\t\t  5. Exit   Program";
     cout<<" \n\t\t\t======================";
     cout << "\n\n";
     cout << "\t\t\t Select Your Choice ::";
     cin>>choice;
     switch(choice)
     {
      case 1 :
        {		
        		char f;
        		cout<<"\n\n\t\t==Do You Want to continue==y/n ";
        		cin>>f;
        		if(f=='y')
        		{
        		
				ofstream f1("parking3.dat",ios::binary|ios::out|ios::app);
                a.input();
                f1.write((char*)&a,sizeof(a));
        }
            	break;
        }
       case 2 :
           {
  		   cout << "\n\n\t\t=== View the Records in the Parking Database ===";
           cout << "\n";
           ifstream infile("parking3.dat",ios::binary|ios::in);
           int d=1;
           while (infile.read((char *)&a,sizeof (a)))
		   {
		
           cout << "\n";
           cout<<"\n\n\tThe Car position in parking lot : "<<d;
           d++;
           a.output();
           cout<<"\n";
           cout<<endl;
       	   }
       
           break;
       	   }
       	case 4:	
		   {
		   
		   delete_record();
		   break;
	}
    	case 3:
		{
				ifstream infile("parking3.dat",ios::binary|ios::in);
           while (infile.read((char *)&a,sizeof (a)))
		   {
             cout << "\n";
			 a.cal();
			 a.output();
			 cout<<"\n";
			 cout<<endl;
			 
       		}
       		break;
   }
   		
   		case 5: 
		   {
		   exit(0);
   			break;
   		}
   		default : 
		   {
		   cout<<"\n\n\t\t Invalid input";
			cout<<"\n\n\t\tPress Enter to continue";
			 
   	
   	}
   }
getch();
}}
