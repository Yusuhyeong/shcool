/******************************************************/
/*             HW#4 : gluLookAt()�� �ǽð� ����       */
/*  �ۼ��� : ������     ��¥ : 2020�� 10�� 28��       */
/*                                                    */
/* ���� ���� : �̺�Ʈ �߻��� ���� ������ȭ��          */
/*             ��� ǥ���� ���ΰ� �����غ��ƾ� �Ѵ� */
/*             camera�� Focus�� �ü����̴� ��� �ٸ�*/
/*             �� ������ ����.                        */
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
	if (Delta < 0.7) // ���� ������ ������ ����� �ʰ� �ϱ� ���� ����
		Delta = Delta + 0.01;
	else ok = false;
	glutPostRedisplay();

	if (ok = true) 
		glutTimerFunc(40, MyTimer, 1);
}


void MyKeyboard(unsigned char key, int x, int y) { //Ű���� �̺�Ʈ �߻� ���� ����
	switch (key) {
	case 'a': //a�� ������ x�� ��ǥ 0.1 ����(focus)
		atx = (atx + 0.1);
		break;
	case 'A':
		atx = (atx + 0.1);
		break;
	case 'f': //f�� ������ x�� ��ǥ 0.1 ����(focus)
		atx = (atx - 0.1);
		break;
	case 'F':
		atx = (atx - 0.1);
		break;
	case 'r': //r�� ������ y�� ��ǥ 0.1 ����(focus)
		aty = (aty + 0.1);
		break;
	case 'R':
		aty = (aty + 0.1);
		break;
	case 'v': //v�� ������ y�� ��ǥ 0.1 ����(focus)
		aty = (aty - 0.1);
		break;
	case 'V':
		aty = (aty - 0.1);
		break;
	case 'z': //z�� ������ z�� ��ǥ 0.1 ����(focus)
		atz = (atz + 0.1);
		break;
	case 'Z':
		atz = (atz + 0.1);
		break;
	case 't': //t�� ������ z�� ��ǥ 0.1 ����(focus)
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
	case GLUT_KEY_LEFT:     //���� Ű
		eyex = eyex - 0.1;  //ī�޶� �ü� �ٲٱ�
		break;
	case GLUT_KEY_RIGHT:     //������ Ű
		eyex = eyex + 0.1;   //ī�޶� �ü� �ٲٱ�
		break;
	case GLUT_KEY_UP:      //�� Ű
		eyey = eyey + 0.1; //ī�޶� �ü� �ٲٱ�
		break;
	case GLUT_KEY_DOWN:      //�Ʒ� Ű
		eyey = eyey - 0.1;   //ī�޶� �ü� �ٲٱ�
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