#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;


void menu();
void writeToPaxFile(Passenger);
string paxFileName = "paxfile.dat";

enum RouteType {
	longRoute,shortRoute
};


class Airline {
	public:

	virtual void getBasicData() = 0;
	virtual void putBasicData() = 0;
};

class Planes {
	public:

	virtual void getBasicData() = 0;
};


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

class Route1:B737,A320,AirIndia {
	vector<string> routeNos;
	vector<string> routeToFrom;
	vector<int> ticketsAvailable;

	public:

		Route1() {
			B737::getBasicData();

			A320::getBasicData();
			char ch;
			while((ch=getchar())!='\n');
			AirIndia::getBasicData();
			while((ch=getchar())!='\n');
			routeNos.resize(noOfRoutesServed);
			routeToFrom.resize(noOfRoutesServed);
			ticketsAvailable.resize(noOfRoutesServed);

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
};

class Route2:B737,A320,Indigo {
	vector<string> routeNos;
	vector<string> routeToFrom;

public:

	Route2() {
		B737::getBasicData();

		A320::getBasicData();
		char ch;
		while((ch=getchar())!='\n');
		Indigo::getBasicData();
		while((ch=getchar())!='\n');
		routeNos.resize(noOfRoutesServed);
		routeToFrom.resize(noOfRoutesServed);

		for(int i=0;i<noOfRoutesServed;i++) {
			getline(cin,routeNos[i]);
			getline(cin,routeToFrom[i]);
		}
	}

	void putData(){
		cout<<"\nThe type of aircraft and its details are : ";
		B737::putBasicData(),A320::putBasicData();
		cout<<"\nThe Airline data is : ";
		Indigo::putBasicData();
		cout<<"\nThe data of the routes is : ";
		cout<<"\nRoute Number\tRoutle Name :: ";
		for(int i=0;i<noOfRoutesServed;i++){
			cout<<"\n"<<routeNos[i]<<"\t"<<routeToFrom[i];
		}
	}
};

class Route3:B737,A320,Vistara {
	vector<string> routeNos;
	vector<string> routeToFrom;

	public:
	Route3() {
		B737::getBasicData();

		A320::getBasicData();
		char ch;
		while((ch=getchar())!='\n');
		Vistara::getBasicData();
		while((ch=getchar())!='\n');
		routeNos.resize(noOfRoutesServed);
		routeToFrom.resize(noOfRoutesServed);
		cout<<"\nEnter the route Data : ";
		for(int i=0;i<noOfRoutesServed;i++) {
			getline(cin,routeNos[i]);
			getline(cin,routeToFrom[i]);
		}
	}

	void putData(){
		cout<<"\nThe type of aircraft and its details are : ";
		B737::putBasicData(),A320::putBasicData();
		cout<<"\nThe Airline data is : ";
		Vistara::putBasicData();
		cout<<"\nThe data of the routes is : ";
		cout<<"\nRoute Number\tRoutle Name :: ";
		for(int i=0;i<noOfRoutesServed;i++){
			cout<<"\n"<<i+1<<"\n"<<routeNos[i]<<"\t"<<routeToFrom[i];
		}
	}
};

class Passenger {
	string name;
	int age;
	bool ticketBooked;
	string routeBooked;
	string uid;

public:

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

	}

	void putPassengerData() {
		cout<<"\nName of the passenger : ";
		cout<<name;
		cout<<"\nAge of the passenger : ";
		cout<<"age";
		cout<<"\nPassenger travel route : "<<routeBooked;
		cout<<"\nUnique Id : "<<uid<<endl;
	}
};

//Route1 route1;
// Route2 route2;
// Route3 route3;

void adminMenu(){
	// cout<<"\nWhich airline's data you want to access : ";
	// cout<<"\n1.AirIndia\n2.Indigo\n3.Vistara";
	// int ch;
	// cin>>ch;
	// char _ch;
	// while((_ch=getchar())!='\n');
	// switch(ch){
	// 	case 1: route1.getBasicData();break;
	// 	case 2: route2.getBasicData();break;
	// 	case 3: route3.getBasicData();break;
	// 	default:cout<<"\nWrong Choice : ",adminMenu();break;
	// }
}

void adminSeeDataMenu() {
	cout<<"\nWhich airline's data you want to access : ";
	cout<<"\n1.AirIndia\n2.Indigo\n3.Vistara";
	int ch;
	cin>>ch;
	char _ch;
	while((_ch=getchar())!='\n');

	switch(ch){
		//case 1:route1.putData();break;
		// case 2:route2.putData();break;
		// case 3:route3.putData();break;
		default:cout<<"\nWrong choice",adminSeeDataMenu();break;
	}
}

void userMenu() {
	cout<<"\n1.Book Ticket"<<"\n2.View Ticket Details\n3.Exit";
	int ch;
	cin>>ch;
	char _ch;
	while((_ch=getchar())!='\n');
	Passenger passenger;
	switch(ch){
		case 1:passenger.getPassengerData(),userMenu();break;
		case 2:passenger.putPassengerData(),userMenu();break;
		case 3:menu();break;
		default:cout<<"\nWrong choice",userMenu();break;
	}
}

void menu() {
	cout<<"\n1.ADMIN MAKE CHANGE MENU"<<"\n2.USER MENU"<<"\n3.ADMIN SEE DATA MENU\n4.Exit";
	int ch;
	cin>>ch;
	switch(ch){
		case 1:adminMenu();break;
		case 2:userMenu();break;
		case 3:adminSeeDataMenu();break;
		case 4:break;
		default:cout<<"\nWrong choice",menu();break;
	}
}


void writeToPaxFile(Passenger passenger){

}

int main() {
	menu();

	return(0);


}
