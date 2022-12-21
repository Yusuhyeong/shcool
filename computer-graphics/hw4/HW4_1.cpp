/*************************************************************************************/
/*             HW#4 : Callback ���α׷���  - Ű�����ݹ�(1)                           */
/*  �ۼ��� : ������                              ��¥ : 2020�� 10�� 15��             */
/*                                                                                   */
/* ���� ���� : Ű���� ������ ���� ��ǥ�̵��� �ϰ� ������ �̵���Ų��.                 */
/*             Ű���� ������ ���� ������ ���� �ٲ۴�                                 */
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
	switch (key) { // switch�� ���� ��Ȳ�� Ű���� �ݹ� ����
	case 'Q': exit(0); break;
	case 'q': exit(0); break;
	case 27: exit(0); break;
	}
	if (key == 'a') { //����
		gx = gx - 0.1f;
	}
	if (key == 'f') { //������
		gx = gx + 0.1f;
	}
	if (key == 'v') { //��
		gy = gy + 0.1f;
	}
	if (key == 'r') { //�Ʒ�
		gy = gy - 0.1f;
	}
	if (key == 'r') {
		rc = 0.5;
		gc = -0.5;
		bc = -0.5;
	}
	if (key == 'b') { //�Ķ������� ����
		rc = -0.5;
		gc = -0.5;
		bc = 0.5;
	}
	glutPostRedisplay(); // ���� �缳��
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