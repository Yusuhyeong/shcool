/*************************************************************************************/
/*             HW#4 : Callback 프로그래밍  - 키보드콜백(5)                           */
/*  작성자 : 유수형                              날짜 : 2020년 10월 15일             */
/*                                                                                   */
/* 문제 정의 : 움직이는 도형인 상태로 키보드 콜백함수를 통해 좌표를 이동시킨다.      */
/*************************************************************************************/




#include <GL/glut.h>
GLfloat gx, gy;
GLfloat Delta = 0.0;

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.5, 0.8);
	//도형은 계속 움직여야 하므로 이벤트를 통해 움직이는 gx, gy와 주기적으로 증가하는 delta의 값을 넣어준다.
	glVertex3f(-1.0 + Delta + gx, -0.5 + gy, 0.0);
	glVertex3f(0.0 + Delta+gx, -0.5+gy, 0.0);
	glVertex3f(0.0 + Delta+gx, 0.5+gy, 0.0);
	glVertex3f(-1.0 + Delta+gx, 0.5+gy, 0.0);
	glEnd();
	glutSwapBuffers();
}
void MySpecial(int key, int x, int y) {
	switch (key) { //switch문을 통한 키보드 콜백 이벤트 설정
	case GLUT_KEY_F1:
		break;
	case GLUT_KEY_LEFT: //왼쪽
		gx = gx - 0.1f;
		break;
	case GLUT_KEY_RIGHT: //오른쪽
		gx = gx + 0.1f;
		break;
	case GLUT_KEY_DOWN: //아래
		gy = gy - 0.1f;
		break;
	case GLUT_KEY_UP: //위
		gy = gy + 0.1f;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

//delata값을 주기적으로 바꿔주기 위한 함수
void MyIdle() {
	Delta = Delta + 0.001;
	glutPostRedisplay();
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
	glutIdleFunc(MyIdle);
	glutSpecialFunc(MySpecial);
	glutMainLoop();
	return 0;
}