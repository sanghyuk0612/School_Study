#include <glm/glm.hpp>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

int main() {
    // 4x4 단위 행렬 생성
    glm::mat4 trans = glm::mat4(1.0f);
    // x축 기준으로 반시계 방향 45도 회전 변환 행렬
    trans = glm::rotate(trans, glm::radians(45.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    // (1, 2, 0) 좌표를 회전
    glm::vec4 point(1.0f, 2.0f, 0.0f, 1.0f);
    glm::vec4 result = trans * point;
    // 결과 출력
    printf("Rotated Point: %f, %f, %f \n", result.x, result.y, result.z);

    return 0;
}