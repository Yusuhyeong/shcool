#include <gl/glut.h>
#include <math.h>

// ������ ���带 ���� ��ũ�� ���
#define DAY true
#define NIGHT false

// mouse movement ��Ƴ��� ������. �ʱⰪ�� ������ ���̵��� ����.
int ViewX = 300, ViewY = 300;

// �ִϸ��̼��� �����ϱ� ���� �ʿ��� �ð� ����. (��, ���� �����϶� ���)
static double time = 0;

// �ʱ⼼���� ����� ����. (false)
bool day_or_night = NIGHT;

// ����, �ȴٸ�, �޻��� ǥ���� �� �ʿ��� �Ǹ��� ������ ����.
GLUquadricObj* cyl;

// ====== �Լ����� ======

// �׸��� �Լ�
void draw_sunlight(); // �޻� �׸���
void draw_sun(); // �� �׸���
void draw_human(); // ��� �׸���

// ��Ÿ �Լ�
void init_light(); // ���� �ʱ�ȭ �Լ�
void timer(int value); // Ÿ�̸� �Լ�
void mouse_callback(GLint X, GLint Y); // ���콺 �ݹ��Լ�
void keyboard_callback(unsigned char key, int x, int y); // Ű���� �ݹ��Լ�
void display(); // ���÷��� �Լ�
void reshape(int w, int h); // ������ �ݹ��Լ�
void menu(int id); // �޴� �Լ�
void create_menu(); // �޴����� �Լ�

// =======================


// ���� �ʱ�ȭ �Լ�
void init_light() {
    GLfloat mat_diffuse[] = { 0.5, 0.4, 0.3, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };

    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat light_ambient[] = { 0.3, 0.3, 0.3, 1.0 };
    GLfloat light_position[] = { -3, 6, 3.0, 0.0 };

    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // �� �ڵ�� ���� ������ ������ �� �ֵ��� ��.
    glEnable(GL_COLOR_MATERIAL);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

// ���÷��� �Լ�
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // gluLookAt �Լ� ���� �� centerX�� centerY�� �̿���
    // ViewX, ViewY �� �� ���콺 �巡�׿� ���� ������ȯ ����.
    gluLookAt(0.0, 0.0, 0.0, ViewX * 0.05 - 15.0, 15.0 - ViewY * 0.05, -1.0, 0.0, 1.0, 0.0);

    // ����� �켱 �׸���
    draw_human();

    // ������� ��� �� ����� �� ���, ������ ��� �� �� ��Ӱ� ����.
    // ���� ������� ��� �ظ� �߰��� �𵨸�.
    if (day_or_night == DAY) {
        glClearColor(0.9, 0.6, 0.3, 0.5);
        draw_sun();
    }
    else glClearColor(0.1, 0.2, 0.4, 0.5);

    glFlush();
}

