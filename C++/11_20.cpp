#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#define MAX 100
int buff[MAX];
class person {
protected:
	char name[80];
	short age;
public:
	void getData() {
		cout << "Enter name: "; cin >> name;
		cout << "Enter age: "; cin >> age;
	}
	void Showdata() {
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
	}
};

int main() {
	//ipers.cpp
	person pers;
	ifstream infile("PERSON.DAT", ios::binary);

	infile.read(reinterpret_cast<char*>(&person)
	//opers.cpp
	person pers;
	pers.getData();
	ofstream outfile("PERSON.DAT", ios::binary);

	outfile.write(reinterpret_cast<char*>(&pers),)




	//이진 데이터 쓰기
	/*for (int j = 0; j < MAX; j++)
		buff[j] = j;

	ofstream os("edata.dat",ios::binary);
	os.write(reinterpret_cast<char*>(buff), MAX * sizeof(int));
	os.close();
	for (int j = 0; j < MAX; j++)
		buff[j] = 0;
	ifstream is("edata.dat", ios::binary);

	is.read(reinterpret_cast<char*>(buff), MAX * sizeof(int));
	for (int j = 0; j < MAX; j++)
		if (buff[j] != j)
		{
			cerr << "Data is incorrect\n"; return 1;
		}
	cout << "Data is correct\n";*/








	//ochar.cpp 
	/*string str = "TIme is a great teacher, but unf" 
		"it kills all its pupils, Belioz" 
		"Incheon National University";
	ofstream outfile("TEST.txt");
	for (int j = 0; j < str.size();j++)
		outfile.put(str[j]);
	cout << "File written\n";*/

	//ichar.cpp 파일
	/*char ch;
	ifstream infile("TEST.TXT");
	while (infile) {
		infile.get(ch);
		cout << ch;
	}
	cout << endl;*/
	//
	/*const int MAX = 10;
	char buffer[MAX];
	ifstream infile("TEST.TXT");
	while (!infile.eof()) {
		infile.getline(buffer, MAX);
		cout << buffer;
	}*/

	//oline 코드
	/*ofstream outfile("TEST.TXT");
	outfile << "I fear thee, acient Marienr!\n";
	outfile << "I fear thy skinny head\n";
	outfile << "And thou art long, and lank, and b\n";
	outfile << "As is the ribbed sea sand.\n";*/


	//파일 저장하는 코드
	/*char ch = 'x';
	int j = 77;
	double d = 6.02;
	string str1 = "Kafka";
	string str2 = "proust";

	ofstream outfile("./dweb/fdata.txt");

	outfile << ch
		<< j
		<< ' '
		<< d
		<<str1
		<< ' '
		<< str2;
	cout << "File written\n";*/
	

	//read 하는 코드
	/*char ch;
	int j;
	double d;
	string str1;
	string str2;
	ifstream infile("./dweb/fdata.txt");
	infile >> ch >> j >> d >> str1 >> str2;
	cout << ch << endl
		<< j << endl
		<< d << endl
		<< str1 << endl
		<< str2 << endl;*/
	return 0;
}