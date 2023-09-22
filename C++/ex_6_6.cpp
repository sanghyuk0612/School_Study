/*
Extend the employee class of Exercise 4 to include a date class (see Exercise 5) and an
etype enum (see Exercise 6 in Chapter 4). An object of the date class should be used to
hold the date of first employment; that is, the date when the employee was hired. The
etype variable should hold the employee’s type: laborer, secretary, manager, and so on.
These two items will be private member data in the employee definition, just like the
employee number and salary. You’ll need to extend the getemploy() and putemploy()
functions to obtain this new information from the user and display it. These functions will
probably need switch statements to handle the etype variable. Write a main() program that
allows the user to enter data for three employee variables and then displays this data.


Exercise 4의 직원 클래스를 확장하여 날짜 클래스(Exercise 5 참조)와 etype 열거형(Chapter 4의 Exercise 6 참조)을 포함하도록 합니다. 
날짜 클래스의 객체는 직원이 고용된 첫 번째 날짜를 저장하는 데 사용되며, etype 변수는 직원의 유형을 저장합니다: 노동자, 비서, 관리자 등입니다. 
이 두 항목은 직원 정의의 private 멤버 데이터로 처리되며, 직원 번호와 급여처럼 처리됩니다. 
이 새로운 정보를 사용자로부터 얻고 표시하기 위해 getemploy() 및 putemploy() 함수를 확장해야 할 것입니다.
이러한 함수는 etype 변수를 처리하기 위해 스위치 문을 사용해야 할 것입니다. 
사용자로부터 세 명의 직원 변수에 대한 데이터를 입력하고 이 데이터를 표시하는 main() 프로그램을 작성하세요.
*/
#include<string>
#include<sstream>
#include<iostream>
using namespace std;
enum etype {
	노동자, 비서, 관리자
};
class cal {
private:
	int month;
	int day;
	int year;
public:
	void getdate(string day);
	void showdate();
};
class employ {
private:
	cal date;
	etype type;
public:
	void getemploy();
	void putemploy();
};
void employ::getemploy() {
	cout << "그 사원의 직급은 : ";
	switch (type) {
	case 0:
		cout << "노동자";
		break;
	case 1:
		cout << "비서";
		break;
	case 2:
		cout << "관리자";
		break;
	}
	cout << endl;
	cout << "그 사원의 입사날짜는 : ";
	date.showdate();
}
void employ::putemploy() {
	int num;
	string calen;
	cout << "직급을 입력해주세요 (노동자 : 1, 비서 : 2, 관리자 : 3) : "; cin >> num;
	switch (num) {
	case 1:
		type = 노동자;
		break;
	case 2:
		type = 비서;
		break;
	case 3:
		type = 관리자;
		break;
	}
	cout << "입사 날짜를 알려주세요 (23/01/42) : "; cin >> calen;
	date.getdate(calen);
}
void cal::getdate(string calender) {
	istringstream iss(calender);
	char sep = '/';
	string buff;
	getline(iss, buff, sep);
	year = stoi(buff);
	getline(iss, buff, sep);
	month = stoi(buff);
	getline(iss, buff, sep);
	day = stoi(buff);

}
void cal::showdate() {
	cout << year << " / " << month << " / " << day << endl;
}
int main(void) {
	employ test1;
	test1.putemploy();
	test1.getemploy();
}
