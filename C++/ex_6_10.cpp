/*
Create a class called ship that incorporates a ship’s number and location. Use the
approach of Exercise 8 to number each ship object as it is created. Use two variables of
the angle class from Exercise 7 to represent the ship’s latitude and longitude. A member
function of the ship class should get a position from the user and store it in the object;
another should report the serial number and position. Write a main() program that cre-
ates three ships, asks the user to input the position of each, and then displays each ship’s
number and position.

다음과 같이 선박 번호와 위치를 포함하는 'ship' 클래스를 만들어보겠습니다.
이 클래스는 연습문제 8의 접근 방식을 사용하여 각 선박 객체가 생성될 때마다 번호를 할당합니다. 
또한 연습문제 7의 각도 클래스에서 파생된 두 변수를 사용하여 선박의 위도와 경도를 나타냅니다. 
'ship' 클래스의 멤버 함수 중 하나는 사용자로부터 위치를 입력받아 객체에 저장하고, 
다른 하나는 일련 번호와 위치를 보고합니다. 
마지막으로 'main()' 프로그램을 작성하여 세 개의 선박을 생성하고 사용자로부터 각 선박의 위치를 입력하고, 
각 선박의 번호와 위치를 표시합니다.
*/
#include<iostream>
using namespace std;
class Angle {
private:
	int degree;
	double min;
	string dir;
public:
	void setAngle() {
		cout << "몇 도인지 입력해주세요 : "; cin >> degree; cout << endl;
		cout << "몇 분인지 입력해주세요 : "; cin >> min; cout << endl;
		cout << "방향을 알려주세요(N, S, E, W) : "; cin >> dir; cout << endl;
	}
	void display() {
		cout << degree << "° " << min << " '" << dir << "'"<<endl;
	}
};
class ship {
private:
	Angle Ang;
public:
	ship() {
		static int num = 0;
		num++;
	}
	void set_ship_loc() {
		Ang.setAngle();
	}
	void display_ship() {
		Ang.display();
	}
};


int main(void) {
	ship s1;
	ship s2;
	ship s3;
	s1.set_ship_loc();
	s2.set_ship_loc();
	s3.set_ship_loc();
	s1.display_ship();
	s2.display_ship();
	s3.display_ship();
}
