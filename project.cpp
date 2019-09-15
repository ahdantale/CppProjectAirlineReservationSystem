#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;



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
		cout<<"\nThe seats available on the B737 are : ";
		cout<<noOfSeats;
		cout<<"\nThe type of route of the B737 is : ";
		if (routeType == longRoute) {
			cout<<"Long Route";
		} else {
			cout<<"Short Route";
		}

	}
};


int main() {
	Vistara test;
	A320 testing;
	test.getBasicData();
	test.putBasicData();
	testing.getBasicData();
	testing.putBasicData();
	return(0);


}
