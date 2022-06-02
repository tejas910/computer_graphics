
#include<GL/gl.h>
#include<iostream>
#include <GL/glut.h>
int posx=0,posy=0;

// tree
void tree()
{

// tree1

glColor3f(0.6,0,0);
glBegin(GL_POLYGON);
    glVertex3i(50, 350, 0);
    glVertex3i(70, 350, 0);
    glVertex3i(70, 500, 0);
    glVertex3i(50, 500, 0);
glEnd();
  glColor3f(0.0, 0.2, 0.0);
glBegin(GL_POLYGON);
    glVertex3i(10, 500, 0);
    glVertex3i(110, 500, 0);
    glVertex3i(60, 600, 0);
glEnd();
glBegin(GL_POLYGON);
    glVertex3i(15, 550, 0);
    glVertex3i(105, 550, 0);
    glVertex3i(60, 650, 0);
glEnd();

// tree2
glColor3f(0.6,0,0);
glBegin(GL_POLYGON);
    glVertex3i(50+100, 350, 0);
    glVertex3i(70+100, 350, 0);
    glVertex3i(70+100, 500, 0);
    glVertex3i(50+100, 500, 0);
glEnd();
  glColor3f(0.0, 0.5, 0.0);
glBegin(GL_POLYGON);
    glVertex3i(10+100, 500, 0);
    glVertex3i(110+100, 500, 0);
    glVertex3i(60+100, 600, 0);
glEnd();
glBegin(GL_POLYGON);
    glVertex3i(15+100, 550, 0);
    glVertex3i(105+100, 550, 0);
    glVertex3i(60+100, 650, 0);
glEnd();

// tree3
glColor3f(0.6,0,0);
glBegin(GL_POLYGON);
    glVertex3i(50+1000, 350+100, 0);
    glVertex3i(70+1000, 350+100, 0);
    glVertex3i(70+1000, 500+100, 0);
    glVertex3i(50+1000, 500+100, 0);
glEnd();
  glColor3f(0.0, 0.5, 0.0);
glBegin(GL_POLYGON);
    glVertex3i(10+1000, 500+100, 0);
    glVertex3i(110+1000, 500+100, 0);
    glVertex3i(60+1000, 600+100, 0);
glEnd();
glBegin(GL_POLYGON);
    glVertex3i(15+1000, 550+100, 0);
    glVertex3i(105+1000, 550+100, 0);
    glVertex3i(60+1000, 650+100, 0);
glEnd();

///tree4
glColor3f(0.6,0,0);
glBegin(GL_POLYGON);
    glVertex3i(50+1100, 350+200, 0);
    glVertex3i(70+1100, 350+200, 0);
    glVertex3i(70+1100, 500+200, 0);
    glVertex3i(50+1100, 500+200, 0);
glEnd();
  glColor3f(0.0, 0.5, 0.0);
glBegin(GL_POLYGON);
    glVertex3i(10+1100, 500+200, 0);
    glVertex3i(110+1100, 500+200, 0);
    glVertex3i(60+1100, 600+200, 0);
glEnd();
glBegin(GL_POLYGON);
    glVertex3i(15+1100, 550+200, 0);
    glVertex3i(105+1100, 550+200, 0);
    glVertex3i(60+1100, 650+200, 0);
glEnd();


// tree5
glColor3f(0.6,0,0);
glBegin(GL_POLYGON);
    glVertex3i(50+900, 350+200, 0);
    glVertex3i(70+900, 350+200, 0);
    glVertex3i(70+900, 500+200, 0);
    glVertex3i(50+900, 500+200, 0);
glEnd();

  glColor3f(0.0, 0.5, 0.0);

glBegin(GL_POLYGON);
    glVertex3i(10+900, 500+200, 0);
    glVertex3i(110+900, 500+200, 0);
    glVertex3i(60+900, 600+200, 0);
glEnd();

glBegin(GL_POLYGON);
    glVertex3i(15+900, 550+200, 0);
    glVertex3i(105+900, 550+200, 0);
    glVertex3i(60+900, 650+200, 0);
glEnd();

}



// river

void river()
{
glColor3f(0.03, 0.5, 0.9);
glBegin(GL_POLYGON); // river is drawn at bottom of window/
    glVertex3i(0, 0, 0); 
    glVertex3i(1200, 0, 0);
    glVertex3i(1200, 300, 0);
    glVertex3i(0, 300, 0);
glEnd();

}


// land
void land()
{
    glColor3f(0.5 ,1.0 ,0.5); // land is drawn over the river
    glBegin(GL_POLYGON);
    glVertex3i(0, 300, 0);
    glVertex3i(1200, 300, 0);
    glVertex3i(1200, 600, 0);
    glVertex3i(0, 600, 0);
glEnd();

}

// hill
void hill()

{
    glColor3f(0.5, 0.2, 0.0);
    glBegin(GL_POLYGON);

    glVertex3i(600, 600, 0);
    glVertex3i(800, 900, 0);
    glVertex3i(900, 650, 0);
    //glVertex3i(600, 600, 0);

    glColor3f(0.5, 0.2, 0.0);
    glBegin(GL_POLYGON);

    //glVertex3i(600, 600, 0);
    glVertex3i(900, 650, 0);
    glVertex3i(1000, 800, 0);
    glVertex3i(1100, 620, 0);

     glColor3f(0.5, 0.2, 0.0);
    glBegin(GL_POLYGON);
    glVertex3i(1050, 620, 0);
    glVertex3i(1200, 800, 0);
    glVertex3i(1200, 600, 0);
    //glVertex3i(1100, 620, 0);
glEnd();
}



