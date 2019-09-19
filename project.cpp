#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

//Forward Class declarations
class Passenger;
class Airline;
class Route1;
class Route2;
class Route3;
class Planes;

//Function prototypes
void menu();
void writeToPaxFile(Passenger);
void readFromPaxFile();
void writeToAdminFiles();
void showRoutes();

//Global filenames
string paxFileName = "paxfile.dat";
string adminFileName1 = "adminfile1.dat";
string adminFileName2 = "adminfile2.dat";
string adminFileName3 = "adminfile3.dat";

//Enumeration to show the route type
enum RouteType {
	longRoute,shortRoute
};

//Airline Abstract Class
class Airline {
	public:

	virtual void getBasicData() = 0;
	virtual void putBasicData() = 0;
};

//Planes Abstract Class
class Planes {
	public:

	virtual void getBasicData() = 0;
};

//AirIndia Class
class AirIndia : public Airline {
 protected:
	string name;
	int noOfRoutesServed;

	public:

	void getBasicData() {
		cout<<"\nEnter the name of the airline : ";
		getline(cin,name);
		cout<<"\nEnter the no. of routes served by the airline : ";
		cin>>noOfRoutesServed;
	}

	void putBasicData() {
		cout<<"\nThe name of the airline is : "<<name
			<<"\nThe no. of routes served by the airline are : "<<noOfRoutesServed<<endl;
	}
};

//Indigo Class
class Indigo : public Airline {
	protected:
	string name;
	int noOfRoutesServed;

	public:

	void getBasicData() {
		cout<<"\nEnter the name of the airline : ";
		getline(cin,name);
		cout<<"\nEnter the no. of routes served by the airline : ";
		cin>>noOfRoutesServed;
	}

	void putBasicData() {
		cout<<"\nThe name of the airline is : "<<name
			<<"\nThe no. of routes served by the airline are : "<<noOfRoutesServed<<endl;
	}
};

//Vistara Class
class Vistara : public Airline {
	protected:
	string name;
	int noOfRoutesServed;

	public:

	void getBasicData() {
		cout<<"\nEnter the name of the airline : ";
		getline(cin,name);
		cout<<"\nEnter the no. of routes served by the airline : ";
		cin>>noOfRoutesServed;

	}

	void putBasicData() {
		cout<<"\nThe name of the airline is : "<<name
			<<"\nThe no. of routes served by the airline are : "<<noOfRoutesServed
			<<endl;
	}
};

//A320 Class
class A320 : public Planes {

 protected:
	int noOfSeats;
	RouteType routeType;

	public:

	void getBasicData() {
		cout<<"\nEnter the no. of seats availbale on the A320 : ";
		cin>>noOfSeats;
		cout<<"\nEnter the type of route : ";
		int rtType;
		cin>>rtType;
		if(rtType == 0) {
			routeType = longRoute;
		} else {
			routeType = shortRoute;
		}

	}

	void putBasicData() {
		cout<<"\nThe seats available on the A320 are : ";
		cout<<noOfSeats;
		cout<<"\nThe type of route of the A320 is : ";
		if (routeType == longRoute) {
			cout<<routeType;
		} else {
			cout<<"Short Route";
		}
	}

};

//B737 Class
class B737 : public Planes {
	protected:

	int noOfSeats;
	RouteType routeType;

	public:

	void getBasicData() {
		cout<<"\nEnter the no. of seats availbale on the B737 : ";
		cin>>noOfSeats;
		cout<<"\nEnter the type of route : ";
		int rtType;
		cin>>rtType;
		if(rtType == 0) {
			routeType = longRoute;
		} else {
			routeType = shortRoute;
		}

	}

	void putBasicData() {
		cout<<"\nThe seats available on the B737 are :  ";
		cout<<noOfSeats;
		cout<<"\nThe type of route of the B737 is : ";
		if (routeType == longRoute) {
			cout<<"Long Route";
		} else {
			cout<<"Short Route";
		}

	}
};

//Route 1 Class for AirIndia Airline
class Route1:B737,A320,AirIndia {
	vector<string> routeNos;
	vector<string> routeToFrom;
	vector<int> ticketsAvailable;
	vector<int> ticketsBooked;

	public:

		Route1() {
			cout<<"\nAirline ::::: AirIndia"
			B737::getBasicData();

			A320::getBasicData();
			char ch;
			while((ch=getchar())!='\n');
			AirIndia::getBasicData();
			while((ch=getchar())!='\n');
			routeNos.resize(noOfRoutesServed);
			routeToFrom.resize(noOfRoutesServed);
			ticketsAvailable.resize(noOfRoutesServed);
			ticketsBooked.assign(noOfRoutesServed,0);

			for(int i=0;i<noOfRoutesServed;i++) {
				cout<<"\nEnter the route Number : ";getline(cin,routeNos[i]);
				cout<<"\nEnter the route path : ";getline(cin,routeToFrom[i]);
				cout<<"\nEnter the total number of tickets available for this route : ";cin>>ticketsAvailable[i];
				char ch;
				while((ch=getchar())!='\n');
			}
		}

