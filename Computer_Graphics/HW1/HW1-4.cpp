///////////////////////////////////
// square.cpp
//
// OpenGL program to draw a square.
// 
// Sumanta Guha.
///////////////////////////////////

#include <GL/glew.h>
#include <GL/freeglut.h> 

// Drawing routine.
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	//내부 채우기 (폴리곤 채우기)
	glColor3f(0.7,1.0,0.6); // 연두색으로 내부 채우기
	glPolygonMode(GL_BACK ,GL_FILL);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(40.0, 50.0, 0.0); //v0
	glVertex3f(40.0, 40.0, 0.0); //v1
	glVertex3f(10.0, 50.0, 0.0); //v2
	glVertex3f(20.0, 40.0, 0.0); //v3
	glVertex3f(10.0, 10.0, 0.0); //v4
	glVertex3f(20.0, 20.0, 0.0); //v5
	glVertex3f(40.0, 10.0, 0.0); //v6
	glVertex3f(40.0, 20.0, 0.0); //v7
	glVertex3f(50.0, 20.0, 0.0); //v8
	glVertex3f(40.0, 40.0, 0.0); //v9
	glVertex3f(50.0, 40.0, 0.0); //v10

	glVertex3f(40.0, 50.0, 0.0); //v11
	glVertex3f(70.0, 40.0, 0.0); //v12
	glVertex3f(80.0, 50.0, 0.0); //v13
	glVertex3f(70.0, 20.0, 0.0); //v14
	glVertex3f(80.0, 10.0, 0.0); //v15

	glVertex3f(50.0, 20.0, 0.0); //v16
	glVertex3f(40.0, 10.0, 0.0); //v17
	glEnd();

	//선 그리기
	glColor3f(0.0, 0.0, 0.0);
	glPolygonMode(GL_BACK, GL_LINE);
	// Draw a polygon with specified vertices.
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(40.0, 50.0, 0.0); //v0
	glVertex3f(40.0, 40.0, 0.0); //v1
	glVertex3f(10.0, 50.0, 0.0); //v2
	glVertex3f(20.0, 40.0, 0.0); //v3
	glVertex3f(10.0, 10.0, 0.0); //v4
	glVertex3f(20.0, 20.0, 0.0); //v5
	glVertex3f(40.0, 10.0, 0.0); //v6
	glVertex3f(40.0, 20.0, 0.0); //v7
	glVertex3f(50.0, 20.0, 0.0); //v8
	glVertex3f(40.0, 40.0, 0.0); //v9
	glVertex3f(50.0, 40.0, 0.0); //v10

	glVertex3f(40.0, 50.0, 0.0); //v11
	glVertex3f(70.0, 40.0, 0.0); //v12
	glVertex3f(80.0, 50.0, 0.0); //v13
	glVertex3f(70.0, 20.0, 0.0); //v14
	glVertex3f(80.0, 10.0, 0.0); //v15

	glVertex3f(50.0, 20.0, 0.0); //v16
	glVertex3f(40.0, 10.0, 0.0); //v17

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
	glOrtho(0.0, 90.0, 0.0, 80.0, -1.0, 1.0);
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
int main(int argc, char **argv)
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