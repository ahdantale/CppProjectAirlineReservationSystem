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

			for(int i=0;i<noOfRoutesServed;i++) {
				getline(cin,routeNos[i]);
				getline(cin,routeToFrom[i]);
			}
		}

		void putData(){
			cout<<"\nThe type of aircraft and its details are : ";
			B737::putBasicData(),A320::putBasicData();
			cout<<"\nThe Airline data is : ";
			AirIndia::putBasicData();
			cout<<"\nThe data of the routes is : ";
			cout<<"\nRoute Number\tRoutle Name :: ";
			for(int i=0;i<noOfRoutesServed;i++){
				cout<<"\n"<<routeNos[i]<<"\t"<<routeToFrom[i];
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


int main() {
	Route2 route;
	route.putData();

	return(0);


}
