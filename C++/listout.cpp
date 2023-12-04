#include<iostream>
#include<list>
#include<vector>
#include<deque>
#include<set>
#include<string>
using namespace std;

int main() {
	
	
	
	////리버스이터 예제
	//int arr1[] = { 1,3,5,7,9 };
	//int arr2[] = { 2,4,6 };
	//deque<int> d1;
	//deque<int> d2;
	//for (int i = 0;i < 5;i++)
	//	d1.push_back(arr1[i]);
	//for (int j = 0;j < 3;j++)
	//	d2.push_back(arr2[j]);
	//copy(d1.begin(), d1.end(), back_inserter(d2));
	////copy(d1.begin(), d1.end(), front_inserter(d2));
	////copy(d1.begin(), d1.end(), inserter(d2, d2.begin()));

	//cout << "\nd2: ";
	//for (int k = 0; k < d2.size();k++)
	//	cout << d2[k] << ' ';
	//cout << endl;


	//리버스 이터레이터 예제
	/*int arr[] = { 2,4,6,8,10 };
	list<int> theList;
	for (int j = 0; j < 5;j++)
		theList.push_back(arr[j]);
	list<int>::reverse_iterator revit;
	revit = theList.rbegin();
	while (revit != theList.rend())
		cout << *revit++ << ' ';
	cout << endl;*/

	/*//카피예제
	int beginRange, endRange;
	vector<int> v1(arr, arr + 10);
	vector<int> v2(10);
	cout << "Enter range to be copied (example: 2 5): ";
	cin >> beginRange >> endRange;
	vector<int>::iterator iter1 = v1.begin() + beginRange;
	vector<int>::iterator iter2 = v1.begin() + endRange;
	vector<int>::iterator iter3;

	iter3 = copy(iter1, iter2, v2.begin());

	iter1 = v2.begin();
	while (iter1 != iter3)
		cout << *iter1++ << ' ';
	cout << endl;*/
	

	/* //리스트 예제
	list<int> theList;
	for (int k = 0;k < 4;k++) {
		theList.push_back(arr[k]);
	}
	list<int>::iterator iter;
	for (iter = theList.begin();iter != theList.end(); iter++)
		cout << *iter << ' ';
	cout << endl;
	iter = theList.begin();
	while (iter != theList.end())
		cout << *iter++ << ' ';
	cout << endl;*/
	return 0;
}