///////////////////////////////////
// square.cpp
//
// OpenGL program to draw a square.
// 
// Sumanta Guha.
///////////////////////////////////

#include <GL/glew.h>
#include <GL/freeglut.h> 
#include <cmath>
// Drawing routine.
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);


	// ���� ����
	glColor3f(0.7, 1.0, 0.6);

	// �ٰ����� �ﰢ�� ������ �׸��� ����
	glBegin(GL_TRIANGLE_FAN);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//glVertex2f(cx, cy);  // �߽���
		// �����̰��� �׸���
	float radius = 30.0f;  // ������
	float cx = 50.0f, cy = 50.0f;  // �߽� ��ǥ
	float PI = 3.141592;
	for (int i = 0; i < 12; i++) {
		float angle = 2.0f * PI * i / 12;
		float x = cx + radius * cos(angle);
		float y = cy + radius * sin(angle);
		glVertex2f(x, y);
	}
	glEnd();

	// ���� �ﰢ���� ������ �׸���
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	// ù��° ������ �� ���������� �׸�
	for (int i = 2; i < 11; i++) {
		float angle = 2.0f * PI * i / 12;
		float x = cx + radius * cos(angle);
		float y = cy + radius * sin(angle);

		// �߽ɿ��� �������� �׸��� ��
		glVertex2f(cx+radius*cos(0), cy+radius*sin(0));  // �߽�
		glVertex2f(x, y);    // ����
	}

	glEnd();
	glFlush();
}

// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
	//glFrustum(0.0, 100.0, 0.0, 100.0, 5.0, 50.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

// Main routine.
int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("square.cpp");

	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}