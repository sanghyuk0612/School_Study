/*
Create an employee class, basing it on Exercise 4 of Chapter 4. The member data should
comprise an int for storing the employee number and a float for storing the employee’s
compensation. Member functions should allow the user to enter this data and display it.
Write a main() that allows the user to enter data for three employees and display it.

"Employee" 클래스를 생성하여 직원 정보를 관리하는 클래스입니다. 
이 클래스는 직원 번호를 나타내는 int 멤버 변수와 직원 보상을 나타내는 float 멤버 변수로 구성됩니다.
또한 사용자가 이 데이터를 입력하고 표시할 수 있는 멤버 함수가 있습니다.

main() 함수에서는 사용자에게 세 명의 직원 정보를 입력하고 이 정보를 표시할 수 있습니다.
*/

#include<iostream>
using namespace std;
class Employee {
private:
	int num;
	float rew;
public:
	Employee(int number) {
		num = number;
		rew = 0;
	}
	void Change(float money) {
		rew = money;
	}
	void display() {
		cout << "직원 번호 : " << num;
		cout << " 직원 수당 : " << rew << endl;
	}

};

int main(void) {
	Employee tem1(1);
	Employee tem2(2);
	Employee tem3(3);
	tem1.Change(100);
	tem2.Change(200);
	tem3.Change(300);
	tem1.display();
	tem2.display();
	tem3.display();
}
