/*
Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a 50 cent
toll. Mostly they do, but sometimes a car goes by without paying. The tollbooth keeps
track of the number of cars that have gone by, and of the total amount of money collected.
Model this tollbooth with a class called tollBooth . The two data items are a type
unsigned int to hold the total number of cars, and a type double to hold the total amount
of money collected. A constructor initializes both of these to 0. A member function called
payingCar() increments the car total and adds 0.50 to the cash total. Another function,
called nopayCar() , increments the car total but adds nothing to the cash total. Finally, a
member function called display() displays the two totals. Make appropriate member
functions const .
Include a program to test this class. This program should allow the user to push one key
to count a paying car, and another to count a nonpaying car. Pushing the Esc key should
cause the program to print out the total cars and total cash and then exit.
*/
#include<iostream>
using namespace std;
class tollBooth {
private:
	unsigned int Car;
	double Cash;
public:
	tollBooth() {
		Car = 0;
		Cash = 0;
	}
	void PayingCar();
	void nopayCar();
	void display() const;
};
void tollBooth::PayingCar() {
	Car++;
	Cash += 0.5;
}
void tollBooth::nopayCar() {
	Car++;
}
void tollBooth::display() const {
	cout << "총 지나간 차량 : " << Car << endl;
	cout << "총 벌어들인 수입 : " << Cash;
}
const char ESC = 27;
int main(void) {
	

	tollBooth tollboth;
	char ch;
	cout << "Enter 0 for each non-paying car" << endl;
	cout << "Enter 1 for each paying car" << endl;
	cout << "Press 2 to exit" << endl;
	do {
		cin >> ch;
		if (ch == '0') {
			tollboth.nopayCar();
		}
		if (ch == '1') {
			tollboth.PayingCar();
		}
	} while (ch != '2');
	tollboth.display();
	return 0;

}
