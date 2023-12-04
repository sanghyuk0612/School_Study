#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;

int main() {
	
	deque<int> deq;
	deq.push_back(30);
	deq.push_back(10);
	deq.push_front(39);
	deq[2] = 33;
	for (int j = 0; j < deq.size();j++) {
		cout << deq[j] << ' ';
	}
	cout << endl;
	return 0;
}