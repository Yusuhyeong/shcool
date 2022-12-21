#include <gl/glut.h>
#include <math.h>

// 낮모드와 밤모드를 위한 매크로 상수
#define DAY true
#define NIGHT false

// mouse movement 담아내는 변수들. 초기값은 정면이 보이도록 설정.
int ViewX = 300, ViewY = 300;

// 애니메이션을 구현하기 위해 필요한 시간 변수. (팔, 눈을 움직일때 사용)
static double time = 0;

// 초기세팅은 밤모드로 설정. (false)
bool day_or_night = NIGHT;

// 몸통, 팔다리, 햇살을 표현할 때 필요한 실린더 포인터 변수.
GLUquadricObj* cyl;

// ====== 함수모음 ======

// 그리기 함수
void draw_sunlight(); // 햇살 그리기
void draw_sun(); // 해 그리기
void draw_human(); // 사람 그리기

// 기타 함수
void init_light(); // 조명 초기화 함수
void timer(int value); // 타이머 함수
void mouse_callback(GLint X, GLint Y); // 마우스 콜백함수
void keyboard_callback(unsigned char key, int x, int y); // 키보드 콜백함수
void display(); // 디스플레이 함수
void reshape(int w, int h); // 리셰잎 콜백함수
void menu(int id); // 메뉴 함수
void create_menu(); // 메뉴생성 함수

// =======================


// 조명 초기화 함수
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

    // 이 코드로 원래 색깔이 보존될 수 있도록 함.
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

// 디스플레이 함수
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // gluLookAt 함수 인자 중 centerX와 centerY를 이용해
    // ViewX, ViewY 값 즉 마우스 드래그에 따라 시점변환 구현.
    gluLookAt(0.0, 0.0, 0.0, ViewX * 0.05 - 15.0, 15.0 - ViewY * 0.05, -1.0, 0.0, 1.0, 0.0);

    // 사람을 우선 그리고
    draw_human();

    // 낮모드일 경우 좀 배경을 더 밝게, 밤모드일 경우 좀 더 어둡게 세팅.
    // 또한 낮모드일 경우 해를 추가로 모델링.
    if (day_or_night == DAY) {
        glClearColor(0.9, 0.6, 0.3, 0.5);
        draw_sun();
    }
    else glClearColor(0.1, 0.2, 0.4, 0.5);

    glFlush();
}

