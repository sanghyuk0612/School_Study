#include<iostream>
#include<cstdlib>
#include<string>
using namespace std; // std::을 쓸 필요가 없음
struct Student {
	string name;
	int number;
	float goal;
};

namespace A {
	void temp_print() {
		cout << "INU_A" << endl;
	}
}
namespace B {
	void temp_print() {
		cout << "INU_B" << endl;
	}
}
void pointer(int *a,int *b) {
	*a = 5;
	*b = 3;
}
int main(void) {
	Student *test;
	test = new Student;
	test->name = "상혁";
	test->number = 01020213420;
	test->goal = 4.32;
	cout << "이름은 " << test->name << endl << "번호는 " << test->number << endl << "학점은 " << test->goal;
	delete test;
	return EXIT_SUCCESS;//define으로 0로 정의되어있음
	
}