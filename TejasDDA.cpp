#include<iostream>
using namespace std;
#include<GL/freeglut.h>
#include<math.h>
#define h 500
#define w 500
 void initGL(void){
   
   glClearColor(1.0f,1.0f,1.0f,0.0f);
       glLineWidth(5.0);
	glPointSize(8.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-w/2,w/2,-h/2,h/2);
 }
  void setpixel(int x,int y){
     glBegin(GL_POINTS);
      glColor3f(0.0f,0.0f,1.0f);
       glVertex2i(x,y);
     glEnd();
     
  }
  
  void line(){
  float x1,y1,x2,y2;
     cout<<"\t\t input parameter for simple line\n";
  cout<<"enter first coordinate for simple line=";
  cin>>x1>>y1;
  cout<<endl;
  
  cout<<"enter second coordinate for simple line=";
  cin>>x2>>y2;
   cout<<"\n";
  
  
    float length,dx,dy,xin,yin,x,y;
    dx=x2-x1;
    dy=y2-y1;
    
    if(dx>dy){
      length=dx;
    }
    else{
       length=dy;
    }
    
    xin=dx/length;
    yin=dy/length;
    
    x=x1;
    y=y1;
       glBegin(GL_POINTS);  
           glColor3f(1.0f,0.0f,0.0f);
    for(int i=0;i<=length;i++){
      x=x+xin;
      y=y+yin; 
      glVertex2i(x,y);      
  }
  glEnd();
  }
  
   void dash_line(){
   float x1,y1,x2,y2;
     cout<<"\t\t input parameter for dash line\n";
  cout<<"enter first coordinate for dash line=";
  cin>>x1>>y1;
  cout<<endl;
  
  cout<<"enter second coordinate for dash line=";
  cin>>x2>>y2;
  cout<<"\n";
  
    float length,dx,dy,xin,yin,x,y;
    dx=(x2-x1);
    dy=(y2-y1);
    
    if(dx>dy){
      length=dx;
    }
    else{
       length=dy;
    }
    
    xin=dx/length;
    yin=dy/length;
    
    x=x1;
    y=y1;
       glBegin(GL_POINTS);  
           glColor3f(1.0f,0.0f,1.0f);
    for(int i=0;i<=length;i++){
      x=x+xin;
      y=y+yin; 
      if(i%10>=5){
      glVertex2i(x,y);
      }      
  }
  glEnd();
  }
  
  
   void dotted_line(){
  float x1,y1,x2,y2;
     cout<<"\t\t input parameter for dotted line\n";
  cout<<"enter first coordinate for dotted line=";
  cin>>x1>>y1;
  cout<<endl;
  
  cout<<"enter second coordinate for dotted line=";
  cin>>x2>>y2;
   cout<<"\n";
  
  
    float length,dx,dy,xin,yin,x,y;
    dx=x2-x1;
    dy=y2-y1;
    
    if(dx>dy){
      length=dx;
    }
    else{
       length=dy;
    }
    
    xin=dx/length;
    yin=dy/length;
    
    x=x1;
    y=y1;
       glBegin(GL_POINTS);  
           glColor3f(1.0f,0.0f,0.5f);
    for(int i=0;i<=length;i++){
      x=x+xin;
      y=y+yin; 
      if(i%6==0){
      glVertex2i(x,y);
      }      
  }
  glEnd();
  }
  
  
  void object(float x1,float y1,float x2,float y2){ 
    float length,dx,dy,xin,yin,x,y;
    dx=(x2-x1);
    dy=(y2-y1);
    
    if(dx>dy){
      length=dx;
    }
    else{
       length=dy;
    }
    
    xin=dx/length;
    yin=dy/length;
    
    x=x1;
    y=y1;
       glBegin(GL_POINTS);  
           glColor3f(0.0f,1.0f,1.0f);
    for(int i=0;i<=length;i++){
      x=x+xin;
      y=y+yin; 
      glVertex2i(x,y);      
  }
  glEnd();
  }
  
 
 void display(void){
 
   glClear(GL_COLOR_BUFFER_BIT);
  for(int i=-w;i<w;i++){
     setpixel(i,0);
        setpixel(0,i);
  }  
	glEnd();
	glFlush();
  
 }

 
   void menu(int t){
     if(t==1)
     {
         line();
     }
     else if(t==2){
        dash_line();
     
     }
      else if(t==3){
           dotted_line();
      }
     else if(t==4){
       
          
     object(100,-100,100,-50);
     // object(100,-50,130,-100);
     // object(50,-100,200,-100);
     // object(50,-100,100,-150);
      // object(100,-150,160,-150);
     // object(160,-150,200,-100);
    
     
     }
     
     else if(t==5){
         object(200,0,200,100);
         object(100,0,100,100);
         object(100,0,200,0);
         object(100,100,200,100);  
         
         object(100,100,150,200); 
         object(200,100,150,200); 
         
            object(130,0,130,75);
            object(160,0,160,75);
             object(130,75,160,75);
     }
     else if (t==5){
         
         exit(0);
     }
      
     
    
   }

int main( int a,char** b){
   
   glutInit(&a,b);
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
   glutInitWindowPosition(100,150);
   glutInitWindowSize(1000,1000);
   glutCreateWindow("niraj palmur");
   glutDisplayFunc(display);
   glutCreateMenu(menu);
     glutAddMenuEntry("SIMPLE LINE",1);
     glutAddMenuEntry("DASH LINE",2);
     glutAddMenuEntry("DOTTED LINE",3);
     glutAddMenuEntry("BOAT",4);
        glutAddMenuEntry("home",5);
     glutAddMenuEntry("EXIT",6);
     glutAttachMenu(GLUT_RIGHT_BUTTON);
    initGL();
    glutMainLoop();
    
    
  return 0;
}