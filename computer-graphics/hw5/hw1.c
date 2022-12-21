/******************************************************/
/*             HW#1 : �¾�� �𵨸� Ȯ��              */
/*  �ۼ��� : ������     ��¥ : 2020�� 10�� 28��       */
/*                                                    */
/* ���� ���� : �¾���� ������ �ľ��Ͽ� ���        */
/*             ������ �ݼ��� �������� ǥ���� ���ΰ�   */
/*             �� �����غ��� �̺�Ʈ �߻����� �����ϴ� */
/*             �ֱ⸦ �����Ѵ�.                       */
/******************************************************/


#include <gl/glut.h>

static int Day = 0, Time = 0, Day2 = 0, Day3 = 0;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.1, 0.1, 0.1, 0.1, 0.0, 0.0, 1.0, 1.5, 0.0);  // ��ü ���� �����
    glColor3f(1.0, 0.3, 0.3);
    glutWireSphere(0.13, 20, 16);
    glPushMatrix();
    glRotatef((GLfloat)Day, 0.0, 1.0, 0.0);
    glTranslatef(0.45, 0.0, 0.0);
    glRotatef((GLfloat)Time, 0.0, 1.0, 0.0); //
    glColor3f(0.5, 0.6, 0.7);
    glutWireSphere(0.06, 10, 8);
    glPushMatrix();
    glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
    glTranslatef(0.12, 0.0, 0.0);
    glColor3f(0.9, 0.8, 0.2);
    glutWireSphere(0.015, 10, 8);
    glPopMatrix();
    glPopMatrix();
    glLoadIdentity(); // ���� ��ǥ ���� �ʱ�ȭ
    gluLookAt(0.1, 0.1, 0.1, 0.1, 0.0, 0.0, 1.0, 1.03, 0.0);
    glRotatef((GLfloat)Day2, 0.0, 1.0, 0.0);
    glTranslatef(0.65, 0.0, 0.0); // �¾����κ��� 0.65 ������ �Ÿ��� ��ġ
    glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
    glColor3f(0.9, 0.8, 0.1); // �ݼ��� �� ����
    glutWireSphere(0.05, 10, 8); // �ݼ��� �׷���
    glLoadIdentity();
    gluLookAt(0.1, 0.1, 0.1, 0.1, 0.0, 0.0, 1.0, 1.025, 0.0);
    glRotatef((GLfloat)Day3, 0.0, 1.0, 0.0);
    glTranslatef(0.95, 0.0, 0.0); // �¾����κ��� 0.95 ������ �Ÿ��� ��ġ
    glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 1.0); // ������ �� ����
    glutWireSphere(0.026, 10, 8); // ������ �׷���
    glutSwapBuffers();
}

void MyKeyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'd':
        Day = (Day + 1) % 360;
        glutPostRedisplay();
        Time = (Time + 10) % 360;
        glutPostRedisplay();
        Day2 = (Day2 + 2) % 360;  // �ݼ��� �����ֱ�� 227�� ������ 0.6 ȸ���� 1�� ������ ȸ���� ������
                            // �Ҽ��� ������ ǥ���� �����Ͽ� ���� 1�� ȸ���� 2��ȸ���� ��Ŵ
        glutPostRedisplay();
        Day3 = (Day3 + 4) % 360;  // ������ �����ֱ�� 87�� ������ 1�� ȸ���� 4�� ȸ��
        glutPostRedisplay();

        break;
    default:
        break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Solar System");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(MyDisplay);
    glutKeyboardFunc(MyKeyboard);
    glutMainLoop();
    return 0;
}