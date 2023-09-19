/*

"Time"라는 클래스를 생성하겠습니다. 이 클래스는 시간을 나타내기 위한 별도의 int 멤버 데이터를 시간(hours), 
분(minutes), 그리고 초(seconds)로 가집니다. 하나의 생성자는 이 데이터를 모두 0으로 초기화하고, 
다른 생성자는 고정된 값으로 초기화할 수 있도록 할 것입니다. 또 다른 멤버 함수는 시간을 "11:59:59" 형식으로 표시할 것이며, 
마지막 멤버 함수는 인수로 전달된 두 개의 time 객체를 더할 것입니다.
그리고 main() 프로그램은 초기화된 두 개의 time 객체와 초기화되지 않은 하나의 time 객체를 생성합니다. 
그런 다음, 두 초기화된 값을 더하여 결과를 세 번째 time 변수에 저장하고, 이 세 번째 변수의 값을 표시합니다.
모든 멤버 함수는 적절하게 const로 선언됩니다.

Create a class called time that has separate int member data for hours, minutes, and
seconds. One constructor should initialize this data to 0, and another should initialize it
to fixed values. Another member function should display it, in 11:59:59 format. The final
member function should add two objects of type time passed as arguments.
A main() program should create two initialized time objects (should they be const ?) and
one that isn’t initialized. Then it should add the two initialized values together, leaving the
result in the third time variable. Finally it should display the value of this third variable.
Make appropriate member functions const .
*/
#include<iostream>
using namespace std;
class Time {
private:
	int hours, minutes, seconds;
public:
	Time() {
		hours = 0;
		minutes = 0;
		seconds = 0;
	}
	Time(int hour, int minute, int second) {
		hours = hour;
		minutes = minute;
		seconds = second;
	}
	void display() {
		cout << hours << " : " << minutes << " : " << seconds << endl;
	}
	Time operator+(Time tmp){
		int tmp_h = hours + tmp.hours;
		int tmp_m = minutes + tmp.minutes;
		int tmp_s = seconds + tmp.seconds;
		if (tmp_s >= 60) {
			tmp_s %= 60;
			tmp_m++;
		}
		if (tmp_m >= 60) {
			tmp_m %= 60;
			tmp_h++;
		}
		if (tmp_h >= 24) {
			tmp_h %= 24;
		}

		return Time(tmp_h, tmp_m, tmp_s);
	}
};
int main(void) {
	Time tim1(3,13,45);
	Time tim2(5, 49, 39);
	Time tim3;
	tim1.display();
	tim2.display();
	tim3.display();
	tim3 = tim1 + tim2;
	tim3.display();
}
