#include <string>
#include <iostream>
using namespace std;
#include <assert.h>
#include "Flight.h"
#include <vector>
Flight::Passenger::Seat::Seat(){
	row = -1;
	col = 0;
}
void Flight::Passenger::Seat::setSeatRow(int r){
	row = r;
}
void Flight::Passenger::Seat::setSeatCol(char c){
	col = c;
	
}
char Flight::Passenger::Seat::getSeatCol(){
	return col;
	
}
int Flight::Passenger::Seat::getSeatRow(){
	return row;
	
}