/*************************************************************************************/
/*             HW#4 : Callback 프로그래밍  - 키보드콜백(1)                           */
/*  작성자 : 유수형                              날짜 : 2020년 10월 15일             */
/*                                                                                   */
/* 문제 정의 : 키보드 자판을 통해 좌표이동을 하고 도형을 이동시킨다.                 */
/*             키보드 자판을 통해 도형의 색을 바꾼다                                 */
/*************************************************************************************/






#include <GL/glut.h>
GLfloat gx, gy;
GLfloat rc = 0;
GLfloat gc = 0;
GLfloat bc = 0;
void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(rc+0.5, gc + 0.5, bc + 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5 + gx, -0.5+gy, 0.0);
	glVertex3f(0.5+gx, -0.5+gy, 0.0);
	glVertex3f(0.5+gx, 0.5+gy, 0.0);
	glVertex3f(-0.5+gx, 0.5+gy, 0.0);
	glEnd();
	glFlush();
}
void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) { // switch를 통해 상황별 키보드 콜백 설정
	case 'Q': exit(0); break;
	case 'q': exit(0); break;
	case 27: exit(0); break;
	}
	if (key == 'a') { //왼쪽
		gx = gx - 0.1f;
	}
	if (key == 'f') { //오른쪽
		gx = gx + 0.1f;
	}
	if (key == 'v') { //위
		gy = gy + 0.1f;
	}
	if (key == 'r') { //아래
		gy = gy - 0.1f;
	}
	if (key == 'r') {
		rc = 0.5;
		gc = -0.5;
		bc = -0.5;
	}
	if (key == 'b') { //파란색으로 변경
		rc = -0.5;
		gc = -0.5;
		bc = 0.5;
	}
	glutPostRedisplay(); // 도형 재설정
}


void MySpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_F1:
		break;
	case GLUT_KEY_LEFT:
		break;
	default:
		break;
	}
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Keyboard Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutSpecialFunc(MySpecial);
	glutMainLoop();
	return 0;
}