// Includes
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>




void display();
void specialKeys();

// Variables globales
double rotate_y=0; 
double rotate_x=0;
double rotate_z=0;

GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 1.0f;

void display(){
 
		//  Borrar la pantalla y el Z-buffer
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

		
		glLoadIdentity();

		
		//glTranslatef( 0.1, 0.0, 0.0 );
		//glRotatef( 180, 0.0, 1.0, 0.0 );
		//glScalef( 2.0, 2.0, 0.0 );


		 
		// Rotar cuando el usuario cambie los valores de “rotate_x” y “rotate_y”.
		glRotatef( rotate_x, 1.0, 0.0, 0.0 );
		glRotatef( rotate_y, 0.0, 1.0, 0.0 );
		glRotatef(rotate_z, 0.0, 0.0, 1.0 );
        glTranslatef(X, Y, Z);



		glScalef(scale, scale, scale);
  



		// LADO FRONTAL: lado multicolor
		glBegin(GL_POLYGON);
		 
		glColor3f( 1.0, 1.0, 1.0 );     glVertex3f(  0.5, -0.5, -0.5 );      // P1 es blanco
		glColor3f( 1.0, 1.0, 0.0 );     glVertex3f(  0.5,  0.5, -0.5 );      // P2 es amarillo
		glColor3f( 0.0, 0.0, 1.0 );     glVertex3f( -0.5,  0.5, -0.5 );      // P3 es azul
		glColor3f( 1.0, 0.0, 0.0 );     glVertex3f( -0.5, -0.5, -0.5 );      // P4 es roj
		 
		glEnd();



		// LADO TRASERO: lado blanco
		glBegin(GL_POLYGON);
		glColor3f(   1.0,  1.0, 1.0 );
		glVertex3f(  0.5, -0.5, 0.5 );
		glVertex3f(  0.5,  0.5, 0.5 );
		glVertex3f( -0.5,  0.5, 0.5 );
		glVertex3f( -0.5, -0.5, 0.5 );
		glEnd();
		 
		// LADO DERECHO: lado verde
		glBegin(GL_POLYGON);
		glColor3f(  0.0,  1.0,  0.0 );
		glVertex3f( 0.5, -0.5, -0.5 );
		glVertex3f( 0.5,  0.5, -0.5 );
		glVertex3f( 0.5,  0.5,  0.5 );
		glVertex3f( 0.5, -0.5,  0.5 );
		glEnd();
		 
		// LADO IZQUIERDO: lado amarillo
		glBegin(GL_POLYGON);
		glColor3f(   1.0,  1.0,  0.0 );
		glVertex3f( -0.5, -0.5,  0.5 );
		glVertex3f( -0.5,  0.5,  0.5 );
		glVertex3f( -0.5,  0.5, -0.5 );
		glVertex3f( -0.5, -0.5, -0.5 );
		glEnd();
		 
		// LADO SUPERIOR: lado azul
		glBegin(GL_POLYGON);
		glColor3f(   0.0,  0.0,  1.0 );
		glVertex3f(  0.5,  0.5,  0.5 );
		glVertex3f(  0.5,  0.5, -0.5 );
		glVertex3f( -0.5,  0.5, -0.5 );
		glVertex3f( -0.5,  0.5,  0.5 );
		glEnd();
 
		// LADO INFERIOR: lado rojo
		glBegin(GL_POLYGON);
		glColor3f(   1.0,  0.0,  0.0 );
		glVertex3f(  0.5, -0.5, -0.5 );
		glVertex3f(  0.5, -0.5,  0.5 );
		glVertex3f( -0.5, -0.5,  0.5 );
		glVertex3f( -0.5, -0.5, -0.5 );
		glEnd();
		 
		glFlush();
		glutSwapBuffers();
		 
		}


		void specialKeys( int key, int x, int y ) {
		 
		//  La flecha derecha: incrementa su rotación en 7 grados
		if (key == GLUT_KEY_RIGHT)
		  rotate_y += 7;
		 
		//  La flecha izquierda: disminuye su rotación en 7 grados
		else if (key == GLUT_KEY_LEFT)
		  rotate_y -= 7;
		 
		else if (key == GLUT_KEY_UP)
		  rotate_x += 7;
		 
		else if (key == GLUT_KEY_DOWN)
		  rotate_x -= 7;
		 
		else if (key == GLUT_KEY_F2)
		rotate_z += 7;
		else if (key == GLUT_KEY_F2)
		rotate_z -= 7;

		glutPostRedisplay();
		 
		}

		void keyboard(unsigned char key, int x, int y)
		{
		switch (key)
		{
		case 's':
		scale=0.5;
		break;
		case 'd':
		scale=1.5;
		break;
		case 'x' :
		X += 0.1f;
		break;
		case 'X' :
		X -= 0.1f;
		break;
		case 'y' :
		Y += 0.1f;
		break;
		case 'Y' :
		Y -= 0.1f;
		break;
		case 'z':
		Z -= 0.1f;
		break;
		case 'Z':
		Z += 0.1f;
		break;
		case 'q':
		exit(0); // exit
		}
		glutPostRedisplay();
}
		int main(int argc, char* argv[]){
		 
		  
		  glutInit(&argc,argv);
		  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
			 
		  glutInitWindowSize (600, 600);
	   	glutInitWindowPosition (100, 100);
		  // Crear ventana
		  glutCreateWindow("EJER_4");
		 
		  //  Habilitar la prueba de profundidad de Z-buffer
		  glEnable(GL_DEPTH_TEST);
				 
		  // Funciones de retrollamada
		  glutDisplayFunc(display);
		  glutKeyboardFunc(keyboard); //invoca funcion de teclado
		  glutSpecialFunc(specialKeys);//invoca teclas de función especial

		 
		  //  Pasar el control de eventos a GLUT
		  glutMainLoop();
		 
		  return 0;
		 
		}


