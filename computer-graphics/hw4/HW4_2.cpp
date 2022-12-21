/*************************************************************************************/
/*             HW#4 : Callback 프로그래밍  - 키보드콜백(2)                           */
/*  작성자 : 유수형                              날짜 : 2020년 10월 15일             */
/*                                                                                   */
/* 문제 정의 : 키보드 자판을 통해 좌표이동을 하고 도형을 이동시킨다.                 */
/*             키보드 자판을 통해 도형의 크기를 바꾼다.                              */
/*************************************************************************************/





#include <GL/glut.h>
//도형의 크기와 좌표를 위해 값을 바꾸는 g, l생성
GLfloat gx, gy, lx, ly;
void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	//도형의 좌표및 크기 변경을 위한 vertex설정
	glVertex3f(-0.5 + lx, -0.5 + ly, 0.0);
	glVertex3f(0.5 + gx, -0.5 + ly, 0.0);
	glVertex3f(0.5 + gx, 0.5 + gy, 0.0);
	glVertex3f(-0.5 + lx , 0.5 + gy, 0.0);
	glEnd();
	glFlush();
}
void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'Q': exit(0); break;
	case 'q': exit(0); break;
	case 27: exit(0); break;
	}
	glutPostRedisplay();
}
void MySpecial(int key, int x, int y) {
	switch (key) { // switch문으로 키보드의 자판별 키보드 콜백 이벤트 설정
	case GLUT_KEY_F1:
		break;
	case GLUT_KEY_LEFT: // 왼쪽
		gx = gx - 0.1f;
		lx = lx - 0.1f;
		break;
	case GLUT_KEY_RIGHT: // 오른쪽
		gx = gx + 0.1f;
		lx = lx + 0.1f;
		break;
	case GLUT_KEY_DOWN: // 아래
		gy = gy - 0.1f;
		ly = ly - 0.1f;
		break;
	case GLUT_KEY_UP:   // 위
		gy = gy + 0.1f;
		ly = ly + 0.1f;
		break;
	case GLUT_KEY_PAGE_UP: //크기증가
		gx = gx - 0.1f;
		gy = gy - 0.1f;
		lx = lx + 0.1f;
		ly = ly + 0.1f;
		break;
	case GLUT_KEY_PAGE_DOWN: //크기감소
		gx = gx + 0.1f;
		gy = gy + 0.1f;
		lx = lx - 0.1f;
		ly = ly - 0.1f;
		break;
	default:
		break;
	}
	glutPostRedisplay(); //도형 재설정
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