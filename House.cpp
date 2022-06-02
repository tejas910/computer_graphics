//Open GL libraries
#include<GL/gl.h> //GL library
#include<GL/glu.h> //GLU library
#include<GL/freeglut.h> // glut library
#include<iostream> 

//Init function which initialize gl functions
void initGL(){
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glLineWidth(8.0);
	glPointSize(15.0);
}

// display all objects which you want to display on window
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES); // GL_LINES attribute
	glPointSize(10.0); // pointsize function 
	glColor3f(1.0f,1.0f,0.0f);
	glVertex2f(-0.1,0.0);
	glVertex2f(-0.4,0.0);
	glVertex2f(-0.4,0.0);
	glVertex2f(-0.2,0.2);
	glVertex2f(-0.2,0.2);
	glVertex2f(-0.1,0.0); // glvertex function 
	glEnd(); // End of block

	glBegin(GL_LINES);
	glPointSize(10.0);
	glColor3f(2.0f,2.0f,0.0f);
	glVertex2f(-0.2,0.2);
	glVertex2f(0.3,0.2);
	glVertex2f(0.3,0.2);
	glVertex2f(0.3,0.0);
	glVertex2f(0.3,0.0);
	glVertex2f(-0.1,0.0);// glvertex function 
	glEnd(); // End of block

	glBegin(GL_LINES);
	glPointSize(10.0);
	glColor3f(1.0f,1.0f,0.0f);
	glVertex2f(-0.4,0.0);
	glVertex2f(-0.4,-0.4);
	glVertex2f(-0.4,-0.4);
	glVertex2f(0.3,-0.4);
	glVertex2f(0.3,-0.4);
	glVertex2f(0.3,0.0);// glvertex function 
	glEnd(); // End of block


	glBegin(GL_LINES);
	glPointSize(10.0);
	glColor3f(3.0f,3.0f,0.0f);
	glVertex2f(-0.1,0.0);
	glVertex2f(-0.1,-0.4);// glvertex function 
	glEnd(); // End of block

	glBegin(GL_LINES);
	glPointSize(10.0);
	glColor3f(1.0f,1.0f,0.0f);
	glVertex2f(-0.3,-0.4);
	glVertex2f(-0.3,-0.2);
	glVertex2f(-0.3,-0.2);
	glVertex2f(-0.2,-0.2);
	glVertex2f(-0.2,-0.2);
	glVertex2f(-0.2,-0.4);// glvertex function 
	glEnd(); // End of block

	glBegin(GL_LINES);
	glPointSize(10.0);
	glColor3f(0.0f,1.0f,0.0f);
	glVertex2f(0.1,-0.2);
	glVertex2f(0.1,-0.1);
	glVertex2f(0.1,-0.1);
	glVertex2f(0.2,-0.1);
	glVertex2f(0.2,-0.1);
	glVertex2f(0.2,-0.2);
	glVertex2f(0.2,-0.2);
	glVertex2f(0.1,-0.2);
	glEnd();
	glFlush();

}
int main(int argc, char **argv)
{

	glutInit(&argc , argv); // calling init function
	glutCreateWindow("House"); // function to title window
	glutInitWindowSize(800,600); // mention size of window
	glutDisplayFunc(display); // callback function
	initGL(); 
	glutMainLoop(); // infinite loop to hold screen
	return 0;

}