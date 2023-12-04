#include<iostream>
#include<cstdlib>
using namespace std;
class alpha {
private:
	int data;
public:
	alpha() {}
	alpha(int d) { data = d; }
	alpha(alpha& a) {
		data = a.data;
	}
	alpha& operator = (alpha& obj) {
		data = obj.data;
		//return *(new alpha(data))
		return *this;
	}
	void display() { cout << data; }
	void real() {
		cout << "My object's address is " << this;
	}
};
int main(void) {
	alpha a1(37);
	alpha a2,a3,a4;
	a2 = a4 = a1;
	a2.real();
	a4.real();
	a1.real();
	return 0;
}