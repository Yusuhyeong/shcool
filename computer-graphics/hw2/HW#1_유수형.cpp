#include <GL/glut.h>

/*
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);
	glPointSize(3.0);
	glBegin(GL_POINTS);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush();
}
*/
//GL_POINTS

/*
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);
	glPointSize(3.0);
	glBegin(GL_LINES);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.5, -0.5);
	glEnd();
	glFlush();
}
*/ //GL_LINES

/*
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);
	glPointSize(3.0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush();
}
*/ //GL_LINE_STRIP

/*
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);
	glPointSize(3.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush();
}
*/ //GL_LINE_LOOP



/*
void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLES);
	GLfloat x = -0.8;
	GLfloat y = 0.4;
	for (int i = 0; i < 6; i++) {
		glVertex2f(x, y);
		x += 0.3;
		y *= -1;
	}
	glEnd();
	glFlush();
}
*/ //GL_TRIANGLES



/*
void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLE_STRIP);
	GLfloat x = -0.8;
	GLfloat y = 0.4;
	for (int i = 0; i < 6; i++) {
		if (i % 2 == 0) {
			glColor3f(1.0, 0, 0);
		}
		else {
			glColor3f(1.0, 0, 0);
		}
		glVertex2f(x, y);
		x += 0.3;
		y *= -1;
	}
	glEnd();
	glFlush();
}
*/ //GL_TRIANGLE_STRIP

/*
void MyDisplay()

{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.35, 0.35);

	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-0.5, 0.0);

	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-0.35, -0.35);

	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(0.0, -0.5);
	glEnd();
	glFlush();
}
*/ // GL_TRIANGLE_FAN

/*
void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.5, 0.0);
	glVertex2f(0.0, -0.5);
	glVertex2f(0.5, 0.0);
	glEnd();
	glFlush();

}
*/ //GL_QUADS

/*
void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUAD_STRIP);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.5, 0.0);
	glVertex2f(0.0, -0.5);
	glVertex2f(0.5, 0.0);
	glVertex2f(1.0, 0.5);
	glVertex2f(0.5, 0.0);
	glVertex2f(1.0, -0.5);
	glVertex2f(1.5, 0.0);
	glEnd();
	glFlush();

}
*/ // GL_QUAD_STRIP

/*
void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.5, 0.0);
	glVertex2f(0.5, 0.0);
	glVertex2f(0.0, -0.5);
	glEnd();
	glFlush();
}
*/ //GL_POLYGON


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(300, 300);
	glutCreateWindow("Graphics Primitvies");
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}