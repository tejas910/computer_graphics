#include<iostream>
using namespace std;
#include<GL/freeglut.h>
#include<math.h>
#define h 1000
#define w 1000

 float a[3][3]={{0,100,200},{10,150,10},{1,1,1}};
 float p2[3][3];
 float tx,ty,sx,sy,shx,shy;
 double angle_rad, angle_rad1,angle_rad2;
void initGL(){
    
     glClearColor(1.0,1.0,1.0,0.0);
         glPointSize(3.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-w/2,w/2,-h/2,h/2);

}
 void setpixel(int x,int y){
   
    glBegin(GL_POINTS);
       glColor3f(1.0,0.0,0.0);
       glPointSize(8.0);	
     glVertex2i(x,y);
     glEnd();
     
 }
 
 
 void matrix_mul(float a1[3][3],float p1[3][3]){
 
 
 for(int i=0;i<3;i++){
   for(int j=0;j<3;j++){
       p2[i][j]=0.0f;
      for(int k=0;k<3;k++){
        p2[i][j]+=p1[i][k]*a1[k][j];
      }
   }
 }
 
 
 }
 
 void object(){
  
  glBegin(GL_POLYGON);
   glColor3f(0.0,1.0,0.0);
   glVertex2i(a[0][0],a[1][0]);
   glVertex2i(a[0][1],a[1][1]);
   glVertex2i(a[0][2],a[1][2]);
   
   glEnd();
   
      
 }
 
 void translation(float tx,float ty){
   
   float t[3][3]={{1,0,tx},{0,1,ty},{0,0,1}};
   matrix_mul(a,t);
   
   glBegin(GL_POLYGON);
      glColor3f(1.0,1.0,0.0);
   glVertex2i(p2[0][0],p2[1][0]);
   glVertex2i(p2[0][1],p2[1][1]);
   glVertex2i(p2[0][2],p2[1][2]);
   glEnd();
    
 glFlush();
 }
 
  void scaling(float sx,float sy){
  
   float s[3][3]={{sx,0,0},{0,sy,0},{0,0,1}};
   matrix_mul(a,s);
   
   glBegin(GL_POLYGON);
      glColor3f(1.0,0.0,0.0);
   glVertex2i(a[0][0],a[1][0]);
   glVertex2i(p2[0][1],p2[1][1]);
   glVertex2i(p2[0][2],p2[1][2]);
   glEnd();
    
 glFlush();

}
 
 void roation_anti(double angle_rad){
  
  float rot[3][3]={{cos(angle_rad),-sin(angle_rad),0},{sin(angle_rad),cos(angle_rad),0},{0,0,1}};
   matrix_mul(a,rot);
   
      glBegin(GL_POLYGON);
      glColor3f(1.0,0.0,1.0);
   glVertex2i(p2[0][0],p2[1][0]);
   glVertex2i(p2[0][1],p2[1][1]);
   glVertex2i(p2[0][2],p2[1][2]);
   glEnd();
    
 glFlush();
}


void roation_clock(double angle_rad1){
  
  float rot[3][3]={{cos(angle_rad1),sin(angle_rad1),0},{-sin(angle_rad1),cos(angle_rad1),0},{0,0,1}};
   matrix_mul(a,rot);
   
      glBegin(GL_POLYGON);
      glColor3f(0.0,1.0,1.0);
   glVertex2i(p2[0][0],p2[1][0]);
   glVertex2i(p2[0][1],p2[1][1]);
   glVertex2i(p2[0][2],p2[1][2]);
   glEnd();
    
 glFlush();
}

 void roatate_about_pivot(double angle_rad2){
  
   float rot[3][3]={{cos(angle_rad2),-sin(angle_rad2),0},{sin(angle_rad2),cos(angle_rad2),0},{0,0,1}};
   float t1[3][3]={{1,0,-150},{0,1,-150},{0,0,1}};
    float t[3][3]={{1,0,150},{0,1,150},{0,0,1}};
 
   float p1[3][3];
        for(int i=0;i<3;i++){
   for(int j=0;j<3;j++){
       p1[i][j]=0.0f;
      for(int k=0;k<3;k++){
        p1[i][j]+=t1[i][k]*rot[k][j];
      }
   }
 }
   
    float a1[3][3];
    
     for(int i=0;i<3;i++){
   for(int j=0;j<3;j++){
       a1[i][j]=0.0f;
      for(int k=0;k<3;k++){
        a1[i][j]+=p1[i][k]*t[k][j];
      }
   }
 }
   float z[3][3];
   for(int i=0;i<3;i++){
   for(int j=0;j<3;j++){
       z[i][j]=0.0f;
      for(int k=0;k<3;k++){
        z[i][j]+=a1[i][k]*a[k][j];
      }
   }
 }
 
      glBegin(GL_POLYGON);
      glColor3f(0.0,0.0,1.0);
   glVertex2i(z[0][0],z[1][0]);
   glVertex2i(z[0][1],z[1][1]);
   glVertex2i(z[0][2],z[1][2]);
   glEnd();
    
 glFlush();
    
 
 }

