#include<iostream>

using namespace std;

class Counter {
protected:
	unsigned int count;
public:
	Counter() : count(0) {}
	Counter(int c) : count(c) {}
	unsigned int get_count() const { return count; }
	
	Counter operator ++() { return Counter(++count); }
	Counter operator ++(int) { return Counter(count++); }
};
class CountDn : public Counter {
public:
	CountDn() {};
	
	CountDn(int c) :Counter(c) {}//상위클래스의 생성자 호출
	Counter operator --() { return Counter(--count);}
	Counter operator --(int) { return Counter(count--); }
};
int main(void) {
	CountDn c1(100);
	cout << "\nc1 =" << c1.get_count() << endl;
	++c1;++c1;++c1;
	cout << "\nc1 =" << c1.get_count() << endl;
	c1--;--c1;
	cout << "\nc1 =" << c1.get_count() << endl;
}