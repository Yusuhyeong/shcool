/***********************************************************************************/
/*                           HW#3 : 3D 가스켓 프로그램                             */
/*  작성자 : 유수형                              날짜 : 2020년 10월 7일            */
/*                                                                                 */
/* 문제 정의 :  viewport를 통해 3D tetrahedron Gasket 구현                         */
/*              viewport를 통해 구현될 경우 가시 부피를 고려하여                   */
/*              설정된 도형의 자표를 초기화 및 재설정을 통해 구현한다              */
/*                                                                                 */
/***********************************************************************************/


#include<stdlib.h> // rand() 함수 사용 용도
#include<GL/glut.h>

GLfloat v[4][3] = { {0.0,0.0,1.0}, {0.0,1.0,0.0}, {-1.0,-0.5,0.0}, {1.0,-0.5,0.0} }; // 도형의 초기 꼭지점 좌표 설정
GLfloat colors[4][3] = { {1.0,0.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{0.0,0.0,0.0} }; // 꼭지점 좌표로 이루어지는 면의 색상 설정
int n = 2; //분할되는 횟수

void triangle(GLfloat* va, GLfloat* vb, GLfloat* vc) // 삼각형 좌표를 설정하는 함수
{
    glVertex3fv(va);
    glVertex3fv(vb);
    glVertex3fv(vc);
}

void tetra(GLfloat* a, GLfloat* b, GLfloat* c, GLfloat* d) // 꼭지점으로 연결된 면의 색상 선택(면과 면을 구분짓기 위해)
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

void divide_tetra(GLfloat* a, GLfloat* b, GLfloat* c, GLfloat* d, int m) // 삼각형 분할
{
    GLfloat mid[6][3];
    int j;
    if (m > 0) // 정사면체의 각 꼭지점에 이어지는 모서리에 중앙값이 찍힌다.
               // 따라서 for문을 6번 반복하여 각 꼭지점에 이어지는 모서리의 중앙값을 계산하고
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
        divide_tetra(a, mid[0], mid[1], mid[2], m - 1); // 이러한 for문을 m번 반복하게 된다.
        divide_tetra(mid[0], b, mid[3], mid[5], m - 1);
        divide_tetra(mid[1], mid[3], c, mid[4], m - 1);
        divide_tetra(mid[2], mid[5], mid[4], d, m - 1);
    }
    else // m이 0보다 작게되면 tetra함수를 통해 색상과 분할된 정사면체를 생성한다.
        tetra(a, b, c, d);
}

void Mydisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_TRIANGLES); // 첫 삼각형 세 점을 그린다.
    divide_tetra(v[0], v[1], v[2], v[3], n); // 초기설정한 좌표와 n = 2라는 값으로 정사면체를 분할한다.
    glEnd();
    glFlush();
}

void myReshape(int NewWidth, int NewHeight)
{
    glViewport(0, 0, NewWidth, NewHeight); 	// 이벤트를 통해 뷰 포트를 새롭게 받은 가로와 세로길이로 설정.
    glMatrixMode(GL_PROJECTION); // GL_PROJECTION으로 변경
    glLoadIdentity(); // 투영변환
    glOrtho(-2.0, 2.0, -2.0, 2.0, -10.0, 10.0); // 모델 뷰 행렬 선택
    glMatrixMode(GL_MODELVIEW);	// 현재 모델뷰 행렬을 항등행렬로 초기화
    glutPostRedisplay(); // 초기화, 재설정으로 이루어진 좌표를 다시 설정
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