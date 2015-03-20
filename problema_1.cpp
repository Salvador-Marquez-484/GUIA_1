#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h> 

 void display(void)
 {
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glPointSize(6);
	
	
	GLfloat angulo;
	int i;
	
	glBegin(GL_POINTS);
	
	
	for (i=0; i<360; i+=7.2)
	
	{
	angulo= i+M_PI/180;
	
	glVertex3f (cos(angulo)*0.5, sin(angulo)*0.5, 0.0f);
	
}
	
	glEnd();
	glEnd();
	glFlush ();
 }
 void init (void)
 {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
 }
 int main(int argc, char** argv)
 {
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (600, 600);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("EJER_1");
	init ();
	glutDisplayFunc(display);
	glutMainLoop ();
	return 0;
}
