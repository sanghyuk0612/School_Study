#include <GL/glut.h>
#include <math.h>
#define M_PI 3.14159265358979323846
#define NUM_SEGMENTS 40// 원을 근사할 세그먼트 수

// 색상 배열 정의
float colors[6][3] = {
    {1.0f, 0.0f, 0.0f}, // 빨간색
    {0.0f, 1.0f, 0.0f}, // 초록색
    {0.0f, 0.0f, 1.0f}, // 파란색
    {1.0f, 1.0f, 0.0f}, // 노란색
    {1.0f, 0.0f, 1.0f}, // 보라색
    {0.0f, 1.0f, 1.0f}  // 청록색
};

void drawShape(int j) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3fv(colors[j]); // 회전 인덱스에 따라 색상 설정
    glVertex2f(0.0f, 0.0f); // 중심점
    for (int i = 0; i <= NUM_SEGMENTS; i++) {
        float angle = (M_PI / 3) * i / NUM_SEGMENTS; // 각도 계산
        float x = cos(angle); // x좌표
        float y = sin(angle); // y좌표
        glVertex2f(x, y);     // 정점 추가
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // 배경을 지우고 설정된 색상으로 채움

    for (int j = 0; j < 6; j++) { // 6번 회전하여 도형 그리기
        glPushMatrix(); // 현재 변환 행렬 저장
        glRotatef(j * 60.0f, 0.0f, 0.0f, 1.0f); // z축을 중심으로 회전

        // 회전된 위치에 도형을 그릴 위치 설정
        drawShape(j); // 색상을 바꿔가며 도형 그리기

        glPopMatrix(); // 변환 행렬 복원
    }

    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // 배경 색상: 흰색
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -1.0, 1.0); // 뷰포트 설정
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Rotating Colored Shapes");

    init(); // 초기화 함수 호출

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}