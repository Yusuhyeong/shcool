/*************************************************************************************/
/*             HW#4 : Callback ���α׷���  - Ű�����ݹ�(6)                           */
/*  �ۼ��� : ������                              ��¥ : 2020�� 10�� 15��             */
/*                                                                                   */
/* ���� ���� : ������ ���� 15������ �����Ӱ� �ٲ�� ��.                            */
/*                                                                                   */
/*************************************************************************************/




#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Timer�� ���� Delta�� ����
GLfloat Delta = 0.0; // 0���� �ʱ�ȭ
GLfloat rc = 0;
GLfloat gc = 0;
GLfloat bc = 0;

void MyDisplay() {
	srand(time(NULL));
	rc = 0; // rc���� ���� �� �ִ� ����� �� 1��
	gc = rand() % 5; // gc���� ���� �� �ִ� ����� �� 5��
	bc = rand() % 3; // bc���� ���� �� �ִ� ����� �� 3��
	// rc, gc, bc ��� 0���� �س��� ������ ���� �� �ִ� ������ ���� 15��
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(rc, gc/10, bc/10);
	//Timer�Լ����� Delta�� ���� 0.001�� ������ ������ ���������� ��� �̵��Ѵ�.
	glVertex3f(-1.0 + Delta, -0.5, 0.0);
	glVertex3f(0.0 + Delta, -0.5, 0.0);
	glVertex3f(0.0 + Delta, 0.5, 0.0);
	glVertex3f(-1.0 + Delta, 0.5, 0.0);
	glEnd();
	glutSwapBuffers();	//���� �缳��
}
void MyTimer(int Value) {
	Delta = Delta + 0.001;
	glutPostRedisplay();
	glutTimerFunc(40, MyTimer, 1);
}
void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Idle Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutTimerFunc(40, MyTimer, 1);
	glutMainLoop();
	return 0;
}