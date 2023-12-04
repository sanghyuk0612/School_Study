#include<iostream>
#include<algorithm>
#include<vector>
void print(std::vector<int>::iterator begin,
	std::vector<int>::iterator end) {
	while (begin != end) {
		std::cout << *begin << " ";
		begin++;
	}
	std::cout << std::endl;
}
int main(void) {
	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(7);
	vec.push_back(4);

	std::cout << "Before Sorting" << std::endl;
	print(vec.begin(), vec.end());
	std::sort(vec.begin(), vec.end());

	std::cout << "After Sorting"
		<< std::endl;
	print(vec.begin(), vec.end());
}