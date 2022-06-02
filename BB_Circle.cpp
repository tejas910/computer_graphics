#include<iostream>
#include <GL/glu.h>
#include <GL/glut.h>
using namespace std;
#define h 800
#define w 1000

//DDA algorithm consist only float values
//where bresehnam not
int r, d, x, y, xc, yc; 

// Init function 
void myInit(void)
{
        //set white color to background
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0); //set point size 4.0
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-w/2, w/2, -h/2, h/2); //devide the axis into 4 quadrant
}

//set pixel draw that axis
void setPixel(int x, int y)
{
glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_POINTS);
glVertex2i(x, y);
glEnd();
// glFlush();
}

// this function draw circle 
void drawCircle(int xc, int yc, int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(xc+x, yc+y);
    glVertex2i(xc-x, yc+y);
    glVertex2i(xc+x, yc-y);
    glVertex2i(xc-x, yc-y);

    glVertex2i(xc+y, yc+x);
    glVertex2i(xc-y, yc+x);
    glVertex2i(xc+y, yc-x);
    glVertex2i(xc-y, yc-x);
    glEnd();

}

// This is simple circle
void circle(int xc, int yc, int r)
{  
// glColor3f(1.0f,0.0f,0.0f);
glBegin(GL_POINTS);
x=0;
y=r;
d=3-2*r;
// cout<<d;
while (y >= x)
    {
        if(d<=0)
        {
           d = d + 4*x + 6;
           x = x + 1;
        }
        else
        {
           d = d + 4*(x-y) + 10;
           x = x+1 ;
           y = y-1;
         }
        drawCircle(xc, yc, x, y);
    }
glEnd();
}

// this is concentric circle 
void concentricCircle()
{
glColor3f(0.0f,5.0f,0.0f);
circle(xc,yc,r);
glColor3f(1.0f,0.0f,0.0f);
circle(xc,yc,r/2);
       
    //glEnd();
}   


// this is olympic ring 
void olympicRing()
{
  glBegin(GL_POINTS);
glClear(GL_COLOR_BUFFER_BIT);

   glColor3f(1.0f,1.0f,0.0f);
    circle(xc+2*r+10,yc+45,r);  
  glColor3f(0.0f,1.0f,0.0f);
    circle(xc+4*r+10,yc+45,r);  
   
    glColor3f(0.0f,0.0f,1.0f);
    circle(xc+r,yc+1.7*r,r);  //1 st
glColor3f(0.0f,0.0f,0.0f);  
    circle(xc+r+2*r,yc+1.7*r,r); // 2nd
glColor3f(1.0f,0.0f,0.0f);  
    circle(xc+r+4*r,yc+1.7*r,r);  // 3rd
     glEnd();
    glFlush();
}



// Here we have to increase radius by 25
 void spiral()
{

 glBegin(GL_POINTS);
int d,x,y;
glVertex2i(xc,yc);
  glColor3f(1.0f,0.0f,0.0f);
for(int r=0;r<=150;r+=25)
{
x=0;
d=3-2*r;
y=r;
while(x<=y)
{

if(d<0)
{
d=d+4*x+6;
x=x+1;
}
else
{
d=d+4*(x-y)+10;
x=x+1;
y=y-1;
}
if(r%10==0)
{
glVertex2i(x+xc,y+yc);
glVertex2i(y+xc,x+yc);
glVertex2i(-y+xc,x+yc);
glVertex2i(-x+xc,y+yc);
}
else
{
xc+=25;
glVertex2i(-x+xc,-y+yc);
glVertex2i(-y+xc,-x+yc);
glVertex2i(y+xc,-x+yc);
glVertex2i(x+xc,-y+yc);
xc-=25;
}
}




}
  glEnd();
    glFlush();

}
// Display object function
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    for (int i = -w; i < w; i++)
{
setPixel(i, 0);
setPixel(0, i);    
    }
    glEnd();
    glFlush();

}

void menu(int choice){

        if(choice==1){
               circle( xc, yc, r); //calling of simple circle
        }
        else if(choice==2){
                concentricCircle(); //calling of concentric circle
        }
        else if(choice==3)
        {
        olympicRing(); // calling olympicring function
}
        else if(choice==4)
        {
           spiral(); // calling spiral function
        }
       
}
int main(int argc, char **argv)
{
cout<<"Enter the value of Xc: ";
cin>>xc;
cout<<"Enter the value of Yc: ";
cin>>yc;
cout<<"Enter the value of radius: ";
cin>>r;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("circle drawing");
    myInit();
    glutDisplayFunc(myDisplay);
    glutCreateMenu(menu);
        glutAddMenuEntry("draw circle ",1);
        glutAddMenuEntry("draw concentric circle",2);
        glutAddMenuEntry("draw olympic ring",3);
        glutAddMenuEntry("spirl ",4);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}