#include<glm/glm.hpp> 
#include<iostream> 
using namespace std;
int main()
{
	glm::mat4 matI = glm::mat4(1.0f); //4*4 단위행렬
	cout << "matrix I : \n";
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			cout << matI[j][i] << " ";
		}
		cout << endl;
	}

	cout << endl;
	glm::vec4 vecB = glm::vec4(1.0f, 2.0f, 3.0f, 1.0f);
	cout << "vector B : \n";
	for (int i = 0;i < 4;i++) {
		cout << vecB[i] << endl;
	}
	cout << endl;
	glm::vec4 vecC = matI * vecB;
	std::cout << "Matrix I * vector B:\n";
	for (int i = 0; i < 4; i++) {
		std::cout << vecC[i] << std::endl;
	}
}
