#include<iostream>
#include<algorithm>
using namespace std;
void seqsearch(int n, const int s[], int x, int& location) {
	location = 0;
	for (int i = 0; i < x; i++) {
		if (s[i] == n) {
			location = i;
			break;
		}
	}

}
int main() {
	
	sort(fdata, fdata + 5);
	//sort(fdata, fdata + 5,greater<double>());
	for (int j = 0; j < 5;j++)
		cout << fdata[j] << ' ';
	cout << endl;
	return 0;
}
