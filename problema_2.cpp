#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void display(void)
{


    glClear (GL_COLOR_BUFFER_BIT);
    glPointSize(2.0f);
    glColor3f (1.0, 1.0, 1.0);



    glBegin(GL_TRIANGLE_STRIP);
   

	        
        glColor3f (0.0, 1.0, 0.0); 
        glVertex3f (1.0, 0.0, 0.0);//FORMA DERECHA        
        glVertex3f (0.4, 0.5, 0.0);
        glVertex3f (0.4, -0.5, 0.0);
        
        
        glColor3f (1.0, 1.0, 0.0);
        glVertex3f (0.0, 1.0, 0.0); //FORMA SUPERIOR
        glVertex3f (-0.4, 0.5, 0.0);
        glVertex3f (0.4, 0.5, 0.0);
        		     
		                    
               
        
        glColor3f (0.0, 1.0, 0.0);
        glVertex3f (-1.0, 0.0, 0.0);    //FORMA IZQUIERDA
        glVertex3f (-0.4, 0.5, 0.0);
        glVertex3f (-0.4, -0.5, 0.0);
        
        
		glColor3f (1.0, 0.0, 0.0);
		glVertex3f (0.0, -1.0, 0.0); //FORMA INFERIOR
        glVertex3f (-0.4, -0.5, 0.0);
        glVertex3f (0.4, -0.5, 0.0);
		glEnd();
		
				
				
		 glBegin(GL_POLYGON);
		glColor3f (0.0, 0.0, 1.0); //FORMA CENTRAL
		glVertex3f (0.4, -0.5, 0.0);
        glVertex3f (0.4, 0.5, 0.0);
        glVertex3f (-0.4, 0.5, 0.0);
        glVertex3f (-0.4, -0.5, 0.0);


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
    glutCreateWindow ("EJER_2");
    init ();
    glutDisplayFunc(display);
    glutMainLoop ();
    return 0;
}
