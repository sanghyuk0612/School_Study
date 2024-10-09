#include <GL/glut.h>
#include <math.h>
#define M_PI 3.14159265358979323846
#define NUM_SEGMENTS 40// ���� �ٻ��� ���׸�Ʈ ��

// ���� �迭 ����
float colors[6][3] = {
    {1.0f, 0.0f, 0.0f}, // ������
    {0.0f, 1.0f, 0.0f}, // �ʷϻ�
    {0.0f, 0.0f, 1.0f}, // �Ķ���
    {1.0f, 1.0f, 0.0f}, // �����
    {1.0f, 0.0f, 1.0f}, // �����
    {0.0f, 1.0f, 1.0f}  // û�ϻ�
};

void drawShape(int j) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3fv(colors[j]); // ȸ�� �ε����� ���� ���� ����
    glVertex2f(0.0f, 0.0f); // �߽���
    for (int i = 0; i <= NUM_SEGMENTS; i++) {
        float angle = (M_PI / 3) * i / NUM_SEGMENTS; // ���� ���
        float x = cos(angle); // x��ǥ
        float y = sin(angle); // y��ǥ
        glVertex2f(x, y);     // ���� �߰�
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // ����� ����� ������ �������� ä��

    for (int j = 0; j < 6; j++) { // 6�� ȸ���Ͽ� ���� �׸���
        glPushMatrix(); // ���� ��ȯ ��� ����
        glRotatef(j * 60.0f, 0.0f, 0.0f, 1.0f); // z���� �߽����� ȸ��

        // ȸ���� ��ġ�� ������ �׸� ��ġ ����
        drawShape(j); // ������ �ٲ㰡�� ���� �׸���

        glPopMatrix(); // ��ȯ ��� ����
    }

    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // ��� ����: ���
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -1.0, 1.0); // ����Ʈ ����
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Rotating Colored Shapes");

    init(); // �ʱ�ȭ �Լ� ȣ��

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}