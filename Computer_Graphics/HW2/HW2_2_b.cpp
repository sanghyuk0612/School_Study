#include <glm/glm.hpp>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

int main() {
    // 4x4 ���� ��� ����
    glm::mat4 trans = glm::mat4(1.0f);
    // x�� �������� �ݽð� ���� 45�� ȸ�� ��ȯ ���
    trans = glm::rotate(trans, glm::radians(45.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    // (1, 2, 0) ��ǥ�� ȸ��
    glm::vec4 point(1.0f, 2.0f, 0.0f, 1.0f);
    glm::vec4 result = trans * point;
    // ��� ���
    printf("Rotated Point: %f, %f, %f \n", result.x, result.y, result.z);

    return 0;
}