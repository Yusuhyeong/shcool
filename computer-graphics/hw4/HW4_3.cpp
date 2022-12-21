/*************************************************************************************/
/*             HW#4 : Callback 프로그래밍  - 키보드콜백(1)                           */
/*  작성자 : 유수형                              날짜 : 2020년 10월 15일             */
/*                                                                                   */
/* 문제 정의 :                                                                       */
/*                                                                                   */
/*************************************************************************************/





#include <GL/glut.h>
GLfloat Delta = 0.0;
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-1.0 + Delta, -0.5, 0.0);
	glVertex3f(0.0 + Delta, -0.5, 0.0);
	glVertex3f(0.0 + Delta, 0.5, 0.0);
	glVertex3f(-1.0 + Delta, 0.5, 0.0);
	glEnd();
	glutSwapBuffers();
}

void MyTimer(int Value) {
	Delta = Delta + 0.01;
	glutPostRedisplay();

	if(glutMouseFunc(MyMouseClick) == GLUT_LEFT_BUTTON)
		glutTimerFunc(40, MyTimer, 1);
}


void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if(Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
		//반복조건을 만족하게 하는 코드
		glutTimerFunc(40, MyTimer, 1);
	}
	if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) {
		//반복 조건을 만족하지 않게 하는 코드
	}
}

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Mouse Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutMouseFunc(MyMouseClick);
	glutMainLoop();
	return 0;
}