/*************************************************************************************/
/*             HW#4 : Callback 프로그래밍  - 키보드콜백(6)                           */
/*  작성자 : 유수형                              날짜 : 2020년 10월 15일             */
/*                                                                                   */
/* 문제 정의 : 도형의 색을 15가지로 자유롭게 바뀌도록 함.                            */
/*                                                                                   */
/*************************************************************************************/




#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Timer를 위한 Delta값 생성
GLfloat Delta = 0.0; // 0으로 초기화
GLfloat rc = 0;
GLfloat gc = 0;
GLfloat bc = 0;

void MyDisplay() {
	srand(time(NULL));
	rc = 0; // rc에서 나올 수 있는 경우의 수 1개
	gc = rand() % 5; // gc에서 나올 수 있는 경우의 수 5개
	bc = rand() % 3; // bc에서 나올 수 있는 경우의 수 3개
	// rc, gc, bc 모두 0으로 해놨기 때문에 나올 수 있는 색깔의 수는 15개
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(rc, gc/10, bc/10);
	//Timer함수에서 Delta의 값이 0.001씩 오르기 때문에 오른쪽으로 계속 이동한다.
	glVertex3f(-1.0 + Delta, -0.5, 0.0);
	glVertex3f(0.0 + Delta, -0.5, 0.0);
	glVertex3f(0.0 + Delta, 0.5, 0.0);
	glVertex3f(-1.0 + Delta, 0.5, 0.0);
	glEnd();
	glutSwapBuffers();	//도형 재설정
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