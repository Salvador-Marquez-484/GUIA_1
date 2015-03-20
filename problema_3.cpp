#include <GL/gl.h>
#include <GL/glut.h>

void display(void)
{ 
		glClear(GL_COLOR_BUFFER_BIT); 
		glColor3f (1.0, 1.0, 1.0);
		glPointSize(30); 
		
		
		glBegin(GL_POINTS); 
		glVertex3f(-0.5, 0.088, 0.0); 
		glVertex3f(-0.5, -0.088, 0.0);
		glEnd(); 

		glBegin(GL_QUADS); 
		glVertex3f(0.5, -0.177, 0.0);
		glVertex3f(0.5, 0.177, 0.0); 
		glVertex3f(-0.5, 0.177, 0.0); 
		glVertex3f(-0.5, -0.177, 0.0); 
		glEnd(); 
	  
	   glBegin(GL_TRIANGLES);
	   glColor3f(   0.0,  0.0,  1.0 );
	   glVertex3f(0.5, -0.2, 0.0); 
	   glVertex3f(0.7, 0.0, 0.0);
	   glVertex3f(0.5, 0.2, 0.0); 

  
		//Ala de Arriba 
	 glColor3f(   0.0,  0.0,  1.0 );
     glVertex3f(0.2, 0.177, 0.0);
     glVertex3f(0.0, 0.4, 0.0);
	 glVertex3f(-0.2, 0.177, 0.0); 
	 glVertex3f(0.0, 0.4, 0.0); 
	 glVertex3f(-0.177, 0.177, 0.0); 
	 glVertex3f(-0.5, 0.4, 0.0); 
	 
	//Ala de abajo 
	  glColor3f(   0.0,  0.0,  1.0 );
	  glVertex3f(0.2, -0.177, 0.0); 
	  glVertex3f(0.0, -0.4, 0.0); 
	  glVertex3f(-0.2, -0.177, 0.0);
	  glVertex3f(0.0, -0.4, 0.0); 
	  glVertex3f(-0.177, -0.177, 0.0); 
	  glVertex3f(-0.5, -0.4, 0.0); 
	  glEnd();
	  glFlush(); 
}
	   
void init (void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -1, 1);
}

int main(int argc, char** argv)

{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (600, 600);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("EJER_3");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
