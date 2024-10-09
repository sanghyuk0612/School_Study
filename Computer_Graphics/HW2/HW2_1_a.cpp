#include<glm/glm.hpp> 
#include<iostream> 
using namespace std;
int main()
{
	glm::mat4 matA = glm::mat4(1.0f); //4*4 단위행렬
	matA[3][2] = -10.0;               //-10을 넣어줌
	cout << "matrix A : \n";
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			cout << matA[j][i] << " ";
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
	glm::vec4 vecC = matA * vecB;
	std::cout << "Matrix A * vector B:\n";
	for (int i = 0; i < 4; i++) {
		std::cout << vecC[i] << std::endl;
	}
}