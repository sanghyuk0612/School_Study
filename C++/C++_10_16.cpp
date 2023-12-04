#include<iostream>

using namespace std;
class String {
private:
	char* str;
public:
	String(char* s) {
		str = s;
	}
	~String() {
		cout << "Deleting str. \n";
		delete[] str;
	}
	void display() {
		cout << str << endl;
	}
};
void eraser(String str) {

}

class DynamicSingleton {
private:
	string name;
	DynamicSingleton() : name("Dweb") {};
	DynamicSingleton(const DynamicSingleton& other);
	static DynamicSingleton* instance;
public:
	string getName() { return name; }
	static DynamicSingleton* GetInstance() {
		if (instance == NULL) instance= new DynamicSingleton();
		return instance;
	}
};
DynamicSingleton* DynamicSingleton::instance = nullptr;
int main(void) {
	DynamicSingleton* obj1 = DynamicSingleton::GetInstance();
	DynamicSingleton* obj2 = DynamicSingleton::GetInstance();
	DynamicSingleton& obj3 = *obj2;
	cout << obj1->getName() << endl;
	cout << obj2->getName() << endl;
	cout << obj3.getName() << endl;
	cout << obj1 << endl;
	/*A s1("Dweb");
	A s2 = s1;
	if (s1.getString() == s2.getString())
		cout << "The data in d2 is the same as that in s1." << endl;
	if (s1.getAddr() != s2.getAddr())
		cout << "s2 is different from s1" << endl;
	else
		cout << "s1 == s2 adress";*/
	
	return 0;
}