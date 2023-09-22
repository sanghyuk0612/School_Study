/*
Start with the date structure in Exercise 5 in Chapter 4 and transform it into a date
class. Its member data should consist of three int s: month , day , and year . It should also
have two member functions: getdate() , which allows the user to enter a date in
12/31/02 format, and showdate() , which displays the date.

Chapter 4의 연습문제 5에서 제공된 날짜 구조체를 사용하여 날짜 클래스로 변환하는 작업을 수행하겠습니다. 
이 클래스는 세 개의 정수형 데이터 멤버인 월 (month), 일 (day), 그리고 년도 (year)를 가지며, 
두 개의 멤버 함수인 getdate()와 showdate()를 가지고 있어야 합니다. 
getdate() 함수는 사용자로부터 "12/31/02" 형식의 날짜를 입력받는 데 사용되며, 
showdate() 함수는 입력된 날짜를 표시하는 데 사용됩니다.
*/
#include<string>
#include<iostream>
#include<sstream>
using namespace std;
class cal {
private:
	int month;
	int day;
	int year;
public:
	void getdate(string day);
	void showdate();
};
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
	cal test;
	test.getdate("23/12/06");
	test.showdate();

}
