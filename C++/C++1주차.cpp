#include<iostream>
#include<cstdlib>
#include<string>
using namespace std; // std::�� �� �ʿ䰡 ����
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
	test->name = "����";
	test->number = 01020213420;
	test->goal = 4.32;
	cout << "�̸��� " << test->name << endl << "��ȣ�� " << test->number << endl << "������ " << test->goal;
	delete test;
	return EXIT_SUCCESS;//define���� 0�� ���ǵǾ�����
	
}