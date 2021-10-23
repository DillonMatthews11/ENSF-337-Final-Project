#include <string>
#include <iostream>
#include <fstream>
using namespace std;
#include <assert.h>
#include "Flight.h"
#include <vector>


Flight::Flight(){
	flightNum = "";
	numOfRows = 0;
	numOfCols = 0;
	lastID = 10000;
}
int Flight::getFlightRows(){
	return numOfRows;
}
int Flight::getFlightCols(){
	return numOfCols;
}

void Flight::deletePassenger(int deletingID){
	bool found = false;
	for(int i = 0; i<numOfRows;i++){
		for(int j = 0; j<numOfCols;j++){
			if(pMatrix[i][j].getID() == deletingID){
				found = true;
				pMatrix[i][j].setFName("");
				pMatrix[i][j].setLName("");
				pMatrix[i][j].setPhoneNum("");
				pMatrix[i][j].setID(-1);
				pMatrix[i][j].seat.setSeatRow(-1);
				pMatrix[i][j].seat.setSeatCol(0);
				cout<<"passenger successfully deleted"<<endl;	
			}
			
		}
	}
	if(found == false)
		cout<<"id Number not found"<<endl;
}

void Flight::printMap(){
	cout<<"Flight Number: "<<flightNum<<" rows: "<<numOfRows<<" columns: "<<numOfCols<<endl<<" ";
	for(int i = 0;i<numOfCols;i++){
		char ch = i+65;
		cout<<"   "<<ch; 		
	}	
	cout<<endl<<"  ";
	for(int j =0;j<numOfCols;j++){
			cout<<"+---";
	}
	cout<<endl;
	
	for(int i = 0;i<numOfRows;i++){
		
		cout<<i+1;
		if((i+1)<10)
			cout<<" ";
		cout<<"|";
		for(int j = 0;j<numOfCols;j++){
			cout<<" ";
			if(pMatrix[i][j].getID() == -1)
				cout<<"  ";
			
			else
				cout<<"X ";
			cout<<"|";
			
			
		}	
		cout<<endl<<"  ";
		for(int j =0;j<numOfCols;j++){
			cout<<"+---";
		}

		cout<<"+"<<endl;
	}
}
void Flight::printInfo(){
	cout<<"First Name          Last Name           Phone Number       Row  Seat    ID"<<endl;
	cout<<"+-----------------------------------------------------------------------------+"<<endl;
	for(int i =0;i<numOfRows;i++){
		for(int j = 0;j<numOfCols;j++){
			if(pMatrix[i][j].getID()!= -1){
				cout<<pMatrix[i][j].getFName()<<spaceFiller(20-pMatrix[i][j].getFName().length());
				cout<<pMatrix[i][j].getLName()<<spaceFiller(20-pMatrix[i][j].getLName().length());
				cout<<pMatrix[i][j].getPhoneNum()<<spaceFiller(20-pMatrix[i][j].getPhoneNum().length());
				cout<<pMatrix[i][j].seat.getSeatRow();
				if(pMatrix[i][j].seat.getSeatRow()<10)
					cout<<spaceFiller(4);
				else
					cout<<spaceFiller(3);
				cout<<pMatrix[i][j].seat.getSeatCol()<<spaceFiller(5);
				cout<<pMatrix[i][j].getID()<<endl;
				cout<<"+-----------------------------------------------------------------------------+"<<endl;
			}
		}
		
	}
}

