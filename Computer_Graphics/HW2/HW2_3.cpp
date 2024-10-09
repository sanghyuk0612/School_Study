#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <fstream>
#include <cmath>
#include <glm/glm.hpp>       // GLM 기본 헤더
#include <glm/gtc/matrix_transform.hpp>  // 변환 함수 헤더
#include <glm/gtc/type_ptr.hpp>   // 행렬 포인터 함수 헤더

// 각도를 라디안으로 변환하는 함수
float toRadians(float degrees) {
    return degrees * 3.14159265f / 180.0f;
}

// 특정 각도에서 변환 행렬을 적용하여 공룡을 그리는 함수
void drawTransformedDino(const char* fileName, float angle, float distance) {
    std::ifstream inStream;
    inStream.open(fileName);    // open the file
    if (inStream.fail())
        return;

    GLint numpolys, numLines, x, y;
    inStream >> numpolys;       // read the number of polylines

    // 기본 단위 행렬 생성
    glm::mat4 transform = glm::mat4(1.0f);

    // 변환 적용
    transform = glm::translate(transform, glm::vec3(400.0f, 400.0f, 0.0f)); // 화면 중심 이동
    transform = glm::rotate(transform, toRadians(angle), glm::vec3(0.0f, 0.0f, 1.0f)); // 회전
    transform = glm::translate(transform, glm::vec3(-20.0f, distance, 0.0f)); // 공룡 위치 이동
    transform = glm::scale(transform, glm::vec3(0.1f, 0.1f, 1.0f)); // 크기 조정

    // 변환된 행렬을 OpenGL에 전달
    glPushMatrix();
    glMultMatrixf(glm::value_ptr(transform));

    // 공룡 그리기
    for (int j = 0; j < numpolys; j++)  // read each polyline
    {
        inStream >> numLines;
        glBegin(GL_LINE_STRIP);	     // draw the next polyline
        for (int i = 0; i < numLines; i++)
        {
            inStream >> x >> y;        // read the next x, y pair
            glVertex2i(x, y);
        }
        glEnd();
    }

    glPopMatrix(); // 원래 변환 상태로 복원
    glFlush();
    inStream.close();
}

//--------------- setWindow ---------------------
void setWindow(float left, float right, int bottom, int top)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(left, right, bottom, top);
}

void render() {
    glClear(GL_COLOR_BUFFER_BIT);
    setWindow(250, 550.0, 250, 550.0);    // set a fixed window
    glViewport(0, 0, 800, 800);

    int numDinos = 12; // 공룡의 개수
    float angleStep = 360.0f / numDinos; // 공룡 간 각도 차이
    float distance = 100.0f; // 공룡 발 위치에서의 거리

    for (int i = 0; i < numDinos; i++) {
        float angle = i * angleStep; // 각 공룡의 각도 계산
        drawTransformedDino("dino.dat", angle, distance);
    }

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Transformed Dino with GLM");
    glutDisplayFunc(render);
    glutMainLoop();
    return(0);
}
