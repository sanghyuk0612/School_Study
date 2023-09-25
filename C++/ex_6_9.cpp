/*
Transform the fraction structure from Exercise 8 in Chapter 4 into a fraction class.
Member data is the fraction’s numerator and denominator. Member functions should
accept input from the user in the form 3/5 , and output the fraction’s value in the same
format. Another member function should add two fraction values. Write a main() program
that allows the user to repeatedly input two fractions and then displays their sum. After
each operation, ask whether the user wants to continue.

Exercise 8 in Chapter 4에서 제공된 분수 구조체를 분수 클래스로 변환하세요. 
멤버 데이터는 분자와 분모입니다. 멤버 함수는 사용자로부터 "3/5"와 같은 형식으로 입력을 받아들이고,
동일한 형식으로 분수 값을 출력해야 합니다. 또 다른 멤버 함수는 두 분수 값을 더해야 합니다. 
사용자가 반복적으로 두 분수를 입력하고 그 합계를 표시할 수 있는 'main()' 프로그램을 작성하세요. 
각 작업 후에 사용자에게 계속할 지 여부를 묻습니다.
*/
#include<iostream>

using namespace std;

class addF {
    int num, den;
public:
    void getData();
    void addFraction(addF, addF);
    void display();
};

void addF::getData() {
    char temp;
    cin >> num >> temp >> den;
}

void addF::addFraction(addF f1, addF f2) {
    num = f1.num * f2.den + f1.den * f2.num;
    den = f1.den * f2.den;
}

void addF::display() {
    cout << "두 분수의 합은: " << num << "/" << den << endl;
}

int main() {
    char choice;
    addF f1, f2, f3;
    do {
        cout << "첫번째 분수를 입력하세요(p/q) : ";
        f1.getData();
        cout << "첫번째 분수를 입력하세요(p/q) : ";
        f2.getData();
        f3.addFraction(f1, f2);
        f3.display();
        cout << "계속하시겠습니까?: ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    cout << endl;
    return 0;
}
