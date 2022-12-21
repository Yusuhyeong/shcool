/*************************************************************************************/
/*             HW#4 : Callback ���α׷���  - Ű�����ݹ�(5)                           */
/*  �ۼ��� : ������                              ��¥ : 2020�� 10�� 15��             */
/*                                                                                   */
/* ���� ���� : �����̴� ������ ���·� Ű���� �ݹ��Լ��� ���� ��ǥ�� �̵���Ų��.      */
/*************************************************************************************/




#include <GL/glut.h>
GLfloat gx, gy;
GLfloat Delta = 0.0;

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.5, 0.8);
	//������ ��� �������� �ϹǷ� �̺�Ʈ�� ���� �����̴� gx, gy�� �ֱ������� �����ϴ� delta�� ���� �־��ش�.
	glVertex3f(-1.0 + Delta + gx, -0.5 + gy, 0.0);
	glVertex3f(0.0 + Delta+gx, -0.5+gy, 0.0);
	glVertex3f(0.0 + Delta+gx, 0.5+gy, 0.0);
	glVertex3f(-1.0 + Delta+gx, 0.5+gy, 0.0);
	glEnd();
	glutSwapBuffers();
}
void MySpecial(int key, int x, int y) {
	switch (key) { //switch���� ���� Ű���� �ݹ� �̺�Ʈ ����
	case GLUT_KEY_F1:
		break;
	case GLUT_KEY_LEFT: //����
		gx = gx - 0.1f;
		break;
	case GLUT_KEY_RIGHT: //������
		gx = gx + 0.1f;
		break;
	case GLUT_KEY_DOWN: //�Ʒ�
		gy = gy - 0.1f;
		break;
	case GLUT_KEY_UP: //��
		gy = gy + 0.1f;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

//delata���� �ֱ������� �ٲ��ֱ� ���� �Լ�
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