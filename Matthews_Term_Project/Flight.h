#include <string>
#include <vector>

class Flight{
	public:
	class Passenger{
		public:
			class Seat{
				public:
					Seat();
					//default seat constructor/
					void setSeatRow(int r);
					//REQUIRES: r-1 is the same as number as the 
					//row index of of the passenger vector of vectors
					//PROMISES: will set the row member variable
					//of that seat object to r;
					
					void setSeatCol(char c);
					//REQUIRES: c-65 is the same as number as the 
					//column index of of the passenger vector of vectors
					//PROMISES: will set the col member variable
					//of that seat object to c.
					char getSeatCol();
					//PROMISES: will return col member variable of the
					//object that the this pointer points to
					int getSeatRow();
					//PROMISES: will return row member variable of the
					//object that the this pointer points to
				private:
					int row;
					char col;
			};
			Passenger();
			~Passenger();
			void setFName(string fName);
			//REQUIRES: fName is not NULL.
			//PROMISES: will set the firstName member variable
			//of that passenger object to fName.
			void setLName(string lName);
			//REQUIRES: lName is not NULL.
			//PROMISES: will set the lastName member variable
			//of that passenger object to lName.
			void setPhoneNum(string pNum);
			//REQUIRES: pNum is not NULL.
			//PROMISES: will set the phoneNumber member variable
			//of that passenger object to pNum.
			void setID(int iD);
			//REQUIRES:iD>0
			//PROMISES: will set the id member variable
			//of that passenger object to iD.
			int getID();
			//Promises: returns the value of the id passenger member
			//variable of the passenger object that the this pointer
			//points to.
			string getFName();
			//Promises: returns the firstName member
			//variable of the passenger object that the this pointer
			//points to.
			string getLName();
			//Promises: returns the lastName member
			//variable of the passenger object that the this pointer
			//points to.
			string getPhoneNum();
			//Promises: returns the phoneNumber member
			//variable of the passenger object that the this pointer
			//points to.
			Seat seat;
			
			
			
		private:
			string firstName;
			string lastName;
			string phoneNumber;
			int id;
				
			
		};
		typedef vector< vector<Passenger> > matrix;
		Flight();
		//default flight constructor
		void printMap();
		//PROMISES:prints out seating map of the plane including
		//already existing passengers;
		void readIn(string file);
		//REQUIRES: file is the name of an available text file
		//file passengers have rows and seats that are in the boundary
		//of the number of rows and columns
		//PROMISES:reads the passengers and data into the corresponding
		//index in the passenger vector of vectors from file.
		void printInfo();
		//PROMISES: prints each passengers information line by line
		void addPassenger(string fName,string lName,string pNum,int r,char c);
		//REQUIRES: fName,lName and pNum are less than 20 characters.
		//r-1 is in the boundary of the row index of the passenger vector of vectors.
		//(int)c-65 is in the boundary of the column index of the passenger vector of vectors.
		//PROMISES:sets passenger member variables to corresponding variables passed to the function.
		//sets id to 1+lastID
		void deletePassenger(int deletingID);
		//REQUIRES: deletingID<0
		//PROMISES: goes through matrix comparing the IDs of each
		//object to the deletingID. If a match is found the data
		//of that object is set to default absent passenger data
		int getFlightRows();
		//PROMISES: returns the value of the numOfRows Flight member
		//variable of the passenger object that the  this pointer
		//points to.
		int getFlightCols();
		//PROMISES: returns the value of the numOfCols Flight member
		//variable of the passenger object that the  this pointer
		//points to.
		int checkSeat(int r,char c);
		//REQUIRES: 
		//r-1 is in the boundary of the row index of the passenger vector of vectors.
		//(int)c-65 is in the boundary of the column index of the passenger vector of vectors.
		//PROMISES: returns 1 if the seat object in pMatrix[r-1][c-65] has 
		//the same 
		void saveData(string file);
		//REQUIRES: file is the name of an available text file
		//PROMISES: saves the data of each passenger object to file that's id is not -1 to the file in following
		//format: prints firstName, last name, and phoneNumber, each with spaces after until 20 characters is reached.
		//Then prints the row and column together followed by spaces until 4 characters are reached then prints the id.
		//does this for all objects each on a new line.
	private:
		string spaceFiller(int i);
		//REQUIRES i>0
		//PROMISES: will return a string with i amount of spaces.
		string flightNum;
		int numOfRows;
		int numOfCols;
		matrix pMatrix;
		int lastID;
	
	
};