// �޻� �׸��� �Լ�
void draw_sunlight() {
    // �޻� 1
    glPushMatrix();
    cyl = gluNewQuadric();
    glTranslatef(0.54, 0.97, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(-110.0, 0.0, 1.0, 0.0);
    gluCylinder(cyl, 0.02, 0.01, 0.1, 20, 20);
    glPopMatrix();

    // �޻� 2
    glPushMatrix();
    cyl = gluNewQuadric();
    glTranslatef(0.48, 0.82, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(-90.0, 0.0, 1.0, 0.0);
    gluCylinder(cyl, 0.02, 0.01, 0.1, 20, 20);
    glPopMatrix();

    // �޻� 3
    glPushMatrix();
    cyl = gluNewQuadric();
    glTranslatef(0.5, 0.7, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(-50.0, 0.0, 1.0, 0.0);
    gluCylinder(cyl, 0.02, 0.01, 0.1, 20, 20);
    glPopMatrix();

    // �޻� 4
    glPushMatrix();
    cyl = gluNewQuadric();
    glTranslatef(0.6, 0.6, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(-30.0, 0.0, 1.0, 0.0);
    gluCylinder(cyl, 0.02, 0.01, 0.1, 20, 20);
    glPopMatrix();

    // �޻� 5
    glPushMatrix();
    cyl = gluNewQuadric();
    glTranslatef(0.72, 0.54, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(-10.0, 0.0, 1.0, 0.0);
    gluCylinder(cyl, 0.02, 0.01, 0.1, 20, 20);
    glPopMatrix();

    // �޻� 6
    glPushMatrix();
    cyl = gluNewQuadric();
    glTranslatef(0.86, 0.54, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(10.0, 0.0, 1.0, 0.0);
    gluCylinder(cyl, 0.02, 0.01, 0.1, 20, 20);
    glPopMatrix();

}

// �� �׸��� �Լ�
void draw_sun() {
    // �ظ� �׸� ��
    glPushMatrix();
    glColor3f(0.99, 0.72, 0.07);
    glTranslatef(0.8, 0.8, 0.0);
    glutSolidSphere(0.2, 20, 20);
    glPopMatrix();

    // �޻�׸��� �Լ� ȣ��
    draw_sunlight();
}

// ��� �׸��� �Լ�
void draw_human() {
    // ��� ��
    glPushMatrix();
    glColor3f(0.98, 0.80, 0.70);
    glTranslatef(0.0, 0.5, 0.0);
    glutSolidSphere(0.3, 20, 20);
    glPopMatrix();

    // ��� �� R
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    if (day_or_night == DAY) {
        glTranslatef(0.12 + sin(time) * 0.05, 0.6, 0.26 - sin(time) * 0.033);
        glutSolidSphere(0.03, 20, 20);
    }
    else {
        glBegin(GL_QUADS);
        glVertex3f(0.05, 0.58, 0.3);
        glVertex3f(0.15, 0.58, 0.3);
        glVertex3f(0.15, 0.60, 0.3);
        glVertex3f(0.05, 0.60, 0.3);
        glEnd();
    }
    glPopMatrix();

    // ��� �� L
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    if (day_or_night == DAY) {
        glTranslatef(-0.12 + sin(time) * 0.05, 0.6, 0.26 + sin(time) * 0.033);
        glutSolidSphere(0.03, 20, 20);
    }
    else {
        glBegin(GL_QUADS);
        glVertex3f(-0.15, 0.58, 0.3);
        glVertex3f(-0.05, 0.58, 0.3);
        glVertex3f(-0.05, 0.60, 0.3);
        glVertex3f(-0.15, 0.60, 0.3);
        glEnd();
    }
    glPopMatrix();

    // ����
    glPushMatrix();
    glColor3f(0.2, 0.2, 0.2);
    cyl = gluNewQuadric();
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glTranslatef(0.0, 0.0, -0.2);
    gluCylinder(cyl, 0.02, 0.02, 0.7, 20, 20);
    glPopMatrix();

    // �� R
    glPushMatrix();
    cyl = gluNewQuadric();
    glTranslatef(0.0, 0.1, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);

    if (day_or_night == DAY) glRotatef(50.0 + sin(time) * 30, 0.0, 1.0, -0.5);
    else glRotatef(50.0, 0.0, 1.0, 0.0);

    gluCylinder(cyl, 0.02, 0.02, 0.5, 20, 20);
    glPopMatrix();

    // �� L
    glPushMatrix();
    cyl = gluNewQuadric();
    glTranslatef(0.0, 0.1, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);

    if (day_or_night == DAY) glRotatef(-50.0 + sin(time) * 30, 0.0, 1.0, -0.5);
    else glRotatef(-50, 0, 1, 0);

    gluCylinder(cyl, 0.02, 0.02, 0.5, 20, 20);
    glPopMatrix();

    // �ٸ� R
    glPushMatrix();
    cyl = gluNewQuadric();
    glTranslatef(0.0, -0.5, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(30.0, 0.0, 1.0, 0.0);
    gluCylinder(cyl, 0.02, 0.02, 0.5, 20, 20);
    glPopMatrix();

    // �ٸ� L
    glPushMatrix();
    cyl = gluNewQuadric();
    glTranslatef(0.0, -0.5, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(-30.0, 0.0, 1.0, 0.0);
    gluCylinder(cyl, 0.02, 0.02, 0.5, 20, 20);
    glPopMatrix();
}

// Ÿ�̸� �Լ�
void timer(int value) {
    time += 0.1;
    glutPostRedisplay();

    // ��͸� ���� ���α׷� ���ۺ��� ������ ��� ȣ���.
    glutTimerFunc(40, timer, 1);
}

// ���콺 �ݹ��Լ�
void mouse_callback(GLint X, GLint Y) {
    // ���콺 ������ X, Y�� ���������� ViewX, ViewY�� �Ҵ�
    ViewX = X; ViewY = Y;
    glutPostRedisplay();
}

// Ű���� �ݹ��Լ�
void keyboard_callback(unsigned char key, int x, int y) {
    switch (key) {
        // �����̽��ٸ� ������ ���
    case ' ':
        // DAY��忴�� �� NIGHT���� ��ȯ�ϰ�
        // NIGHT��忴���� time�� 0���� �ʱ�ȭ�� �� DAY���� ��ȯ.
        if (day_or_night == DAY) day_or_night = NIGHT;
        else {
            time = 0;
            day_or_night = DAY;
        }
        break;

        // Q Ȥ�� q�� ���ȴٸ� ���α׷� ����
    case 'Q':
    case 'q':
        exit(0);
        break;
    }
}

// ������ �ݹ��Լ�
void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

// �޴� �Լ�
void menu(int id) {
    // 1�ϰ�� �����, 2�ϰ�� ����, 3�ϰ�� ���α׷� ����
    switch (id) {
    case 1:
        day_or_night = DAY;
        break;
    case 2:
        day_or_night = NIGHT;
        break;
    case 3:
        exit(0);
        break;
    }
}

// �޴� ���� �Լ�
void create_menu() {
    // �޴��� ������ 1, 2, 3���� �̸��� �ο��ϰ� ������ ���콺 Ŭ������ �����.
    GLint mainmenu = glutCreateMenu(menu);
    glutAddMenuEntry("daytime", 1);
    glutAddMenuEntry("midnight", 2);
    glutAddMenuEntry("exit", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// �����Լ�
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Daytime or Midnight");

    init_light(); // ���� ����
    glutDisplayFunc(display); // ���÷��� ���
    glutKeyboardFunc(keyboard_callback); // Ű���� �ݹ� ���
    glutMotionFunc(mouse_callback); // ���콺 �ݹ� ���
    glutReshapeFunc(reshape); // ������ �ݹ� ���
    glutTimerFunc(40, timer, 1); // Ÿ�̸� �Լ� ����
    create_menu(); // �޴� ���� �� ���

    glutMainLoop();
    return 0;
}
