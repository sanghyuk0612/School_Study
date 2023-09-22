/*
Create a class that includes a data member that holds a “serial number” for each object
created from the class. That is, the first object created will be numbered 1, the second 2,
and so on.
To do this, you’ll need another data member that records a count of how many objects
have been created so far. (This member should apply to the class as a whole; not to
individual objects. What keyword specifies this?) Then, as each object is created, its
constructor can examine this count member variable to determine the appropriate serial
number for the new object.
Add a member function that permits an object to report its own serial number. Then
write a main() program that creates three objects and queries each one about its serial
number. They should respond I am object number 2 , and so on.


"시리얼 번호"를 나타내는 데이터 멤버를 보유하는 클래스를 생성하십시오. 
즉, 처음으로 생성된 객체는 1로 번호 지정되고, 두 번째 객체는 2로 번호 지정되는 식입니다.
이를 위해 지금까지 생성된 객체 수를 기록하는 다른 데이터 멤버가 필요합니다. 
(이 멤버는 개별 객체에 적용되는 것이 아니라 클래스 전체에 적용되어야 합니다.이를 지정하는 키워드는 무엇인가요?) 
그런 다음 각 객체가 생성될 때마다 해당 객체에 대한 적절한 시리얼 번호를 결정하기 위해 생성자는 이 카운트 멤버 변수를 검사할 수 있습니다.
객체 자체의 시리얼 번호를 보고할 수 있는 멤버 함수를 추가하세요. 
그런 다음 세 개의 객체를 생성하고 각각의 시리얼 번호에 대해 쿼리하는 'main()' 프로그램을 작성하세요. 
이들은 "나는 객체 번호 2입니다"와 같이 응답해야 합니다.
*/
#include<iostream>
#include<string>
using namespace std;
class number {
private:
	int num;
public:
	number() {
		static int counting = 1;
		num = counting++;
	}
	void display() {
		cout << "나는 객체 번호 " << num << "입니다." << endl;
	}
};
int main(void) {
	number test1;
	number test2;
	number test3;
	test1.display();
	test2.display();
	test3.display();
}