int Flight::checkSeat(int r,char c){
	
	if(pMatrix[r-1][c-65].getID() != -1){
		cout<<"seat is taken please try again "<<endl;
		return 0;
	}
	return 1;
}
void Flight::addPassenger(string fName,string lName,string pNum,int r,char c){
	pMatrix[r-1][c-65].setFName(fName);
	pMatrix[r-1][c-65].setLName(lName);
	pMatrix[r-1][c-65].setPhoneNum(pNum);
	pMatrix[r-1][c-65].setID(++lastID);
	pMatrix[r-1][c-65].seat.setSeatRow(r);
	pMatrix[r-1][c-65].seat.setSeatCol(c);
}
void Flight::readIn(string file){
	
	ifstream inStream;
	inStream.open(file);
	if(inStream.fail()){
		cout<<"File not found";
		exit(1);
	}
	
	char ch[70];
	string fName;
	string lName;
	string pNum;
	
	string s = "";
	char col;
	
	string sRow;
	string sID;
	inStream.getline(ch ,20,'\n');
	int i = 0;
	while(ch[i] != ' '){
		flightNum+=ch[i];
		i++;
	}
	while(ch[i] == ' ')
		i++;
	while(ch[i] != ' '){
		s+=ch[i];
		i++;
	}
	numOfRows = stoi(s);
	while(ch[i] == ' ')
		i++;
	s = "";
	while(ch[i] != ' '){
		s+=ch[i];
		i++;
	}
	
	numOfCols = stoi(s);	
	
		pMatrix.resize(numOfRows);
	for(int i = 0; i<numOfRows;i++)
		pMatrix.at(i).resize(numOfCols);
	
	while(!inStream.eof()){
		
		inStream.getline(ch,70,'\n');
		
		fName = "";
		for(i=0;i<20;i++)
			fName+=ch[i];
		
		
		lName = "";
		for(i=i;i<40;i++)
			lName+=ch[i];
		
		
		
		pNum = "";
		for(i=i;i<60;i++)
			pNum += ch[i];
		sRow = "";
		sRow+= ch[i++];
		if(ch[i]>='0'&&ch[i]<='9')
			sRow+=ch[i++];
		col = ch[i++];
		while(ch[i]==' ')
			i++;
		sID = "";
		
		while(ch[i]>='0'&&ch[i]<='9'){
			sID += ch[i];
			i++;
		}
		
		int row = stoi(sRow);
		int pID = stoi(sID);
		pMatrix[row-1][col-65].setFName(fName);
		pMatrix[row-1][col-65].setLName(lName);
		pMatrix[row-1][col-65].setPhoneNum(pNum);
		pMatrix[row-1][col-65].seat.setSeatRow(row);
		pMatrix[row-1][col-65].seat.setSeatCol(col);
		pMatrix[row-1][col-65].setID(pID);
		if(lastID<pID)
			lastID = pID;
		
	}
	
	
	
	inStream.close();		
}
void::Flight::saveData(string file){
	ofstream outStream;
	outStream.open(file);
	
	if(outStream.fail()){
		cout<<"File not found";
		exit(1);
	}
	string s;
	s = flightNum+"   "+to_string(numOfRows)+"   "+to_string(numOfCols);
	outStream<<s<<"\n";
	
	for(int i = 0;i<numOfRows;i++){
		
		for(int j = 0;j<numOfCols;j++){
			s = "";
			if(pMatrix[i][j].getID() != -1){
				s+= pMatrix[i][j].getFName();
				s+= spaceFiller(20-pMatrix[i][j].getFName().length());
				s+= pMatrix[i][j].getLName();
				s+= spaceFiller(20-pMatrix[i][j].getLName().length());
				s+= pMatrix[i][j].getPhoneNum();
				s+= spaceFiller(20-pMatrix[i][j].getPhoneNum().length());
				s+= (to_string(pMatrix[i][j].seat.getSeatRow())+pMatrix[i][j].seat.getSeatCol());
				s+= spaceFiller(4-(to_string(pMatrix[i][j].seat.getSeatRow())+pMatrix[i][j].seat.getSeatCol()).length());
				s+= (to_string(pMatrix[i][j].getID()));
				outStream<<s<<"\n";
				
			}
		}
	}
	outStream.close();
	cout<<"Data has been saved."<<endl;
	
	
}
string Flight::spaceFiller(int i){
	string s = "";
	for(int j = 0;j<i;j++)
		s+=" ";
	return s;
}
 