// house
void house()
{

// house1
glColor3f(0.5, 0.0, 0.5);
glBegin(GL_POLYGON);
    glVertex3i(220, 350, 0);
    glVertex3i(380, 350, 0);
    glVertex3i(380, 450, 0);
    glVertex3i(220, 450, 0);
glEnd();

glColor3f(0, 0, 1); // triangle
glBegin(GL_POLYGON);
    glVertex3i(200, 450, 0);
    glVertex3i(400, 450, 0);
    glVertex3i(300, 650, 0);
glEnd();

glColor3f(1,1,0);
glBegin(GL_POLYGON);
    glVertex3i(280, 350, 0);
    glVertex3i(320, 350, 0);
    glVertex3i(320, 450, 0);
    glVertex3i(280, 450, 0);
glEnd();


// house2

glColor3f(0.5, 0.0, 0.5);
glBegin(GL_POLYGON);
    glVertex3i(220+200, 350+50, 0);
    glVertex3i(380+200, 350+50, 0);
    glVertex3i(380+200, 450+50, 0);
    glVertex3i(220+200, 450+50, 0);
glEnd();

glColor3f(1.444, .5, 0);
glBegin(GL_POLYGON);
    glVertex3i(200+200, 450+50, 0);
    glVertex3i(400+200, 450+50, 0);
    glVertex3i(300+200, 650+50, 0);
glEnd();

glColor3f(1,1,0);
glBegin(GL_POLYGON);
    glVertex3i(280+200, 350+50, 0);
    glVertex3i(320+200, 350+50, 0);
    glVertex3i(320+200, 450+50, 0);
    glVertex3i(280+200, 450+50, 0);
glEnd();

}

int rad,x,y,a,b,h;
bool SE,E;

// Sun 
void sun()
{

glColor3f(1.0, 2.0, 0.0);
a=1000;
b=1000;
x=0;
rad=80;  //radius 
y=rad;
h=1-rad;
glBegin(GL_POLYGON); // draw circle 

glVertex3i(x+b,y+b,0);


if(h>=0)
{
    SE=true;
    E=false;
}
else

{
    E=true;
    SE=false;

}
while(y>=x)
{
    if(SE)
    {

        h=h+5+2*(x-y);


        if(h>=0)
{
    SE=true;
    E=false;
}
else
{
    E=true;
    SE=false;

}
x++;
y--;
       glVertex3f(x+a, y+b ,0.0);
       glVertex3f(y+a, x+b, 0.0);
       glVertex3f(-y+a, x+b, 0.0);
       glVertex3f(-x+a, -y+b, 0.0);
       glVertex3f(-y+a, -x+b, 0.0);
       glVertex3f(y+a,-x+b , 0.0);
       glVertex3f(x+a, -y+b, 0.0);
       glVertex3f(x+a, y+b, 0.0);
       glVertex3f(-x+a, y+b, 0.0);
    }

    if(E)
    {

        h=h+3+2*x;
        if(h>=0)
{
    SE=true;
    E=false;
}
else

{
    E=true;
    SE=false;

}
x++;


       glVertex3f(x+a, y+b,0.0);
       glVertex3i(y+a, x+b, 0.0);
       glVertex3i(-y+a, x+b, 0.0);
       glVertex3i(-x+a, -y+b, 0.0);
       glVertex3i(-y+a, -x+b, 0.0);
       glVertex3i(y+a,-x+b , 0.0);
       glVertex3i(x+a, -y+b, 0.0);
       glVertex3i(x+a, y+b, 0.0);
       glVertex3i(-x+a, y+b, 0.0);

   
    }
}

glEnd();
// glColor3f(1.0, 0.0, 0.0);
// glBegin(GL_LINES);
// glVertex3i(850,750,5);
// glVertex3i(950,900,0);
// glEnd();
}

// boat function for drawing boat
void boat()
{
    ///boat1
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);

    glVertex3i(10,150,0);
    glVertex3i(150+50,150,0);
    glVertex3i(120+50,100,0);
    glVertex3i(30,100,0);
    glEnd();
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);

    glVertex3i(50,150,0);
    glVertex3i(150,150,0);
    glVertex3i(150,220,0);
    glVertex3i(50,220,0);
    glEnd();


   
}

// various object drawn from this function
void draw_object()
{
    
        land();
        hill();
        tree();
        river();
        house();
        sun();
        glPushMatrix();
        glTranslatef(posx,0,0); // this function is used to translate the position of boat 
        boat();
        glPopMatrix();

    
    
}

// display function for dislpaying object
void display(void)
{

 glClear(GL_COLOR_BUFFER_BIT);
 draw_object();
 glFlush();

}

// Update function to update position of boat
void update(int value) {


    if(posx>=1200)
    {
        posx=0;
    }
    else{
        posx++;
    }
    glutPostRedisplay();
    glutTimerFunc(15, update, 0); // Timer function 1 st argument for delay another is callback function
}

void init(void)
{
    
    glClearColor(0.6,0.9, 0.9, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1200.0, 0, 1200.0);


}

int main(int argc, char** argv)
{

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
glutInitWindowSize(1000, 600); // set window size
glutInitWindowPosition(0, 0); // not mention window position
glutCreateWindow("Village Scenario"); // title of window
glutTimerFunc(25, update, 0);
glutDisplayFunc(display);
init();
glutMainLoop();
return 0;

}