// 햇살 그리기 함수
void draw_sunlight() {
    // 햇살 1
    glPushMatrix();
    cyl = gluNewQuadric();
    glTranslatef(0.54, 0.97, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(-110.0, 0.0, 1.0, 0.0);
    gluCylinder(cyl, 0.02, 0.01, 0.1, 20, 20);
    glPopMatrix();

    // 햇살 2
    glPushMatrix();
    cyl = gluNewQuadric();
    glTranslatef(0.48, 0.82, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(-90.0, 0.0, 1.0, 0.0);
    gluCylinder(cyl, 0.02, 0.01, 0.1, 20, 20);
    glPopMatrix();

    // 햇살 3
    glPushMatrix();
    cyl = gluNewQuadric();
    glTranslatef(0.5, 0.7, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(-50.0, 0.0, 1.0, 0.0);
    gluCylinder(cyl, 0.02, 0.01, 0.1, 20, 20);
    glPopMatrix();

    // 햇살 4
    glPushMatrix();
    cyl = gluNewQuadric();
    glTranslatef(0.6, 0.6, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(-30.0, 0.0, 1.0, 0.0);
    gluCylinder(cyl, 0.02, 0.01, 0.1, 20, 20);
    glPopMatrix();

    // 햇살 5
    glPushMatrix();
    cyl = gluNewQuadric();
    glTranslatef(0.72, 0.54, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(-10.0, 0.0, 1.0, 0.0);
    gluCylinder(cyl, 0.02, 0.01, 0.1, 20, 20);
    glPopMatrix();

    // 햇살 6
    glPushMatrix();
    cyl = gluNewQuadric();
    glTranslatef(0.86, 0.54, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(10.0, 0.0, 1.0, 0.0);
    gluCylinder(cyl, 0.02, 0.01, 0.1, 20, 20);
    glPopMatrix();

}

// 해 그리기 함수
void draw_sun() {
    // 해를 그린 뒤
    glPushMatrix();
    glColor3f(0.99, 0.72, 0.07);
    glTranslatef(0.8, 0.8, 0.0);
    glutSolidSphere(0.2, 20, 20);
    glPopMatrix();

    // 햇살그리기 함수 호출
    draw_sunlight();
}

// 사람 그리기 함수
void draw_human() {
    // 사람 얼굴
    glPushMatrix();
    glColor3f(0.98, 0.80, 0.70);
    glTranslatef(0.0, 0.5, 0.0);
    glutSolidSphere(0.3, 20, 20);
    glPopMatrix();

    // 사람 눈 R
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

    // 사람 눈 L
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

    // 몸통
    glPushMatrix();
    glColor3f(0.2, 0.2, 0.2);
    cyl = gluNewQuadric();
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glTranslatef(0.0, 0.0, -0.2);
    gluCylinder(cyl, 0.02, 0.02, 0.7, 20, 20);
    glPopMatrix();

    // 팔 R
    glPushMatrix();
    cyl = gluNewQuadric();
    glTranslatef(0.0, 0.1, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);

    if (day_or_night == DAY) glRotatef(50.0 + sin(time) * 30, 0.0, 1.0, -0.5);
    else glRotatef(50.0, 0.0, 1.0, 0.0);

    gluCylinder(cyl, 0.02, 0.02, 0.5, 20, 20);
    glPopMatrix();

    // 팔 L
    glPushMatrix();
    cyl = gluNewQuadric();
    glTranslatef(0.0, 0.1, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);

    if (day_or_night == DAY) glRotatef(-50.0 + sin(time) * 30, 0.0, 1.0, -0.5);
    else glRotatef(-50, 0, 1, 0);

    gluCylinder(cyl, 0.02, 0.02, 0.5, 20, 20);
    glPopMatrix();

    // 다리 R
    glPushMatrix();
    cyl = gluNewQuadric();
    glTranslatef(0.0, -0.5, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(30.0, 0.0, 1.0, 0.0);
    gluCylinder(cyl, 0.02, 0.02, 0.5, 20, 20);
    glPopMatrix();

    // 다리 L
    glPushMatrix();
    cyl = gluNewQuadric();
    glTranslatef(0.0, -0.5, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(-30.0, 0.0, 1.0, 0.0);
    gluCylinder(cyl, 0.02, 0.02, 0.5, 20, 20);
    glPopMatrix();
}

// 타이머 함수
void timer(int value) {
    time += 0.1;
    glutPostRedisplay();

    // 재귀를 통해 프로그램 시작부터 끝까지 계속 호출됨.
    glutTimerFunc(40, timer, 1);
}

// 마우스 콜백함수
void mouse_callback(GLint X, GLint Y) {
    // 마우스 움직임 X, Y를 전역변수인 ViewX, ViewY에 할당
    ViewX = X; ViewY = Y;
    glutPostRedisplay();
}

// 키보드 콜백함수
void keyboard_callback(unsigned char key, int x, int y) {
    switch (key) {
        // 스페이스바를 눌렀을 경우
    case ' ':
        // DAY모드였을 땐 NIGHT모드로 전환하고
        // NIGHT모드였을땐 time을 0으로 초기화한 뒤 DAY모드로 전환.
        if (day_or_night == DAY) day_or_night = NIGHT;
        else {
            time = 0;
            day_or_night = DAY;
        }
        break;

        // Q 혹은 q가 눌렸다면 프로그램 종료
    case 'Q':
    case 'q':
        exit(0);
        break;
    }
}

// 리셰잎 콜백함수
void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

// 메뉴 함수
void menu(int id) {
    // 1일경우 낮모드, 2일경우 밤모드, 3일경우 프로그램 종료
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

// 메뉴 생성 함수
void create_menu() {
    // 메뉴를 생성해 1, 2, 3번에 이름을 부여하고 오른쪽 마우스 클릭으로 등록함.
    GLint mainmenu = glutCreateMenu(menu);
    glutAddMenuEntry("daytime", 1);
    glutAddMenuEntry("midnight", 2);
    glutAddMenuEntry("exit", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// 메인함수
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Daytime or Midnight");

    init_light(); // 조명 설정
    glutDisplayFunc(display); // 디스플레이 등록
    glutKeyboardFunc(keyboard_callback); // 키보드 콜백 등록
    glutMotionFunc(mouse_callback); // 마우스 콜백 등록
    glutReshapeFunc(reshape); // 리셰잎 콜백 등록
    glutTimerFunc(40, timer, 1); // 타이머 함수 시작
    create_menu(); // 메뉴 생성 및 등록

    glutMainLoop();
    return 0;
}
