/******************************************************/
/*             HW#4 : gluLookAt()의 실시간 제어       */
/*  작성자 : 유수형     날짜 : 2020년 10월 28일       */
/*                                                    */
/* 문제 정의 : 이벤트 발생에 따른 시점변화를          */
/*             어떻게 표현할 것인가 생각해보아야 한다 */
/*             camera와 Focus의 시선차이는 어떻게 다른*/
/*             지 생각해 본다.                        */
/******************************************************/

#include <gl/glut.h>
#include <stdbool.h>

bool ok;
static float atx = 0, aty = 0, atz = 0, eyex = 0, eyey = 0, eyez = 0;
float Delta = 0.0;

void DrawGround() {
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(-2.0, -0.71, 2.0);
	glVertex3f(2.0, -0.71, 2.0);
	glVertex3f(2.0, -0.71, -2.0);
	glVertex3f(-2.0, -0.71, -2.0);
	glEnd();
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_LINES);
	for (float x = -2.0; x <= 2.2; x += 0.2) {
		glVertex3f(x, -0.7, -2.0);
		glVertex3f(x, -0.7, 2.0);
	}
	for (float z = -2.0; z <= 2.2; z += 0.2) {
		glVertex3f(-2.0, -0.7, z);
		glVertex3f(2.0, -0.7, z);
	}
	glEnd();
}
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0+ eyex, 3.5+eyey, 3.5+eyez, 0.0+atx, 0.0+aty, 0.0+atz, 0.0, 1.0, 0.0);
	//gluLookAt(-1.0, 0.5, 3.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawGround();
	glColor3f(1.0, 1.0, 0.0);
	glutWireTeapot(1.0);
	glFlush();
}

void MyTimer(int value) {
	if (Delta < 0.7) // 모델이 윈도우 영역을 벗어나지 않게 하기 위한 조건
		Delta = Delta + 0.01;
	else ok = false;
	glutPostRedisplay();

	if (ok = true) 
		glutTimerFunc(40, MyTimer, 1);
}


void MyKeyboard(unsigned char key, int x, int y) { //키보드 이벤트 발생 조건 생성
	switch (key) {
	case 'a': //a를 누르면 x축 좌표 0.1 증가(focus)
		atx = (atx + 0.1);
		break;
	case 'A':
		atx = (atx + 0.1);
		break;
	case 'f': //f를 누르면 x축 좌표 0.1 감소(focus)
		atx = (atx - 0.1);
		break;
	case 'F':
		atx = (atx - 0.1);
		break;
	case 'r': //r를 누르면 y축 좌표 0.1 증가(focus)
		aty = (aty + 0.1);
		break;
	case 'R':
		aty = (aty + 0.1);
		break;
	case 'v': //v를 누르면 y축 좌표 0.1 감소(focus)
		aty = (aty - 0.1);
		break;
	case 'V':
		aty = (aty - 0.1);
		break;
	case 'z': //z를 누르면 z축 좌표 0.1 증가(focus)
		atz = (atz + 0.1);
		break;
	case 'Z':
		atz = (atz + 0.1);
		break;
	case 't': //t를 누르면 z축 좌표 0.1 감소(focus)
		atz = (atz - 0.1);
		break;
	case 'T':
		atz = (atz - 0.1);
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
void MySpecialKey(int Key, int X, int Y)
{
	switch (Key) {
	case GLUT_KEY_LEFT:     //왼쪽 키
		eyex = eyex - 0.1;  //카메라 시선 바꾸기
		break;
	case GLUT_KEY_RIGHT:     //오른쪽 키
		eyex = eyex + 0.1;   //카메라 시선 바꾸기
		break;
	case GLUT_KEY_UP:      //위 키
		eyey = eyey + 0.1; //카메라 시선 바꾸기
		break;
	case GLUT_KEY_DOWN:      //아래 키
		eyey = eyey - 0.1;   //카메라 시선 바꾸기
		break;
	}
	glutPostRedisplay();
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLsizei)w / (GLsizei)h, 0.0, 100);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("VCS (View Coordinate System)");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutKeyboardFunc(MyKeyboard);
	glutSpecialFunc(MySpecialKey);
	glutMainLoop();
	return 0;
}