#include<GL/glut.h> 
#include<math.h> 
#include<stdlib.h> 
#include<iostream> 
using namespace std;

int w=640,h=480; 
int x1,y2,choice; 
float boundaryColor[3]={0,0,0},interiorColor[3]={1,1,1},fillColor[3]={0,0,0}; float readPixel[3]; 


void setPixel(int x,int y) 
{ 
glColor3fv(fillColor); 
glBegin(GL_POINTS); 
glVertex2f(x,y); 
glEnd(); 
glFlush(); 
} 
void getPixel(int x,int y,float *color) 
{ 
    glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,color); 
} 
 
 
     void polygon(){
       glBegin(GL_LINES);
        glLineWidth(10.0);
         glColor3f(0.0,1.0,0.0);        
         glVertex2i(100,100);
         glVertex2i(230,250);
         glVertex2i(230,250);
         glVertex2i(350,100);
          glVertex2i(350,100);
           glVertex2i(100,100);
        
       glEnd();
       
   }
void display() 
{ 
glClearColor(1.0,1.0,1.0,0.0); 
glColor3f(0.0,0.0,0.0); 
glLoadIdentity(); 
glLineWidth(10.0);
gluOrtho2D(0,640,0,480); 
glClear(GL_COLOR_BUFFER_BIT); 
   polygon();
   
   glEnd();
   glFlush();
} 
       void floodFill(int x,int y) //flood fill algo 
    { 
         getPixel(x,y,readPixel); 
   if(readPixel[0]==interiorColor[0]&&readPixel[1]==interiorColor[1]&&readPixel[2]==interiorColor[2]) 
  { 

   glBegin(GL_POINTS);
   glVertex2f(x,y); 
    glEnd();
    floodFill(x+1,y); 
    floodFill(x,y+1); 
    floodFill(x-1,y); 
    floodFill(x,y-1); 

glFlush(); 
}
} 


void boundaryFill(int x,int y) 
{ 
getPixel(x,y,readPixel); 
if(readPixel[0]!=boundaryColor[0] && readPixel[1]!=boundaryColor[1] && readPixel[2]!=boundaryColor[2]) 
{ 
    glColor3f(fillColor[0],fillColor[1],fillColor[2]);
      glBegin(GL_POINTS);
   glVertex2f(x,y); 
    glEnd();
    glFlush(); 
boundaryFill(x+1,y); 
boundaryFill(x,y+1); 
boundaryFill(x-1,y); 
boundaryFill(x,y-1); 
  
} 
} 
   
   void mouse(int btn,int state,int x,int y) 
    { 
       if((btn==GLUT_LEFT_BUTTON)&&(state==GLUT_DOWN)) 
        { 
         x1=x; 
         y2=480-y; 
        if(choice==1)boundaryFill(x1,y2); 
        else if(choice==2)floodFill(x1,y2); 
        } 
    } 


     void menu(int item) 
 { 
       if(item==1) //boundary fill 
    { 
       choice=1; 
       fillColor[0]=0;
       fillColor[1]=0; 
       fillColor[2]=1; 
     } 
    else if(item==2) //flood fill   
{ 
       choice=2; 
       fillColor[0]=0.0; 
       fillColor[1]=1.0; 
       fillColor[2]=0.0; 
} 
else if(item==3)exit(0); 
} 
int main(int argc,char **argv) 
{ 
glutInit(&argc,argv); 
//glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
glutInitWindowSize(w,h); 
glutCreateWindow("Boundary and Flood Fill Algorithm"); 
glutCreateMenu(menu); 
glutAddMenuEntry("Boundary Fill",1); 
glutAddMenuEntry("Flood Fill",2); 
glutAddMenuEntry("Exit",3); 
glutAttachMenu(GLUT_RIGHT_BUTTON); 
glutDisplayFunc(display); 
glutMouseFunc(mouse); 
glutMainLoop(); 
return 0; 
}