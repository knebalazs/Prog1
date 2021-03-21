#include <iostream>
#include <string>
#include "std_lib_facilities.h"

using namespace std;

struct Person {

	Person() : first_name("init"), last_name("init"), a(0) {};
	Person(string set_first_name, string set_last_name, int set_age);
	const string name() { return first_name + ' ' + last_name; }
	const string get_first_name() { return first_name; }
	const int age () { return a; }

	private :
		string first_name;
		string last_name; 
		int a;

};

Person::Person(string set_fitst_name, string set_last_name, int set_age) : first_name{set_fitst_name}, last_name{set_last_name}, a{set_age} {

	if (set_age < 0 || set_age > 150) error("invalid age");
	for (char c : set_fitst_name + set_last_name) {
		switch (c){
			case ';' : error("invalid character"); break;
			case ':' : error("invalid character"); break;
			case '"' : error("invalid character"); break;
			case '`' : error("invalid character"); break;
			case '[' : error("invalid character"); break;
			case ']' : error("invalid character"); break;
			case '*' : error("invalid character"); break;
			case '&' : error("invalid character"); break;
			case '^' : error("invalid character"); break;
			case '%' : error("invalid character"); break;
			case '$' : error("invalid character"); break;
			case '#' : error("invalid character"); break;
			case '@' : error("invalid character"); break;
			case '!' : error("invalid character"); break;
			default : break;
		}
	}
}

ostream& operator<< (ostream& os, Person& x){

	return os << x.name() << " " << x.age() << endl;

}

istream& operator>> (istream& is, Person& x){

	string first_name;
	string last_name;
	int age;

	cout << "enter person first name: ";
	is >> first_name;
	cout << "enter person last name: ";
	is >> last_name;
	cout << "enter person age: ";
	is >> age;

	x = Person{first_name, last_name, age};

	return is;

}

int main()
try{

	Person person1;
	char stop;

	/*
	person1.name = "Goofy";
	person1.age = 68;
	cout << person1.name << endl;
	cout << person1.age << endl;
	*/

	vector<Person> v;

	for(Person i;cin >> i;v.push_back(i)) {
		cout << "press c to continue or press x to exit:  ";
		cin >> stop;
		if (stop == 'x'){
			v.push_back(i);
			break;
		}
		
	}
	
	for(Person y  : v)
		cout << y ;

} catch(exception& e){
	cerr << "Execption:" << e.what() << endl;
	return 1;
}