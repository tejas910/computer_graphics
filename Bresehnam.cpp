#include<iostream>
using namespace std;
#include<GL/freeglut.h>
#define h 1000
#define w 1000
 int x1,y1,x2,y2;
  int dx,dy,x,y,s1,s2,temp,interchange=0;
 void initGL(void){
    glClearColor(1.0,1.0,1.0,0.0);
         glPointSize(3.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-w/2,w/2,-h/2,h/2);
    
  
 }
 
  void setpixel(int x,int y)
  {
     glBegin(GL_POINTS);

       glColor3f(1.0,0.0,0.0);
       glPointSize(8.0);
     glVertex2i(x,y);
     glEnd();
     
   }
   
   void simple_line(){
   
    cout<<"enter first coordinate for simple line=";
   cin>>x1>>y1;
   cout<<endl;
  
   cout<<"enter second coordinate for simple line=";
   cin>>x2>>y2;
   cout<<"\n";
  
   glBegin(GL_POINTS);
    glColor3f(1.0,0.0,1.0);

    dx = abs(x2-x1);
    dy = abs(y2-y1);
    x=x1;
    y=y1;
    if((x2-x1)<0)
    {
      s1=-1;
  }
  else  
  {
    s1=1;
  }
  
  if((y2-y1)<0)
  {
    s2=-1;
  }
  else
  {
    s2=1;
  } 
  
  if(dy>dx)
  {
    temp=dx;
    dx=dy;
    dy=temp;
    interchange=1;
  }
  else
  {
  
    interchange=0;
  }
  
  float e = 2*dy-dx;
  for(int i=1;i<dx;i++)
  {
    glVertex2i(x,y);
    
    
      while(e>=0)
        {
          if(interchange=1)
          {
           x = x + s1;
        }
        else
        {
         y = y + s2;
        }
        e = e - 2*dx;
      }
      
      if(interchange=1)
      {
        y = y + s2;
      }
      else
      {
        x = x + s1;
      }
      e =e + 2*dy;
  }
     
  glEnd();
  glFlush();
   }
   
   
   
    void dashed_line(){
     
     
    cout<<"enter first coordinate for dashed line=";
   cin>>x1>>y1;
   cout<<endl;
  
   cout<<"enter second coordinate for dashed line=";
   cin>>x2>>y2;
   cout<<"\n";

    glBegin(GL_POINTS);
    glColor3f(1.0,0.0,1.0);
   
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    x=x1;
    y=y1;
    if((x2-x1)<0)
    {
      s1=-1;
  }
  else
  {
    s1=1;
  }
  
  if((y2-y1)<0)
  {
    s2=-1;
  }
  else
  {
    s2=1;
  } 
  
  if(dy>dx)
  {
    temp=dx;
    dx=dy;
    dy=temp;
    interchange=1;
  }
  else
  {
    interchange=0;
  }
  
  float e = 2*dy - dx;
  for(int i=1;i<dx;i++)
  {     
      if(i%10>4){
    glVertex2i(x,y);
     }  
      while(e>=0)
        {
          if(interchange=1)
          {
           x = x + s1;  
        }
        else
        {
         y = y + s2;
        }
        e = e - 2*dx;
      }
      
      if(interchange=1)
      {
        y = y + s2;
      }
      else
      {
        x = x + s1;
      }
      e =e + 2*dy;
  }
     
  glEnd();
  glFlush();
   }
   
   
 void dotted_line(){
   
   
   cout<<"enter first coordinate for dotted line=";
   cin>>x1>>y1;
   cout<<endl;
  
   cout<<"enter second coordinate for dotted line=";
   cin>>x2>>y2;
   cout<<"\n";
   
    glBegin(GL_POINTS);
    glColor3f(1.0,0.0,1.0);

   
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    x=x1;
    y=y1;
    if((x2-x1)<0)
    {
      s1=-1;
  }
  else
  {
    s1=1;
  }
  
  if((y2-y1)<0)
  {
    s2=-1;
  }
  else
  {
    s2=1;
  } 
  
  if(dy>dx)
  {
    temp=dx;
    dx=dy;
    dy=temp;
    interchange=1;
  }
  else
  {
    interchange=0;
  }
  
  float e = 2*dy - dx;
  for(int i=1;i<dx;i++)
  {     
      if(i%5==0){
    glVertex2i(x,y);
    }
      while(e>=0)
        {
          if(interchange=1)
          {
           x = x + s1;
        }
        else
        {
         y = y + s2;
        }
        e = e - 2*dx;
      }
      
      if(interchange=1)
      {
        y = y + s2;
      }
      else
      {
        x = x + s1;
      }
      e =e + 2*dy;
  }
     
  glEnd();
  glFlush();
   }
  
   void display( void){
     glClear(GL_COLOR_BUFFER_BIT);
    for(int i=-w;i<w;i++){
     
     setpixel(i,0);
      setpixel(0,i);
     }
  
       
     glEnd();
     glFlush();
  }
  void object(int x1,int y1,int x2,int y2){
    glBegin(GL_POINTS);
    glColor3f(1.0,0.0,1.0);

    dx = abs(x2-x1);
    dy = abs(y2-y1);
    x=x1;
    y=y1;
    if((x2-x1)<0)
    {
      s1=-1;
  }
  else
  {
    s1=1;
  }
  
  if((y2-y1)<0)
  {
    s2=-1;
  }
  else
  {
    s2=1;
  } 
  
  if(dy>dx)
  {
    temp=dx;
    dx=dy;
    dy=temp;
    interchange=1;
  }
  else
  {
  
    interchange=0;
  }
  
  float e = 2*dy-dx;
  for(int i=1;i<dx;i++)
  {
    glVertex2i(x,y);
    
    
      while(e>=0)
        {
          if(interchange==1)
          {
           x = x + s1;
        }
        else
        {
         y = y + s2;
        }
        e = e - 2*dx;
      }
      
      if(interchange==1)
      {
        y = y + s2;
      }
      else
      {
        x = x + s1;
      }
      e =e + 2*dy;
  }
     
  glEnd();
  glFlush();
  }
  
  void menu(int choice){

        if(choice==1){
               simple_line();
        }
        else if(choice==2)
        {
          dashed_line();
  }
  else if(choice==3)
  {
  dotted_line();
  }
  else if(choice==4){
     
      glColor3f(1.0,0.0,1.0);
        glFlush();
                object(50,0,50,250);
                object(50,0,300,0);
                object(300,0,300,250);
                object(300,250,50,250);
                  
                object(50,125,175,0); 
                object(175,0,300,125); 
                object(300,125,175,250);  
                object(175,250,50,125);  
                
              glColor3f(0.0,0.0,1.0);
               object(112.5,62.5,112.5,187.5); 
               object(112.5,187.5,237.5,187.5); 
               object(237.5,187.5,237.5,62.5); 
               object(237.5,62.5,112.5,62.5);
              
    
     }
  
}
int main(int a,char** b)
{

 
   
   glutInit(&a,b);
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
   glutInitWindowPosition(100,150);
   glutInitWindowSize(1000,1000);
   glutCreateWindow("niraj palmur");
      initGL();
   glutDisplayFunc(display);
      glutCreateMenu(menu);
        glutAddMenuEntry("Simple Line ",1);
        glutAddMenuEntry("Dashed Line",2);
        glutAddMenuEntry("Dotted Line",3);
        glutAddMenuEntry("House",4);
        
          glutAttachMenu(GLUT_RIGHT_BUTTON);
   glutMainLoop();
   
   return 0;
}