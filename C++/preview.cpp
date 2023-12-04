#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class strCount {
private:
	int count;
	char* str;
	friend class String;
	strCount(const char* s) {
		int length = strlen(s);
		str = new char[length + 1];
		strcpy(str, s);
		count = 1;
	}
	~strCount() { delete[] str; }
};
class String {
private:
	strCount* psc;
public:
	String() { psc = new strCount("NULL"); }
	String(String& S) { psc = S.psc;(psc->count++); }
	~String() {
		if (psc->count == 1)
			delete psc;
		else
			(psc->count)--;
	}
	void display() {
		cout << psc->str;
		cout << " (addr=" << psc << ")";
	}
	void operator = (String& s) {
		if (psc->count == 1)
			delete psc;
		else
			(psc->count)--;
		psc = s.psc;
		(psc->count)++;
	}
};
int main(void) {
	//String s3 = "DIscributed System and Web design";
}