// GymPesickaV00807592.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Exercise {
public:
	virtual Exercise* clone() = 0;
	virtual void work_out() = 0;
};

class Factory {
public:
	static Exercise* choose_exercise(int choice);
private:
	static Exercise* exercise_prototypes[5];
};

void menu() {
	std::cout << "Welcome to the Gym.\n";
	std::cout << "Each machine can be used for 20 minutes at a time.\n";
	std::cout << "Please choose an option:\n";
	std::cout << "1) Elliptical\n";
	std::cout << "2) Treadmill\n";
	std::cout << "3) Exercise Bike\n";
	std::cout << "4) Weight Room\n";
	std::cout << "If you'd like to leave, please use exit by typing 0.\n";
	std::cout << "Your selection: ";

}

int main()
{
	std::vector<Exercise*> line_up;
	int CustomerUse;

	menu();
	while (true) {

		
		cin >> CustomerUse;
		if (CustomerUse == 1) {
			std::cout << "You booked your time on the elliptical\n";
			line_up.push_back(Factory::choose_exercise(CustomerUse));
		}
		else if (CustomerUse == 2) {
			std::cout << "You booked your time on the Treadmill.\n";
			line_up.push_back(Factory::choose_exercise(CustomerUse));
		}
		else if (CustomerUse == 3) {
			std::cout << "You booked your time on the Exercise Bike.\n";
			line_up.push_back(Factory::choose_exercise(CustomerUse));
		}
		else if (CustomerUse == 4) {
			std::cout << "You booked your time in the Weight Room.\n";
			line_up.push_back(Factory::choose_exercise(CustomerUse));
		}
		else if (CustomerUse == 0) {
			for (int i = 0; i < line_up.size(); ++i)
				line_up[i]->work_out();
			for (int i = 0; i < line_up.size(); ++i)
				delete line_up[i];
			std::cout << "Thank you for choosing our gym for your exercise needs!\n" << endl << endl;
			system("PAUSE");
			exit(0);
		}
		else {
			std::cout << "I'm sorry, that is an invalid input, please try again.\n";
			
		}
		
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
class WeightRoom : public Exercise {
public:
	Exercise*   clone() { return new WeightRoom; }
	void work_out() {
		cout << "You worked out in the weight room, pump the iron!\n";
	}
};
Exercise* Factory::choose_exercise(int CustomerUse) {
	return exercise_prototypes[CustomerUse]->clone();
};

Exercise* Factory::exercise_prototypes[] = {
	0, new theElliptical, new theTreadmill, new ExerciseBike, new WeightRoom
};



