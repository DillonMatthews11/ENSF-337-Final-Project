#include <iostream>
using namespace std;
#include <assert.h>
#include "Flight.h"
#include <string>
int menu();
//PROMISES: Will print out a menu of program options.
//Takes in user input for the users choice and returns it.
void displayHeader();
//PROMISES: Will print the project name, version,
//and student name to the console.

void cleanStandardInputSteam();
//PROMISES: will clear the console input stream 
//of any characters that remain.
void addPassenger(Flight &flight);
//REQUIRES: Reference to a Flight object with
//a non zero size vector of vectors with passenger 
//type.
//PROMISES: Will take user input, determine whether 
//input is valid and create a new passenger, placed
//and initialized based off the read in user input

void delPassenger(Flight &flight);
//REQUIRES: Reference to a Flight object with
//a non zero size vector of vectors with passenger 
//type.
//PROMISES: uses user input to take in the ID number
//of the passenger they wish to delete. Then passes that
//ID to the delete passenger flight member function.
int main()
{
	string file = "flight_info.txt";
	int choice = 0;
	Flight flight;
	flight.readIn(file);
	displayHeader();
	while(1){
		choice = menu();
		switch(choice){
			case 1:
				flight.printMap();
				break;
			case 2:
				flight.printInfo();
				break;
			case 3:
				addPassenger(flight);
				break;
			case 4:
				delPassenger(flight);
				break;
			case 5: 
				flight.saveData(file);
				break;
			
			case 6:
				exit(1);
				break;
			
		}
	}

	return 0;
}
void displayHeader(){
	cout<<"Version 1.0"<<endl<<"Term Project - Flight Management System in C++"<<endl<<"Created by Dillon Matthews."<<endl;
	
}
void delPassenger(Flight &flight){
	int delID;
	cout<<"please type the id number of the passenger you wish to delete"<<endl;
	cin>>delID;
	while(cin.fail()||delID<0){
		
		if(cin.fail()){
			
			cin.clear();
			cin.ignore();
			cleanStandardInputSteam();
		}
		else{
			cin.clear();
			cin.ignore();
		}
		cout<<"invalid Input please try again"<<endl;
		cin>>delID;
	}
	cleanStandardInputSteam();
	flight.deletePassenger(delID);
}
void addPassenger(Flight &flight){
	string fName;
	string lName;
	string pNum;
	bool validPhone = false;
	int row;
	char col;
	cout<<"Please enter first name"<<endl;
	getline(cin,fName);
	while(fName.length()>20){
		cout<<"input is too long please re enter" <<endl;
		getline(cin,fName);
	}
	cout<<"please enter last name"<<endl;
	getline(cin,lName);
	while(lName.length()>20){
		cout<<"input is too long please re enter" <<endl;
		getline(cin,lName);
		
	}
	
	cout<<"please enter phone number "<<endl;
	getline(cin,pNum);
	for(int i = 0;i<(int)pNum.length();i++){
		if(pNum[i] == ' '||pNum[i] == '-'||(pNum[i]<'9'&&pNum[i]>'0'))
			validPhone = true;
		else{
			validPhone=false;
			break;
		}
		
	}
	while(pNum.length()>20||!validPhone){
		
		cout<<"input is either too long or invalid. Only numbers, spaces, and hyphens allowed" <<endl;
		getline(cin,pNum);
		for(int i = 0;i<(int)pNum.length();i++){
			if(pNum[i] == ' '||pNum[i] == '-'||(pNum[i]<'9'&&pNum[i]>'0'))
				validPhone = true;
			else{
				validPhone=false;
				break;
			}
			
			
		
		}
	}
	do{
		cout<<"please enter desired row from 1-"<<flight.getFlightRows()<<endl;
		cin>>row;
		while(cin.fail()||row<1||row>flight.getFlightRows()){
			if(cin.fail()){
				
				cin.clear();
				cin.ignore();
				cleanStandardInputSteam();
			}
			else{
				cin.clear();
				cin.ignore();
			}
			cout<<"invalid Input please try again"<<endl;
			cin>>row;
		}
		cleanStandardInputSteam();
		cout<<"please enter desired col from A-"<<(char)((flight.getFlightCols()-1)+65)<<endl;
		cin>>col;
		while(cin.fail()||col<'A'||col>(char)((flight.getFlightCols()-1)+65)){
			
				
				cin.clear();
				cin.ignore();
				
			
			cout<<"invalid Input please try again"<<endl;
			cin>>col;
		}
		cleanStandardInputSteam();
	}while(!flight.checkSeat(row,col));
	flight.addPassenger(fName,lName,pNum,row,col);
	
}
int menu(){
	int choice;
	cout<<"<<Press return to continue>>\n";
	
	cleanStandardInputSteam();
	cout<<"Please select one of the following options to continue\n";
	cout<<"1. Display Flight Seat Map"<<endl;
	cout<<"2. Display Passenger Information"<<endl;
	cout<<"3. Add a New Passenger"<<endl;
	cout<<"4. Remove an Existing Passenger"<<endl;
	cout<<"5. Save Data"<<endl;
	cout<<"6. Quit"<<endl;
	cout<<"Please enter your choice (1, 2, 3, 4, 5, or 6)"<<endl;
	cin>>choice;
	while(cin.fail()||choice<1||choice>6){
		if(cin.fail()){
			
			cin.clear();
			cin.ignore();
			cleanStandardInputSteam();
		}
		else{
			cin.clear();
			cin.ignore();
		}
		cout<<"invalid Input please try again"<<endl;
		cin>>choice;
	}
	cleanStandardInputSteam();
	return choice;
}
void cleanStandardInputSteam(){
	int leftOver;
	do{
		leftOver = cin.get();
	}while(leftOver != '\n'&&leftOver != EOF);
}