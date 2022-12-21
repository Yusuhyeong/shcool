#include <stdlib.h>
#include <GL/glut.h>
GLUquadricObj* qobj = gluNewQuadric();
int MyListID;

/*
void MyCreateList() {
	MyListID = glGenLists(1);
	glNewList(MyListID, GL_COMPILE);
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricNormals(qobj, GLU_SMOOTH);
	gluQuadricOrientation(qobj, GLU_OUTSIDE);
	gluQuadricTexture(qobj, GL_FALSE);
	gluPartialDisk(qobj, 0.4, 1.0, 50, 3, 0, 180);
	glEndList();
}
*/ //PartialDisk 持失

/*
void MyCreateList() {
	MyListID = glGenLists(1);
	glNewList(MyListID, GL_COMPILE);
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricNormals(qobj, GLU_SMOOTH);
	gluQuadricOrientation(qobj, GLU_OUTSIDE);
	gluQuadricTexture(qobj, GL_FALSE);
	gluDisk(qobj, 0.4, 1.0, 50, 3);
	glEndList();
}
*/ //Disk 持失

/*
void MyCreateList() {
	MyListID = glGenLists(1);
	glNewList(MyListID, GL_COMPILE);
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricNormals(qobj, GLU_SMOOTH);
	gluQuadricOrientation(qobj, GLU_OUTSIDE);
	gluQuadricTexture(qobj, GL_FALSE);
	glutSolidCone(1, 1, 30, 30);
	glEndList();
}
*/ //SolidCone 持失

/*
void MyCreateList() {
	MyListID = glGenLists(1);
	glNewList(MyListID, GL_COMPILE);
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricNormals(qobj, GLU_SMOOTH);
	gluQuadricOrientation(qobj, GLU_OUTSIDE);
	gluQuadricTexture(qobj, GL_FALSE);
	glutWireCone(1, 1, 30, 30);
	glEndList();
}
*/ //WireCone 持失


/*
void MyCreateList() {
	MyListID = glGenLists(1);
	glNewList(MyListID, GL_COMPILE);
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricNormals(qobj, GLU_SMOOTH);
	gluQuadricOrientation(qobj, GLU_OUTSIDE);
	gluQuadricTexture(qobj, GL_FALSE);
	glutSolidSphere(1, 30, 30);
	glEndList();
}
*/ //SolidSphere持失

/*
void MyCreateList() {
	MyListID = glGenLists(1);
	glNewList(MyListID, GL_COMPILE);
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricNormals(qobj, GLU_SMOOTH);
	gluQuadricOrientation(qobj, GLU_OUTSIDE);
	gluQuadricTexture(qobj, GL_FALSE);
	glutWireSphere(1, 30, 30);
	glEndList();
}
*/ //WireSphere 持失

/*
void MyCreateList() {
	MyListID = glGenLists(1);
	glNewList(MyListID, GL_COMPILE);
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricNormals(qobj, GLU_SMOOTH);
	gluQuadricOrientation(qobj, GLU_OUTSIDE);
	gluQuadricTexture(qobj, GL_FALSE);
	glutSolidTorus(0.5, 0.5, 50, 50);
	glEndList();
}
*/ //SolidTorus 持失

/*
void MyCreateList() {
	MyListID = glGenLists(1);
	glNewList(MyListID, GL_COMPILE);
	gluQuadricDrawStyle(qobj, GLU_FILL); 
	gluQuadricNormals(qobj, GLU_SMOOTH);
	gluQuadricOrientation(qobj, GLU_OUTSIDE); 
	gluQuadricTexture(qobj, GL_FALSE); 
	glutWireTorus(0.5, 0.5, 50, 50);
	glEndList();
}
*/ //WireTorus 持失

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(30.0, -40.0, 1.0, 0.0);
	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glCallList(MyListID);
	glutSwapBuffers();
}


void MyInit(void) {
	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 }; 
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 }; 
	GLfloat mat_shininess[] = { 50.0 }; 
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 }; 
	GLfloat model_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void Reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.5, 2.5, -2.5 * (GLfloat)h / (GLfloat)w, 2.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Graphics Primitives");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(Reshape);
	MyCreateList();
	glutMainLoop();
	return 0;
}