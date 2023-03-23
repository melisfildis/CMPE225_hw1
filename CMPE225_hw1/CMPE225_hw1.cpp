#include<iostream>
#include<string>
using namespace std;

class Film {
	string name;
	string type;
	double film_registration_fee;

public:

	Film() {}

	Film(string film_name, string film_type) {
		name = film_name;
		type = film_type;
	}
	string getName(void) {
		return this->name;
	}
	double setFee(double ffee) {
		double daily_fee = ffee;
		return daily_fee;
	}
	string getType(void) {
		return this->type;
	}
	double getFee(void) {
		return this->film_registration_fee;
	}
	void add(string cin_name, string cin_type) {
		this->name = cin_name;
		this->type = cin_type;
	}

	friend double calculateMonthlyFee(Film f); //friend function
};

double calculateMonthlyFee(Film f)
{
	if (f.type == "Animation") { //daily fee=11.0
		f.film_registration_fee = f.setFee(11.0) * 30;
	}

	else if (f.type == "Action") { //daily fee=17.0
		f.film_registration_fee = f.setFee(17.0) * 30;
	}

	else {//fee=15.0
		f.film_registration_fee = f.setFee(15.0) * 30;
	}
	return f.film_registration_fee;
}
int main() {
	string option, name, type;
	Film film[2];
	int num, loop, i, a = 0;
	double monthly_fee;

	while (a == 0) {

		cout << "Do you want to add or watch a film (A/W) or enter (C) for exit the system:" << endl;
		cin >> option;


		if ((option == "A") || (option == "a")) {
			for (loop = 0; loop < 2; loop++) {
				cout << "Enter the name of film to be added: ";
				cin >> name;
				cout << "The film name " << name << " is added." << endl;

				cout << "Enter the type:";
				cin >> type;
				cout << "The type of the film is " << type << endl;

				film[loop].add(name, type);
			}
		}

		else if ((option == "W") || (option == "w")) {
			cout << "Enter the number of films:" << endl;
			cin >> num;
			for (i = 0; i < num; i++) {

				cout << "The name of the movie:";
				cin >> name;

				cout << "The type of the movie:";
				cin >> type;

				film[i].add(name, type);
				cout << "You watched a film and the type of the film is " << film[i].getType() << endl;

				monthly_fee = calculateMonthlyFee(film[i]);

				cout << "Film Archive Fee Details:" << endl;
				cout << "-------------------------------------" << endl;

				cout << "The Monthly Rent Fee:" << monthly_fee << "TL" << endl;
				cout << "-------------------------------------" << endl;
			}
		}

		else if ((option == "C") || (option == "c")) {
			cout << "Exit the system." << endl;
			a++;
		}
		else { cout << "Wrong Option!" << endl; }


	}
}
