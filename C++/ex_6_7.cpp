/*
In ocean navigation, locations are measured in degrees and minutes of latitude and longi-
tude. Thus if you’re lying off the mouth of Papeete Harbor in Tahiti, your location is 149
degrees 34.8 minutes west longitude, and 17 degrees 31.5 minutes south latitude.
This is written as 149°34.8 ’ W, 17°31.5 ’ S. There are 60 minutes in a degree. (An older system
also divided a minute into 60 seconds, but the modern approach is to use decimal minutes
instead.) Longitude is measured from 0 to 180 degrees, east or west from Greenwich,
England, to the international dateline in the Pacific. Latitude is measured from 0 to 90
degrees, north or south from the equator to the poles.
Create a class angle that includes three member variables: an int for degrees, a float
for minutes, and a char for the direction letter (N, S, E, or W). This class can hold either
a latitude variable or a longitude variable. Write one member function to obtain an angle
value (in degrees and minutes) and a direction from the user, and a second to display the
angle value in 179°59.9 ’ E format. Also write a three-argument constructor. Write a
main() program that displays an angle initialized with the constructor, and then, within a
loop, allows the user to input any angle value, and then displays the value. You can use
the hex character constant ‘\xF8’ , which usually prints a degree (°) symbol.

해양 항법에서 위치는 위도와 경도의 도와 분으로 측정됩니다. 
따라서 타히티의 파페트 항구 입구에서 누워 있다면 위치는 서경 149도 34.8분 및 남위 17도 31.5분입니다. 
이것은 149°34.8 '서, 17°31.5 '남으로 표시됩니다. 1도에 60분이 있습니다. 
(과거 시스템은 분을 60초로 나누었지만 현대적인 접근은 소수 분을 사용하는 것입니다.) 
경도는 그리니치, 잉글랜드에서부터 태평양 국제 날짜선까지 동서로 0도에서 180도까지 측정되며, 
위도는 적도에서 극지까지 북남으로 0도에서 90도까지 측정됩니다.

먼저, '각도' 클래스를 생성하세요. 
이 클래스는 도수를 나타내는 정수, 분을 나타내는 부동 소수점 및 방향 문자 (N, S, E 또는 W) 세 개의 멤버 변수를 포함합니다.
이 클래스는 위도 변수 또는 경도 변수를 보유할 수 있습니다. 
사용자로부터 각도 값을 (도와 분으로) 및 방향을 입력받는 멤버 함수를 하나 작성하고, 
각도 값을 '179°59.9 'E' 형식으로 표시하는 두 번째 멤버 함수를 작성하세요.
또한 세 개의 인수를 사용하는 생성자를 작성하세요. 그런 다음 'main()' 프로그램을 작성하고, 
생성자로 초기화된 각도를 표시한 다음 루프 내에서 사용자로부터 모든 각도 값을 입력하고 값을 표시하세요. 
도 (°) 기호를 출력하는 데 사용할 수있는 16 진수 문자 상수 '\xF8'을 사용할 수 있습니다.
*/
#include<iostream>
#include<string>
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
		cout << degree << "° " << min << " '" << dir << "'";
	}
};


int main(void) {
	Angle test;
	test.setAngle();
	test.display();
}
