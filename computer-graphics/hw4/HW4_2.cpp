/*************************************************************************************/
/*             HW#4 : Callback ���α׷���  - Ű�����ݹ�(2)                           */
/*  �ۼ��� : ������                              ��¥ : 2020�� 10�� 15��             */
/*                                                                                   */
/* ���� ���� : Ű���� ������ ���� ��ǥ�̵��� �ϰ� ������ �̵���Ų��.                 */
/*             Ű���� ������ ���� ������ ũ�⸦ �ٲ۴�.                              */
/*************************************************************************************/





#include <GL/glut.h>
//������ ũ��� ��ǥ�� ���� ���� �ٲٴ� g, l����
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
	//������ ��ǥ�� ũ�� ������ ���� vertex����
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
	switch (key) { // switch������ Ű������ ���Ǻ� Ű���� �ݹ� �̺�Ʈ ����
	case GLUT_KEY_F1:
		break;
	case GLUT_KEY_LEFT: // ����
		gx = gx - 0.1f;
		lx = lx - 0.1f;
		break;
	case GLUT_KEY_RIGHT: // ������
		gx = gx + 0.1f;
		lx = lx + 0.1f;
		break;
	case GLUT_KEY_DOWN: // �Ʒ�
		gy = gy - 0.1f;
		ly = ly - 0.1f;
		break;
	case GLUT_KEY_UP:   // ��
		gy = gy + 0.1f;
		ly = ly + 0.1f;
		break;
	case GLUT_KEY_PAGE_UP: //ũ������
		gx = gx - 0.1f;
		gy = gy - 0.1f;
		lx = lx + 0.1f;
		ly = ly + 0.1f;
		break;
	case GLUT_KEY_PAGE_DOWN: //ũ�Ⱘ��
		gx = gx + 0.1f;
		gy = gy + 0.1f;
		lx = lx - 0.1f;
		ly = ly - 0.1f;
		break;
	default:
		break;
	}
	glutPostRedisplay(); //���� �缳��
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