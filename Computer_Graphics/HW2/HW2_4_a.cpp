#include <GL/glut.h>
#include <math.h>
#define M_PI 3.14159265358979323846
#define NUM_SEGMENTS 20  // ���� �ٻ��� ���׸�Ʈ ��

void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // ����� ����� ������ �������� ä��

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 0.0f, 0.0f); // �� ����: ������
    glVertex2f(0.0f, 0.0f); // �߽���
    for (int i = 0; i <= NUM_SEGMENTS; i++) {
        float angle = (M_PI/ 3) * i / NUM_SEGMENTS; // ���� ���
        float x = cos(angle); // x��ǥ
        float y = sin(angle); // y��ǥ
        glVertex2f(x, y);     // ���� �߰�
    }
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // ��� ����: ���
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.5, 1.5, -1.5, 1.5, -1.0, 1.0); // ����Ʈ ����
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Circle with GL_TRIANGLE_FAN");

    init(); // �ʱ�ȭ �Լ� ȣ��

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}