/*************************************************************************************/
/*             HW#4 : Callback 프로그래밍  - 키보드콜백(1)                           */
/*  작성자 : 유수형                              날짜 : 2020년 10월 15일             */
/*                                                                                   */
/* 문제 정의 :                                                                       */
/*                                                                                   */
/*************************************************************************************/




#include <GL/glut.h>
GLboolean IsSphere = true;
GLboolean IsSmall = true;
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.5, 0.5);
	if ((IsSphere) && (IsSmall))
		glutWireSphere(0.5, 30, 30);
	else if ((IsSphere) && (!IsSmall))
		glutWireSphere(0.7, 30, 30);
	else if ((!IsSphere) && (IsSmall))
		glutWireTorus(0.1, 0.3, 40, 20);
	else glutWireTorus(0.2, 0.5, 40, 20);
	glFlush();
}
void MyMainMenu(int entryID) {
	if (entryID == 1)IsSphere = true;
	else if (entryID == 2) IsSphere = false;
	else if (entryID == 3) exit(0);
	glutPostRedisplay();
}
void MySizeMenu(int entryID) {
	if (entryID == 1)IsSmall = true;
	else if (entryID == 2)IsSmall = false;
	glutPostRedisplay();
}
void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	GLint MySizeID = glutCreateMenu(MySizeMenu);
	glutAddMenuEntry("Small", 1);
	glutAddMenuEntry("Large", 2);
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddSubMenu("Draw Sphere", MySizeID);
	glutAddSubMenu("Draw Torus", MySizeID);
	glutAddSubMenu("Size", MySizeID);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	GLint MySizeID_2 = glutCreateMenu(MySizeMenu);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);
	GLint MyMainMenuID_2 = glutCreateMenu(MyMainMenu);
	glutAddSubMenu("Change Color", MySizeID);
	glutAddMenuEntry("Exit", 3);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Menu Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}