		void putData(){
			cout<<"\nThe type of aircraft and its details are : ";
			B737::putBasicData(),A320::putBasicData();
			cout<<"\nThe Airline data is : ";
			AirIndia::putBasicData();
			cout<<"\nThe data of the routes is : ";
			cout<<"\nRoute Number\tRoutle Name\tTickets Available :: ";
			for(int i=0;i<noOfRoutesServed;i++){
				cout<<"\n"<<routeNos[i]<<"\t"<<routeToFrom[i]<<"\t"<<ticketsAvailable[i];
			}
		}

		bool findBooking(string route){
			int loc;

			for(int i=0;i<noOfRoutesServed;i++) {
				if(route == routeToFrom[i]){
					loc = i;
					break;
				}
			}

			if(ticketsAvailable[loc]>ticketsBooked[loc]){
				ticketsBooked[loc]++;
				cout<<"\nTicket booked successfully";
				return(true);
			} else {
				cout<<"\nTicket could not be booked : ";
				return(false);
			}

		}
};

//Route Class for indigo airline
class Route2:B737,A320,Indigo {
	vector<string> routeNos;
	vector<string> routeToFrom;
	vector<int> ticketsAvailable;
	vector<int> ticketsBooked;

public:

	Route2() {
		cout<<"\nAirline :::::::: Indigo";
		B737::getBasicData();

		A320::getBasicData();
		char ch;
		while((ch=getchar())!='\n');
		Indigo::getBasicData();
		while((ch=getchar())!='\n');
		routeNos.resize(noOfRoutesServed);
		routeToFrom.resize(noOfRoutesServed);
		ticketsAvailable.resize(noOfRoutesServed);
		ticketsBooked.assign(noOfRoutesServed,0);

		for(int i=0;i<noOfRoutesServed;i++) {
			cout<<"\nEnter the route Number : ";getline(cin,routeNos[i]);
			cout<<"\nEnter the route path : ";getline(cin,routeToFrom[i]);
			cout<<"\nEnter the total number of tickets available for this route : ";cin>>ticketsAvailable[i];
			char ch;
			while((ch=getchar())!='\n');
		}
	}

	void putData(){
		cout<<"\nThe type of aircraft and its details are : ";
		B737::putBasicData(),A320::putBasicData();
		cout<<"\nThe Airline data is : ";
		Indigo::putBasicData();
		cout<<"\nThe data of the routes is : ";
		cout<<"\nRoute Number\tRoutle Name\tTickets Available :: ";
		for(int i=0;i<noOfRoutesServed;i++){
			cout<<"\n"<<routeNos[i]<<"\t"<<routeToFrom[i]<<"\t"<<ticketsAvailable[i];
		}
	}

	bool findBooking(string route){
		int loc;

		for(int i=0;i<noOfRoutesServed;i++) {
			if(route == routeToFrom[i]){
				loc = i;
				break;
			}
		}

		if(ticketsAvailable[loc]>ticketsBooked[loc]){
			ticketsBooked[loc]++;
			return(true);
		} else {
			return(false);
		}

	}
};

//Route class for Vistara airline
class Route3:B737,A320,Vistara {
	vector<string> routeNos;
	vector<string> routeToFrom;
	vector<int> ticketsAvailable;
	vector<int> ticketsBooked;

	public:
	Route3() {
		cout<<"\nAirline :::::: Vistara";
		B737::getBasicData();

		A320::getBasicData();
		char ch;
		while((ch=getchar())!='\n');
		Vistara::getBasicData();
		while((ch=getchar())!='\n');
		routeNos.resize(noOfRoutesServed);
		routeToFrom.resize(noOfRoutesServed);
		ticketsAvailable.resize(noOfRoutesServed);
		ticketsBooked.assign(noOfRoutesServed,0);

		for(int i=0;i<noOfRoutesServed;i++) {
			cout<<"\nEnter the route Number : ";getline(cin,routeNos[i]);
			cout<<"\nEnter the route path : ";getline(cin,routeToFrom[i]);
			cout<<"\nEnter the total number of tickets available for this route : ";cin>>ticketsAvailable[i];
			char ch;
			while((ch=getchar())!='\n');
		}
	}

	void putData(){
		cout<<"\nThe type of aircraft and its details are : ";
		B737::putBasicData(),A320::putBasicData();
		cout<<"\nThe Airline data is : ";
		Vistara::putBasicData();
		cout<<"\nThe data of the routes is : ";
		cout<<"\nRoute Number\tRoutle Name\tTickets Available :: ";
		for(int i=0;i<noOfRoutesServed;i++){
			cout<<"\n"<<routeNos[i]<<"\t"<<routeToFrom[i]<<"\t"<<ticketsAvailable[i];
		}
	}

	bool findBooking(string route){
		int loc;

		for(int i=0;i<noOfRoutesServed;i++) {
			if(route == routeToFrom[i]){
				loc = i;
				break;
			}
		}

		if(ticketsAvailable[loc]>ticketsBooked[loc]){
			ticketsBooked[loc]++;
			return(true);
		} else {
			return(false);
		}

	}
};

