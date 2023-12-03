#include "SLinkedList.h"
#include<string>
class Student {
public:
	int age;    
	string name;
	//Student(string Name, int Age) : name(Name), age(Age) {} 
	//생성자 정의해주면 에러남
	string getName() { return name; }
	int getAge() { return age; }
	void display() {
		cout << "이름은 " << name << " 나이는 " << age << endl;
	}
};



int main() {

	//int 형 자료형
	SLinkedList<int> IntTest;
	cout << "int형 자료형 확인" << endl;
	IntTest.addFront(5); // 5 - > NULL
	IntTest.addFront(3); // 3-> 5 -> NULL 
	cout << IntTest.front() << endl; //3출력
	IntTest.removeFront(); //3제거 5->NULL
	cout << IntTest.front()<<endl; //5출력

	cout << endl;
	//float형 자료형
	cout << "float형 자료형 확인" << endl;
	SLinkedList<float> FloatTest;
	FloatTest.addFront(5.5F); //5.5 -> NULL
	FloatTest.addFront(3.3F); //3.3 ->5.5 NULL
	cout << FloatTest.front() << endl; //3.3출력
	FloatTest.removeFront();  //3.3제거
	cout << FloatTest.front()<<endl; //5.5출력
	cout << endl;

	//string 자료형 확인 
	cout << "string형 자료형 확인" << endl;
	SLinkedList<string> StringTest;
	StringTest.addFront("안녕하세요."); //안녕하세요. -> NULL
	StringTest.addFront("반갑습니다."); // 반갑습니다.->안녕하세요. -> NULL
	cout << StringTest.front() << endl; //반갑습니다. 출력
	StringTest.removeFront();           //반갑습니다. 제거
	cout << StringTest.front() << endl; //안녕하세요 출력
	cout << StringTest.empty() << endl; //비어있지 않아서 0 출력

	cout << endl;

	cout << "Student형 자료형 확인" << endl;
	SLinkedList<Student> StudentTest;
	Student a; //Student 객체 1
	a.age = 24;
	a.name = "정상혁";
	Student b; //Student 객체 2
	b.age = 35;
	b.name = "정상혁2";
	//StudentTest.addFront(Student("정상혁",24); 생성자로 바로 넣어주려 했지만 에러나옴
	StudentTest.addFront(a); //객체 1 넣어줌
	StudentTest.addFront(b); //객체 2 넣어줌
	//StudentTest.front().display(); 메서드 호출이 안됨 getter setter도 마찬가지로 호출이 안돼서 
	//변수를 public으로 선언할수밖에 없었음
	cout << "이름은 "<< StudentTest.front().name << " 나이는 " <<StudentTest.front().age << endl; 
	//객체 2의이름과 나이 출력
	StudentTest.removeFront(); //객체 2 제거
	cout << "이름은 " << StudentTest.front().name << " 나이는 " << StudentTest.front().age << endl; 
	//객체 1의 이름과 나이 출력
}

