/*
Modify the four-function fraction calculator of Exercise 12 in Chapter 5 to use a
fraction class rather than a structure. There should be member functions for input and
output, as well as for the four arithmetical operations. While you’re at it, you might as
well install the capability to reduce fractions to lowest terms. Here’s a member function
that will reduce the fraction object of which it is a member to lowest terms. It finds the
greatest common divisor (gcd) of the fraction’s numerator and denominator, and uses this
gcd to divide both numbers.

Chapter 5의 연습문제 12에서 사용한 사칙연산 분수 계산기를 구조체 대신 분수 클래스를 사용하도록 수정하세요. 
입력 및 출력을 위한 멤버 함수와 네 가지 산술 연산을 수행하는 멤버 함수가 있어야 합니다. 
이와 더불어 분수를 기약분수로 간소화하는 기능도 구현하세요. 
다음은 해당 분수 객체를 기약분수로 줄이기 위한 멤버 함수입니다. 
이 함수는 분수의 분자와 분모의 최대공약수(gcd)를 찾고 이 gcd를 사용하여 두 숫자를 나눕니다.
*/

#include<iostream>
#include<string>
using namespace std;
class fraction {
public:
	int son;
	int mom;
	void display() {
		if (son == 0)
			cout << 0 << endl;
		else if (son == mom)
			cout << 1 << endl;
		else
			cout << son << "/" << mom << endl;
	}
	void set_frac() {
		cout << "분수를 입력해주세요(p/q) :";
		char temp;
		cin >> son >> temp >> mom;
	}
};
class calculate {
public:
	fraction plus(fraction a, fraction b);
	fraction minus(fraction a, fraction b);
	fraction multi(fraction a, fraction b);
	fraction div(fraction a, fraction b);
	fraction minimum(fraction a);
};

int main(void) {
	fraction test1, test2;
	calculate cal;
	test1.set_frac();
	test2.set_frac();
	cout << "puls : ";
	cal.plus(test1, test2).display();
	cout << "minus : ";
	cal.minus(test1, test2).display();
	cout << "div : ";
	cal.div(test1, test2).display();
	cout << "multi : ";
	cal.multi(test1, test2).display();
}

fraction calculate::plus(fraction a, fraction b)
{
	fraction temp;
	temp.son = a.son * b.mom + b.son * b.mom;
	temp.mom = a.mom * b.mom;
	temp = minimum(temp);
	return temp;
}

fraction calculate::minus(fraction a, fraction b)
{
	fraction temp;
	temp.son = a.son * b.mom - b.son * b.mom;
	temp.mom = a.mom * b.mom;
	temp = minimum(temp);
	return temp;
}

fraction calculate::multi(fraction a, fraction b)
{
	fraction temp;
	temp.son = a.son * b.son;
	temp.mom = a.mom * b.mom;
	temp = minimum(temp);
	return temp;
}

fraction calculate::div(fraction a, fraction b)
{
	fraction temp;
	temp.son = a.son * b.mom;
	temp.mom = a.mom * b.son;
	temp = minimum(temp);
	return temp;
}

fraction calculate::minimum(fraction a)
{
	int n1 = a.mom;
	int n2 = a.son;
	int temp, n;
	if (n1 < n2) {
		temp = n1;
		n1 = n2;
		n2 = temp;
	}
	while (n2 != 0) {
		n = n1 % n2;
		n1 = n2;
		n2 = n;
	}
	a.mom = a.mom / n1;
	a.son = a.son / n1;
	return a;
}
