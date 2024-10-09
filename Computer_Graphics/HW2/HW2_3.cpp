#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <fstream>
#include <cmath>
#include <glm/glm.hpp>       // GLM �⺻ ���
#include <glm/gtc/matrix_transform.hpp>  // ��ȯ �Լ� ���
#include <glm/gtc/type_ptr.hpp>   // ��� ������ �Լ� ���

// ������ �������� ��ȯ�ϴ� �Լ�
float toRadians(float degrees) {
    return degrees * 3.14159265f / 180.0f;
}

// Ư�� �������� ��ȯ ����� �����Ͽ� ������ �׸��� �Լ�
void drawTransformedDino(const char* fileName, float angle, float distance) {
    std::ifstream inStream;
    inStream.open(fileName);    // open the file
    if (inStream.fail())
        return;

    GLint numpolys, numLines, x, y;
    inStream >> numpolys;       // read the number of polylines

    // �⺻ ���� ��� ����
    glm::mat4 transform = glm::mat4(1.0f);

    // ��ȯ ����
    transform = glm::translate(transform, glm::vec3(400.0f, 400.0f, 0.0f)); // ȭ�� �߽� �̵�
    transform = glm::rotate(transform, toRadians(angle), glm::vec3(0.0f, 0.0f, 1.0f)); // ȸ��
    transform = glm::translate(transform, glm::vec3(-20.0f, distance, 0.0f)); // ���� ��ġ �̵�
    transform = glm::scale(transform, glm::vec3(0.1f, 0.1f, 1.0f)); // ũ�� ����

    // ��ȯ�� ����� OpenGL�� ����
    glPushMatrix();
    glMultMatrixf(glm::value_ptr(transform));

    // ���� �׸���
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

    glPopMatrix(); // ���� ��ȯ ���·� ����
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

    int numDinos = 12; // ������ ����
    float angleStep = 360.0f / numDinos; // ���� �� ���� ����
    float distance = 100.0f; // ���� �� ��ġ������ �Ÿ�

    for (int i = 0; i < numDinos; i++) {
        float angle = i * angleStep; // �� ������ ���� ���
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
