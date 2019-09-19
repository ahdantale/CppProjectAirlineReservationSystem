#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Passenger {
	string name;
	int age;
	string routeBooked;
	string uid;

public:
	bool ticketBooked;

	Passenger(){

	}

	Passenger(Passenger &passenger){
		name=passenger.name;
		age=passenger.age;
		routeBooked=passenger.routeBooked;
		uid=passenger.uid;
		ticketBooked=passenger.ticketBooked;
	}



	void putPassengerData() {
		cout<<"\nName of the passenger : ";
		cout<<name;
		cout<<"\nAge of the passenger : ";
		cout<<age;
		cout<<"\nPassenger travel route : "<<routeBooked;
		cout<<"\nUnique Id : "<<uid<<endl;
	}


};
int main() {
  string paxFileName = "paxfile.dat";
  Passenger passenger;
  ifstream fin;
  fin.open(paxFileName,ios::binary);

  while(fin.read((char *)&passenger,sizeof(Passenger))){

    passenger.putPassengerData();
  }

  return(0);
}
