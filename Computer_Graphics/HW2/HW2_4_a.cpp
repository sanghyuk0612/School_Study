#include <GL/glut.h>
#include <math.h>
#define M_PI 3.14159265358979323846
#define NUM_SEGMENTS 20  // 원을 근사할 세그먼트 수

void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // 배경을 지우고 설정된 색상으로 채움

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 0.0f, 0.0f); // 선 색상: 빨간색
    glVertex2f(0.0f, 0.0f); // 중심점
    for (int i = 0; i <= NUM_SEGMENTS; i++) {
        float angle = (M_PI/ 3) * i / NUM_SEGMENTS; // 각도 계산
        float x = cos(angle); // x좌표
        float y = sin(angle); // y좌표
        glVertex2f(x, y);     // 정점 추가
    }
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // 배경 색상: 흰색
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.5, 1.5, -1.5, 1.5, -1.0, 1.0); // 뷰포트 설정
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Circle with GL_TRIANGLE_FAN");

    init(); // 초기화 함수 호출

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}