void reflection_x_axis(){

  float r_x[3][3]={{1,0,0},{0,-1,0},{0,0,1}};
  matrix_mul(a,r_x);
  
       glBegin(GL_POLYGON);
      glColor3f(0.0,0.0,1.0);
   glVertex2i(p2[0][0],p2[1][0]);
   glVertex2i(p2[0][1],p2[1][1]);
   glVertex2i(p2[0][2],p2[1][2]);
   glEnd();
    
 glFlush();
}



 void reflection_y_axis(){

  float r_y[3][3]={{-1,0,0},{0,1,0},{0,0,1}};
  matrix_mul(a,r_y);
  
       glBegin(GL_POLYGON);
      glColor3f(0.0,1.0,1.0);
   glVertex2i(p2[0][0],p2[1][0]);
   glVertex2i(p2[0][1],p2[1][1]);
   glVertex2i(p2[0][2],p2[1][2]);
   glEnd();
    
 glFlush();
}

 void reflection_xy_axis(){

  float r_xy[3][3]={{-1,0,0},{0,-1,0},{0,0,1}};
  matrix_mul(a,r_xy);
  
       glBegin(GL_POLYGON);
      glColor3f(0.0,0.0,1.0);
   glVertex2i(p2[0][0],p2[1][0]);
   glVertex2i(p2[0][1],p2[1][1]);
   glVertex2i(p2[0][2],p2[1][2]);
   glEnd();
    
 glFlush();
}

void shar_x(float shx){
  
  float sh[3][3]={{1,shx,0},{0,1,0},{0,0,1}};
   matrix_mul(a,sh);
   
      glBegin(GL_POLYGON);
      glColor3f(0.0,0.0,0.0);
   glVertex2i(a[0][0],a[1][0]);
   glVertex2i(p2[0][1],p2[1][1]);
   glVertex2i(p2[0][2],p2[1][2]);
   glEnd();
    
 glFlush();

}

 void shar_y(float shy){
     
   
     float sh[3][3]={{1,0,0},{shy,1,0},{0,0,1}};
   matrix_mul(a,sh);
   
      glBegin(GL_POLYGON);
      glColor3f(0.0,0.0,0.0);
   glVertex2i(a[0][0],a[1][0]);
   glVertex2i(p2[0][1],p2[1][1]);
   glVertex2i(p2[0][2],p2[1][2]);
   glEnd();
    
 glFlush();

  }
  void menu(int choice){

        if(choice==1){
          object();
        }
        else if(choice==2)
        {  
           object();
           translation(tx,ty);
	}
	else if(choice==3)
	{
	   object();
           scaling(sx,sy);
	}
	else if(choice==4)
	{
	    object();
          roation_anti(angle_rad);
	}
	
        else if(choice==5)
	{
	    object();
          roation_clock(angle_rad1);
	}
	
	  else if(choice==6)
	{
	    object();
           reflection_x_axis();
	}
	
       else if(choice==7)
	{
	    object();
           reflection_y_axis();
	}
	
	  else if(choice==8)
	{
	    object();
           reflection_xy_axis();
	}
	
	  else if(choice==9)
	{
	    object();
           shar_x(shx);
	}
	
	  else if(choice==10)
	{
	    object();
            shar_y(shy);
	}
	
	  else if(choice==11)
	{
	    object();
            roatate_about_pivot(angle_rad2);
	}
}
void display(){
   
   
        glClear(GL_COLOR_BUFFER_BIT);
    for(int i=-w;i<w;i++){
     
     setpixel(i,0);
      setpixel(0,i);
     }
     
     
      glEnd();
     glFlush();

}



int main(int a,char** b){
 
 
    cout<<"\t\tinput parameter"<<"\n";
      cout<<"enter the valur of tx=";
      cin>>tx;
      cout<<endl<<endl;
      
      cout<<"enter the valur of ty=";
      cin>>ty;
      cout<<endl<<endl;
      
      
        cout<<"enter the valur of sx=";
      cin>>sx;
      cout<<endl<<endl;
      
      cout<<"enter the valur of sy=";
      cin>>sy;
      cout<<endl<<endl;
      
      cout<<"enter the value anti_clockwice rotation(radian)=";
      cin>>angle_rad;
      cout<<endl<<endl;
      
      cout<<"enter the value  rotation about pivote point(radian)=";
      cin>>angle_rad2;
      cout<<endl<<endl;
      
      cout<<"enter the value clockwice rotation(radian)=";
      cin>>angle_rad1;
      cout<<endl<<endl;
      
      
        cout<<"enter the valur of shx=";
      cin>>shx;
      cout<<endl<<endl;
      
      cout<<"enter the valur of shy=";
      cin>>shy;
      cout<<endl<<endl;
      
      
    glutInit(&a,b);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100,150);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("niraj palmur");
    glutDisplayFunc(display);
      glutCreateMenu(menu);
        glutAddMenuEntry("object",1);
    glutAddMenuEntry("translation",2);
    glutAddMenuEntry("scaling",3);
    glutAddMenuEntry("anti_clockwice_roation",4);
    glutAddMenuEntry("clockwice_roation",5);
    glutAddMenuEntry("reflection_x_axis",6);
    glutAddMenuEntry("reflection_y_axis",7);
    glutAddMenuEntry("reflection_xy_axis",8);
    glutAddMenuEntry("shar_x_axis",9);
    glutAddMenuEntry("shar_y_axis",10);
       glutAddMenuEntry("r_pivote_point",11);
          glutAttachMenu(GLUT_RIGHT_BUTTON);
    initGL();
    glutMainLoop();
    	
 
  return 0;
}