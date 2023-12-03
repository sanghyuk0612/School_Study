#include "SLinkedList.h"
#include<string>
class Student {
public:
	int age;    
	string name;
	//Student(string Name, int Age) : name(Name), age(Age) {} 
	//������ �������ָ� ������
	string getName() { return name; }
	int getAge() { return age; }
	void display() {
		cout << "�̸��� " << name << " ���̴� " << age << endl;
	}
};



int main() {

	//int �� �ڷ���
	SLinkedList<int> IntTest;
	cout << "int�� �ڷ��� Ȯ��" << endl;
	IntTest.addFront(5); // 5 - > NULL
	IntTest.addFront(3); // 3-> 5 -> NULL 
	cout << IntTest.front() << endl; //3���
	IntTest.removeFront(); //3���� 5->NULL
	cout << IntTest.front()<<endl; //5���

	cout << endl;
	//float�� �ڷ���
	cout << "float�� �ڷ��� Ȯ��" << endl;
	SLinkedList<float> FloatTest;
	FloatTest.addFront(5.5F); //5.5 -> NULL
	FloatTest.addFront(3.3F); //3.3 ->5.5 NULL
	cout << FloatTest.front() << endl; //3.3���
	FloatTest.removeFront();  //3.3����
	cout << FloatTest.front()<<endl; //5.5���
	cout << endl;

	//string �ڷ��� Ȯ�� 
	cout << "string�� �ڷ��� Ȯ��" << endl;
	SLinkedList<string> StringTest;
	StringTest.addFront("�ȳ��ϼ���."); //�ȳ��ϼ���. -> NULL
	StringTest.addFront("�ݰ����ϴ�."); // �ݰ����ϴ�.->�ȳ��ϼ���. -> NULL
	cout << StringTest.front() << endl; //�ݰ����ϴ�. ���
	StringTest.removeFront();           //�ݰ����ϴ�. ����
	cout << StringTest.front() << endl; //�ȳ��ϼ��� ���
	cout << StringTest.empty() << endl; //������� �ʾƼ� 0 ���

	cout << endl;

	cout << "Student�� �ڷ��� Ȯ��" << endl;
	SLinkedList<Student> StudentTest;
	Student a; //Student ��ü 1
	a.age = 24;
	a.name = "������";
	Student b; //Student ��ü 2
	b.age = 35;
	b.name = "������2";
	//StudentTest.addFront(Student("������",24); �����ڷ� �ٷ� �־��ַ� ������ ��������
	StudentTest.addFront(a); //��ü 1 �־���
	StudentTest.addFront(b); //��ü 2 �־���
	//StudentTest.front().display(); �޼��� ȣ���� �ȵ� getter setter�� ���������� ȣ���� �ȵż� 
	//������ public���� �����Ҽ��ۿ� ������
	cout << "�̸��� "<< StudentTest.front().name << " ���̴� " <<StudentTest.front().age << endl; 
	//��ü 2���̸��� ���� ���
	StudentTest.removeFront(); //��ü 2 ����
	cout << "�̸��� " << StudentTest.front().name << " ���̴� " << StudentTest.front().age << endl; 
	//��ü 1�� �̸��� ���� ���
}

