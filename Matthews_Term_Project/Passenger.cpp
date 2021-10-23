#include <string>
#include <iostream>
using namespace std;
#include <assert.h>
#include "Flight.h"
#include <vector>

Flight::Passenger::Passenger(){
	firstName = "";
	lastName = "";
	phoneNumber = "";
	id = -1;
}
Flight::Passenger::~Passenger(){
	firstName = "";
	lastName = "";
	phoneNumber = "";
	id = -1;
}
#if 1
void Flight::Passenger::setFName(string fName){
	firstName = fName;
}
void Flight::Passenger::setLName(string lName){
	lastName = lName;
}
void Flight::Passenger::setPhoneNum(string pNum){
	phoneNumber = pNum;
}
void Flight::Passenger::setID(int iD){
	id = iD;
}
#endif
int Flight::Passenger::getID(){
	return id;
}
string Flight::Passenger::getFName(){
	return firstName;
}
string Flight::Passenger::getLName(){
	return lastName;
}
string Flight::Passenger::getPhoneNum(){
	return phoneNumber;
}