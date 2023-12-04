#include<iostream>
using namespace std;

const int LEN = 80;

class employee {
private:
	char name[LEN];
	unsigned long number;
public:
	friend istream& operator >> (istream& s, employee& e);
};


//template<class TYPE>
//class linklist {
//private:
//	linke<TYPE>* first;
//public:
//	linklist() {
//	}
//	void addlink(TYPE d);
//};
//template<class TYPE>
//void linklist<TYPE>::addlink(TYPE d) {
//
//
//}

//template <class T>
//T abs(T a) {
//	return (a < 0) ? -a : a;
//}
//
//template <class atype>
//int find(atype* array, atype value, int size) {
//	for (int j = 0;j < size;j++)
//		if (array[j] == value)
//			return j;
//	retunr - 1;
//}
//template<class atype, class btype>
//btype find(atype* array, atype value, btype size) {
//	for (btype j = 0;j < size; j++)
//		if (array[i] = value)
//			return j;
//	return static_cast<btype>(-1);
//}
//char chrArr[] = { 1,3,5,9.11,13 };
//char ch = 5;
//
//int intArr[] = { 1,3,5,9,11,13 };
//int in = 6;
//
//long lonArr[] = { 1L,3L,5L,9L,11L,13L };
//long lo = 11L;
//
//double dubArr[] = { 1.0,3.0,5.0,9.0,11.0,13.0 };
//double db = 4.0;
//
//template<class type>
//class Stack {
//private:
//	type st[100];
//	int top;
//public:
//	Stack() { top = -1; }
//	void push(type var) { st[++top] = var };
//	type pop();
//};
//template<class type>
//Stack<type>::Stack() {
//	return st = -1;
//}
int main() {



	/*Stack<float> s1;
	s1.push(1111.4F);
	s1.push(2222.2F);
	s1.push(3333.3F);*/

	//cout << "\n 5 in chrArary : index = " << find(chrArr, ch, 5);
	/*int int1 = 5;
	int int2 = -6;
	long long1 = 2000L;
	long long2 = -80000L;

	double dub1 = 9.95;
	double dub2 = -10.15;
	cout << "\nabs(" << int1 << ")=" << abs(int1);
	cout << "\nabs(" << int2 << ")=" << abs(int2);
	cout << "\nabs(" << long1 << ")=" << abs(long1);
	cout << "\nabs(" << long2 << ")=" << abs(long2);
	cout << "\nabs(" << dub1 << ")=" << abs(dub1);
	cout << "\nabs(" << dub2 << ")=" << abs(dub2);*/

}