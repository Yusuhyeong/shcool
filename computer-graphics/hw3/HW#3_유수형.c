/***********************************************************************************/
/*                           HW#3 : 3D ������ ���α׷�                             */
/*  �ۼ��� : ������                              ��¥ : 2020�� 10�� 7��            */
/*                                                                                 */
/* ���� ���� :  viewport�� ���� 3D tetrahedron Gasket ����                         */
/*              viewport�� ���� ������ ��� ���� ���Ǹ� ����Ͽ�                   */
/*              ������ ������ ��ǥ�� �ʱ�ȭ �� �缳���� ���� �����Ѵ�              */
/*                                                                                 */
/***********************************************************************************/


#include<stdlib.h> // rand() �Լ� ��� �뵵
#include<GL/glut.h>

GLfloat v[4][3] = { {0.0,0.0,1.0}, {0.0,1.0,0.0}, {-1.0,-0.5,0.0}, {1.0,-0.5,0.0} }; // ������ �ʱ� ������ ��ǥ ����
GLfloat colors[4][3] = { {1.0,0.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{0.0,0.0,0.0} }; // ������ ��ǥ�� �̷������ ���� ���� ����
int n = 2; //���ҵǴ� Ƚ��

void triangle(GLfloat* va, GLfloat* vb, GLfloat* vc) // �ﰢ�� ��ǥ�� �����ϴ� �Լ�
{
    glVertex3fv(va);
    glVertex3fv(vb);
    glVertex3fv(vc);
}

void tetra(GLfloat* a, GLfloat* b, GLfloat* c, GLfloat* d) // ���������� ����� ���� ���� ����(��� ���� �������� ����)
{
    glColor3fv(colors[0]);
    triangle(a, b, c);
    glColor3fv(colors[1]);
    triangle(a, c, d);
    glColor3fv(colors[2]);
    triangle(a, d, b);
    glColor3fv(colors[3]);
    triangle(b, d, c);
}

void divide_tetra(GLfloat* a, GLfloat* b, GLfloat* c, GLfloat* d, int m) // �ﰢ�� ����
{
    GLfloat mid[6][3];
    int j;
    if (m > 0) // �����ü�� �� �������� �̾����� �𼭸��� �߾Ӱ��� ������.
               // ���� for���� 6�� �ݺ��Ͽ� �� �������� �̾����� �𼭸��� �߾Ӱ��� ����ϰ�
    {
        for (j = 0; j < 3; j++)
        {
            mid[0][j] = (a[j] + b[j]) / 2;
            mid[1][j] = (a[j] + c[j]) / 2;
            mid[2][j] = (a[j] + d[j]) / 2;
            mid[3][j] = (b[j] + c[j]) / 2;
            mid[4][j] = (c[j] + d[j]) / 2;
            mid[5][j] = (b[j] + d[j]) / 2;
        }
        divide_tetra(a, mid[0], mid[1], mid[2], m - 1); // �̷��� for���� m�� �ݺ��ϰ� �ȴ�.
        divide_tetra(mid[0], b, mid[3], mid[5], m - 1);
        divide_tetra(mid[1], mid[3], c, mid[4], m - 1);
        divide_tetra(mid[2], mid[5], mid[4], d, m - 1);
    }
    else // m�� 0���� �۰ԵǸ� tetra�Լ��� ���� ����� ���ҵ� �����ü�� �����Ѵ�.
        tetra(a, b, c, d);
}

void Mydisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_TRIANGLES); // ù �ﰢ�� �� ���� �׸���.
    divide_tetra(v[0], v[1], v[2], v[3], n); // �ʱ⼳���� ��ǥ�� n = 2��� ������ �����ü�� �����Ѵ�.
    glEnd();
    glFlush();
}

void myReshape(int NewWidth, int NewHeight)
{
    glViewport(0, 0, NewWidth, NewHeight); 	// �̺�Ʈ�� ���� �� ��Ʈ�� ���Ӱ� ���� ���ο� ���α��̷� ����.
    glMatrixMode(GL_PROJECTION); // GL_PROJECTION���� ����
    glLoadIdentity(); // ������ȯ
    glOrtho(-2.0, 2.0, -2.0, 2.0, -10.0, 10.0); // �� �� ��� ����
    glMatrixMode(GL_MODELVIEW);	// ���� �𵨺� ����� �׵���ķ� �ʱ�ȭ
    glutPostRedisplay(); // �ʱ�ȭ, �缳������ �̷���� ��ǥ�� �ٽ� ����
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D tetrahedron Gasket");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(Mydisplay);
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutMainLoop();

    return 0;
}