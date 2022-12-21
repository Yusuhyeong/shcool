/*************************************************************************************/
/*             HW#4 : Callback ���α׷���  - Ű�����ݹ�(1)                           */
/*  �ۼ��� : ������                              ��¥ : 2020�� 10�� 15��             */
/*                                                                                   */
/* ���� ���� :                                                                       */
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
		//�ݺ������� �����ϰ� �ϴ� �ڵ�
		glutTimerFunc(40, MyTimer, 1);
	}
	if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) {
		//�ݺ� ������ �������� �ʰ� �ϴ� �ڵ�
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