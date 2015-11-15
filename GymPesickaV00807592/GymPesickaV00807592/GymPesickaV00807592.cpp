// GymPesickaV00807592.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Elliptical (){

	std::cout << "You use the elliptical";
}

void Treadmill() {

	std::cout << "You run on the treadmill";
}

class Exercise {
public:
	virtual Exercise* clone() = 0;
	virtual void work_out() = 0;
};

class Factory {
public:
	static Exercise* choose_exercise(int choice);
private:
	static Exercise* s_prototypes[4];
};

void menu() {
	std::cout << "Welcome to the Gym.\n";
	std::cout << "Each machine can be used for 20 minutes at a time.\n";
	std::cout << "Please choose an option:\n";
	std::cout << "1) Elliptical\n";
	std::cout << "2) Treadmill\n";
	std::cout << "3) Exercise Bike\n";
	std::cout << "4) Weight Room\n";
	std::cout << "If you'd like to leave, please use exit by typing E.\n";
	std::cout << "Your selection: ";

}

int main()
{
	std::vector<int> line_up;
	string CustomerUse;

	menu();
	while (true) {

		
		getline(cin, CustomerUse);
		if (CustomerUse == "1") {
			std::cout << "You chose to run on the Elliptical.\n";
		}
		else if (CustomerUse == "2") {
			std::cout << "You chose to run on the Treadmill.\n";
		}
		else if (CustomerUse == "3") {
			std::cout << "You chose to ride the Exercise Bike.\n";
		}
		else if (CustomerUse == "4") {
			std::cout << "You chose to work out in the Weight Room.\n";
		}
		else if (CustomerUse == "E") {
			std::cout << "Thank you for chosing our gym for your exercise needs!\n" << endl << endl;
			exit(0);
		}
		else {
			std::cout << "I'm sorry, that is an invalid input, please try again.\n";
		}
		/*
		roles.push_back(
			Factory::choose_exercise(choice));

		for (int i = 0; i < line_up.size(); ++i)
			line_up[i]->work_out();
		for (int i = 0; i < line_up.size(); ++i)
			delete line_up[i];
			*/
		//string s1 = "you chose to " + CustomerUse + ".\n";
		//std::cout << s1;
		//Elliptical();
	}
}

class theElliptical : public Exercise {
public:
	Exercise*   clone() { return new theElliptical; }
	void work_out() {
		cout << "You ran on the elliptical, do you feel the burn?\n";
	}
};
class theTreadmill : public Exercise {
public:
	Exercise*   clone() { return new theTreadmill; }
	void work_out() {
		cout << "You ran on the treadmill, look at those miles go!\n";
	}
};
class ExerciseBike: public Exercise {
public:
	Exercise*   clone() { return new ExerciseBike; }
	void work_out() {
		cout << "You rode on the exercise bike, generate some power!\n";
	}
};

Exercise* Factory::s_prototypes[] = {
	0, new theElliptical, new theTreadmill, new ExerciseBike
};
Exercise* Factory::choose_exercise(int choice) {
	return s_prototypes[choice]->clone();
}