//Global Objects
Route1 route1;
Route2 route2;
Route3 route3;

//Passenger Class
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

	void getPassengerData() {
		cout<<"\nEnter your name : ";
		getline(cin,name);
		cout<<"\nEnter your age : ";
		cin>>age;
		char ch;
		while((ch=getchar())!='\n');
		cout<<"\nEnter the route you want the ticket for : ";
		string neededRoute;
		getline(cin,neededRoute);
		cout<<"\nEnter the unique id you have been issued by the GoI : ";
		getline(cin,uid);
		routeBooked = neededRoute;
		bookTicket();
	}

	void putPassengerData() {
		cout<<"\nName of the passenger : ";
		cout<<name;
		cout<<"\nAge of the passenger : ";
		cout<<age;
		cout<<"\nPassenger travel route : "<<routeBooked;
		cout<<"\nUnique Id : "<<uid<<endl;
	}

	void bookTicket() {
		cout<<"\nEnter the airline you want to book with \nBased on the data of the routes and airlines below : \n\n";
		showRoutes();
		string airline;
		getline(cin,airline);

		if(airline == "AirIndia"){
			ticketBooked = route1.findBooking(routeBooked);
		} else if (airline == "Indigo") {
			ticketBooked = route2.findBooking(routeBooked);
		} else if (airline == "Vistara") {
			ticketBooked = route3.findBooking(routeBooked);
		} else {
			cout<<"\nSorry this airline is not found in this universe ";
		}

	}

	string getUID() {
		return(uid);
	}
};



//Function to show for airlines so that the passenger can book according to the
//routes thar are already in place
void showRoutes() {
		cout<<"\nThe route and aircraft details for the airlines are : ";
		route1.putData(),route2.putData(),route3.putData();
	}

//Airline Admin menu
void adminMenu() {
	cout<<"\nWhich airline's data you want to access : ";
	cout<<"\n1.AirIndia\n2.Indigo\n3.Vistara\n4.Exit";
	int ch;
	cin>>ch;
	char _ch;
	while((_ch=getchar())!='\n');

	switch(ch){
		case 1:route1.putData();break;
		case 2:route2.putData();break;
		case 3:route3.putData();break;
		case 4:break;
		default:cout<<"\nWrong choice",adminMenu();break;
	}
}

//User menu to view different details
void userMenu() {
	cout<<"\n1.Book Ticket"<<"\n2.View Ticket Details\n3.Exit";
	int ch;
	cin>>ch;
	char _ch;
	while((_ch=getchar())!='\n');
	Passenger passenger;
	switch(ch){
		case 1:passenger.getPassengerData(),writeToPaxFile(passenger),userMenu();break;
		case 2:readFromPaxFile(),userMenu();break;
		case 3:menu();break;
		default:cout<<"\nWrong choice",userMenu();break;
	}
}

//Menu to access different menus
void menu() {
	cout<<"\n1.ADMIN MAKE CHANGE MENU"<<"\n2.USER MENU"<<"\n4.Exit";
	int ch;
	cin>>ch;
	switch(ch){
		case 1:adminMenu();break;
		case 2:userMenu();break;
		case 4:break;
		default:cout<<"\nWrong choice",menu();break;
	}
}

//Writing passenger data to a file
void writeToPaxFile(Passenger passenger){
		if(passenger.ticketBooked){
				ofstream fout;
				fout.open(paxFileName,ios::binary|ios::app);
						if(fout.is_open()){
							fout.write((char *)&passenger,sizeof(Passenger));
							cout<<"\nWrite to file successfull:";
						} else {
							cout<<"\nWrite failed:";
						}
		} else {
			cout<<"\nTicket Not Booked For This PAX"<<endl;
		}
}

//Reading from the passenger file
void readFromPaxFile() {
	string uid;
	Passenger passenger;
	ifstream fin;
	cout<<"\nEnter the uid you provided for ticket reservation : ";
	getline(cin,uid);
	fin.open(paxFileName,ios::in|ios::binary);
	if(fin.is_open()){

		while(fin.read((char *)&passenger,sizeof(Passenger))){

			if(passenger.getUID()==uid) {
			passenger.putPassengerData();
			cout<<"\nTesting here"<<fin.tellg();
		} else {
			cout<<"\nNo matching data found for this uid";
		}
	}
 } else{
	 cout<<"\nBad filename";
 }
 	fin.close();
}

//Writing to admin files for airline data
void writeToAdminFiles(){
	ofstream fout;
	fout.open(adminFileName1,ios::app|ios::binary);
	fout.write((char *)&route1,sizeof(Route1));
	fout.close();
	fout.open(adminFileName2,ios::app|ios::binary);
	fout.write((char *)&route2,sizeof(Route2));
	fout.close();
	fout.open(adminFileName3,ios::app|ios::binary);
	fout.write((char *)&route3,sizeof(Route3));
	fout.close();
}

//Main function
int main() {

	writeToAdminFiles();
	menu();

	return(0);


}
