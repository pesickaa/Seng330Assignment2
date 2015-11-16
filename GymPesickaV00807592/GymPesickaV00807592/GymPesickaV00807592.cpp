// GymPesickaV00807592.cpp : Defines the entry point for the console application.
// Alexis Pesicka
// V00807592
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Exercise {
protected:
	//string ExerciseName;
public:
	//Exercise(ExerciseName* parent = 0); //pass parent to QObject's c-tor in the definition of your c-tor
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
	std::cout << "Each machine can be used for 20 minutes at a time. You can book your work out now.\n";
	std::cout << "Please choose an option:\n";
	std::cout << "Elliptical\n";
	std::cout << "Treadmill\n";
	std::cout << "Exercise Bike\n";
	std::cout << "Weight Room\n";
	std::cout << "To confirm your selections, please type Confirm.\n";
	std::cout << "To see the menu again, please type Menu.\n";
	std::cout << "If you'd like to leave, please use exit by typing Exit.\n";
};

int main()
{
	std::vector<Exercise*> line_up; //This vector holds the exercise lineup the client has selected
	int CustomerUse; //An int that helps us keep everything orderly as each exercise is assigned a number
	string CustomerSelect;//The Client's selection to be compared to the items available
	menu();//Our menu
	string userExerciseName;//The name the client is assigning their selected machine
		
	for (;;) {		
		std::cout << "Your selection: ";
		getline(std::cin, CustomerSelect); //Accepts a full line of information to accomodate Weight Room and Exercise Bike

		//These are the selections that the client can chose from. 
		//Currently, the naming system doesn't work, and causes the whole program to crash after the first confirmation has passed. 
		if (CustomerSelect == "Elliptical") {
			CustomerUse = 1;
			std::cout << "You booked your time on the elliptical\n";
			//std::cout << "What would you like to name your exercise? ";
			//cin >> userExerciseName;
			line_up.push_back(Factory::choose_exercise(CustomerUse));
			//line_up[0]->ExerciseName=userExerciseName;
		}else if (CustomerSelect == "Treadmill") {
			CustomerUse = 2;
			std::cout << "You booked your time on the Treadmill.\n";
			//std::cout << "What would you like to name your exercise? ";
			//cin >> userExerciseName;
			line_up.push_back(Factory::choose_exercise(CustomerUse));
			//line_up[0]->ExerciseName = userExerciseName;
		}else if (CustomerSelect == "Exercise Bike") {
			CustomerUse = 3;
			std::cout << "You booked your time on the Exercise Bike.\n";
			//std::cout << "What would you like to name your exercise? ";
			//cin >> userExerciseName;
			line_up.push_back(Factory::choose_exercise(CustomerUse));
			//line_up[0]->ExerciseName = userExerciseName;
		}else if (CustomerSelect == "Weight Room") {
			CustomerUse = 4;
			std::cout << "You booked your time in the Weight Room.\n";
			//std::cout << "What would you like to name your exercise? ";
			//cin >> userExerciseName;
			line_up.push_back(Factory::choose_exercise(CustomerUse));
			//line_up[0]->ExerciseName = userExerciseName;
		}else if (CustomerSelect == "Confirm") {//Confirms the selections the client has made. Can be singular or multiple selections.
			CustomerUse = 0;
			for (int i = 0; i < line_up.size(); ++i)
				line_up[i]->work_out();
			for (int i = 0; i < line_up.size(); ++i) {
				delete line_up[i];
				line_up.clear();
			}
		}else if (CustomerSelect == "Exit"){
			std::cout << "Thank you for choosing our gym for your exercise needs!\n" << endl << endl;
			system("PAUSE");//Allows the client to see the close statement.
			exit(0);
		}
		else if (CustomerSelect == "Menu") {
			menu();//Prints menu

		}else {
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

class ExerciseBike : public Exercise {
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
		cout << "You worked out in the weight room, pump that iron!\n";
	}
};

Exercise* Factory::choose_exercise(int CustomerUse) {
	return exercise_prototypes[CustomerUse]->clone();
};

Exercise* Factory::exercise_prototypes[] = {
	0, new theElliptical, new theTreadmill, new ExerciseBike, new WeightRoom
};