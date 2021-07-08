#include <iostream>
#include <vector>
#define all(x) x.begin(),x.end() 
using namespace std;
class User{
	public:
	int id;
	string name;
	string location;
	string carPref;
	User(int id,string name,string location){
		this->id=id;
		this->name=name;
		this->location=location;
	}
	void getPrefereces(string carPref){
		this->carPref=carPref;
	}
};
class Driver{
	public:
	int id;
	string name;
	string location;
	string car;
	vector<string> reviews; 
	Driver(int id,string name,string location,string car){
		this->id=id;
		this->name=name;
		this->car=car;
		this->location=location;
	}
	void storeReview(string s){
		reviews.push_back(s);
	}
};
class Db{
	public:
	vector<User> users;
	vector<Driver> drivers;
	void addUser(User user){
		users.push_back(user);
	}
	void addDriver(Driver driver){
		drivers.push_back(driver);
	}
	void showUser(int id){
		cout<<"user_name : "<<users[id-1].name<<endl;
		cout<<"location : "<<users[id-1].location;
	}
	void getDriverForLocation(int id){
		string locat = users[id-1].location;
		string car = drivers[id-1].car;
		for(int i=0;i<drivers.size();i++){
			if(locat==drivers[i].location && car==drivers[i].car){
				cout<<"Driver Name: "<<drivers[i].name<<endl;
				cout<<"Driver Location: "<<drivers[i].location<<endl;
				cout<<"Driver Car: "<<drivers[i].car<<endl;
				break;
			}
		}
	}
	void addReview(int id,string s){
		drivers[id-1].storeReview(s);
	}
	void viewDriverReviews(int id){
		cout<<"Reviews for "<<drivers[id-1].name<<":"<<endl;
		for(string s:drivers[id-1].reviews){
			cout<<s<<endl;
		}
	}
};

int main()
{
	Db db;
	User user(1,"Ash","poy");
	Driver driver1(1,"Muth","poy","Xteem");
	Driver driver2(2,"Karupu","poy","RollsRoylce");
	db.addUser(user);
	db.addDriver(driver1);
	db.addDriver(driver2);
	// if users need preferences
	user.getPrefereces("Xteem");
	// add review
	db.addReview(2,"Nice Driving Man");
	db.addReview(1,"Dangerous Driver Thou!!");
	db.addReview(1,"Dangerous But Safe Thou!!");
	db.addReview(2,"Killer ride Man!!");
	// user & location == driver & location
	cout<<"---------------------"<<endl;
	db.getDriverForLocation(1);
	// view drivers review
	cout<<"---------------------"<<endl;
	db.viewDriverReviews(1);
	cout<<"---------------------"<<endl;
	return 0;
}
