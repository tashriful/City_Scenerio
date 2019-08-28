#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
void updateCar(int);

void drawRain();
void drawSnow();
void drawHail();

float cloud1=-20.0,cloud2=30.0;
float suny=-2.0,ts=20.0,tc=-60.0,tc2=-5.0,tc3=35.0;
float speed = 0.0f;

//--------Day and Night view---------
float skr=0.10,skg=0.53,skb=0.84;
float skr2=0.50,skg2=0.93,skb2=0.94;
float sc=0;
float snr=0.93,sng=0.72,snb=0.07;
float rvg=0.75,rvg2=.87;
float moon=0.0;
float st=-1000,st2=-1000,st3=-1000,st4=-1000,st5=-1000,st2y=-10;
float shr=0,shg=0;
float vlgr=.49,vlgg=.86,vlgb=.35;
//------------*******--------------

char text[] = "STORE";
char text2[] = "SALON";
char text3[] = "40 KM/H";
char text4[] = "d - DAy || n- Night || r- Rain || s- Snow || h- haill || right key - speed increase || left key - decrease";
void ship();
void cloud();
void mount();
void car();
void bus();
void star();
void triangle2();
void tree1();
void Sprint();
void backSide();
void frontSide(int i);

///////////////////////////

//rain code start
#define MAX_PARTICLES 1000

#define RAIN	0
#define SNOW	1
#define	HAIL	2


float slowdown = 2.0;
float velocity = 0.0;
float zoom = -30.0;
float pan = 0.0;
float tilt = 0.0;
float hailsize = 0.1;

int loop;
int fall = 10;

//floor colors
float r = 0.0;
float g = 1.0;
float b = 0.0;
float ground_points[21][21][3];
float ground_colors[21][21][4];
float accum = -10.0;

typedef struct {
  // Life
  bool alive;	// is the particle alive?
  float life;	// particle lifespan
  float fade; // decay
  // color
  float red;
  float green;
  float blue;
  // Position/direction
  float xpos;
  float ypos;
  float zpos;
  // Velocity/Direction, only goes down in y dir
  float vel;
  // Gravity
  float gravity;
}particles;

// Paticle System
particles par_sys[MAX_PARTICLES];

//rain code end


void Sprint( float x, float y, char *st)
{
    int l,i;


    l=strlen( st ); // see how many characters are in text string.
    glColor3f(0.0,0.0,0.7);
    glRasterPos2f(-25.0,2.5); // location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);

    }
}

void Sprint2( float x, float y, char *st)
{
    int l,i;


    l=strlen( st ); // see how many characters are in text string.

    glColor3f(0.0,0.0,0.7);
    glRasterPos2f(-26.0,2.5);// location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);

    }
}

void Sprint3( float x, float y, char *st)
{
    int l,i;


    l=strlen( st ); // see how many characters are in text string.

    glColor3f(1,1,1);
    glRasterPos2f(-10.0,-7);// location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);

    }
}

void Sprint4( float x, float y, char *st)
{
    int l,i;


    l=strlen( st ); // see how many characters are in text string.

    glColor3f(1.4,1.4,1.7);
    glRasterPos2f(-40.0,-23);// location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);

    }
}


void triangle2(void)  //For Jhau Tree
    {
        glColor3f (0.15,0.30,0.14);
        glBegin(GL_POLYGON);

        glVertex3f (0.0, 0.0, 0.0);
        glVertex3f (9.0, 13.0, 0.0);
        glVertex3f (18.0, 0.0, 0.0);

        glEnd();
    }

void star()
    {
           //star
        glColor3f(1, 1, 1);
        glBegin(GL_TRIANGLES);
        glVertex2f(-44.5, 23.3);
        glVertex2f(-44.0, 22.5);
        glVertex2f(-45.0, 22.5);
        glVertex2f(-44.5, 22.2);
        glVertex2f(-44.0, 23.0);
        glVertex2f(-45.0, 23.0);
        glEnd();
    }



void tree1()
    {
        glPushMatrix();
        glTranslatef(-40.0,-23.0,-0);
        glScalef(.4,.4,0);
        triangle2();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-40.0,-21.5,0);
        glScalef(.4,.4,0);
        triangle2();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-40.0,-20.0,0);
        glScalef(.4,.4,0);
        triangle2();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(7,26,0);
        glScalef(.5,.5,0);
        triangle2();
        glPopMatrix();

        //Tree Body(Gora)
        glPushMatrix();
        glBegin(GL_POLYGON);
        glColor3f(0.36,0.25,0.20);
        glVertex2f (-37.5,-23.0);
        glVertex2f (-35.5,-23.0);
        glVertex2f (-35.5,-25.0);
        glVertex2f (-37.5,-25.0);

        glEnd();
        glPopMatrix();
    }






void car()
    {
        glPushMatrix();
        glColor3f(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex2f(10.0,-5.5);
        glVertex2f(14.0,-2.0);
        glVertex2f(22.0,-2.0);
        glVertex2f(25.5,-5.25);
        glVertex2f(29.0,-6.5);
        glVertex2f(29.0,-8.5);
        glVertex2f(10.0,-8.5);
        glEnd();
        glPopMatrix();
        //Window
        glPushMatrix();
        glColor3f(0.75, 0.75, 0.75);
        glBegin(GL_POLYGON);
        glVertex2f(12.0,-5.5);
        glVertex2f(15.0,-2.5);
        glVertex2f(18.0,-2.5);
        glVertex2f(18.0,-5.5);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.75, 0.75, 0.75);
        glBegin(GL_POLYGON);
        glVertex2f(18.5,-2.5);
        glVertex2f(18.5,-5.5);
        glVertex2f(24.5,-5.5);
        glVertex2f(21.5,-2.5);
        glEnd();
        glPopMatrix();
        //Light
        glPushMatrix();
        glColor3f(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2f(29.0,-7.2);
        glVertex2f(29.5,-7.2);
        glVertex2f(29.5,-8.0);
        glVertex2f(29.0,-8.0);
        glEnd();
        glPopMatrix();
        //Handle
        glPushMatrix();
        glColor3f(0, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2f(19.0,-6.7);
        glVertex2f(20.8,-6.7);
        glVertex2f(20.8,-6.11);
        glVertex2f(19.0,-6.11);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3f(0, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2f(12.0,-6.7);
        glVertex2f(13.8,-6.7);
        glVertex2f(13.8,-6.11);
        glVertex2f(12.0,-6.11);
        glEnd();
        glPopMatrix();

        //Tyre(Chaka)
         glPushMatrix();
         glTranslatef(14.0,-9,0.0);
         glColor3f(0.75, 0.75, 0.75);
            glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=1.5;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );

            }
         glEnd();
         glPopMatrix();
            //Front
         glPushMatrix();
         glTranslatef(24.0,-9,0.0);
         glColor3f(0.75, 0.75, 0.75);
            glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=1.5;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );

            }
          glEnd();
          glPopMatrix();
    }

void bus()
    {
        glPushMatrix();
        glColor3f(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2f(15.0,-1.0);
        glVertex2f(30.0,-1.0);
        glColor3f(1, 1, 0);
        glVertex2f(30.0,-8.0);
        glVertex2f(15.0,-8.0);
        glEnd();
        glPopMatrix();
        //Glass
        glPushMatrix();
        glColor3f(0.75, 0.75, 0.75);
        glBegin(GL_POLYGON);
        glVertex2f(18.0,-3.0);
        glVertex2f(22.0,-3.0);
        glVertex2f(22.0,-5.0);
        glVertex2f(18.0,-5.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.75, 0.75, 0.75);
        glBegin(GL_POLYGON);
        glVertex2f(24.0,-3.0);
        glVertex2f(28.0,-3.0);
        glVertex2f(28.0,-5.0);
        glVertex2f(24.0,-5.0);
        glEnd();
        glPopMatrix();
        //Door
        glPushMatrix();
        glColor3f(1, 1, 1);
        glBegin(GL_POLYGON);
        glVertex2f(16.0,-5.0);
        glVertex2f(18.0,-5.0);
        glVertex2f(18.0,-8.0);
        glVertex2f(16.0,-8.0);
        glEnd();
        glPopMatrix();
        //Tyre(Chaka)
         glPushMatrix();
         glTranslatef(20.0,-8,0.0);
         glColor3f(0.75, 0.75, 0.75);
         glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=1.7;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );

            }
          glEnd();
          glPopMatrix();
        //Rear
         glPushMatrix();
         glTranslatef(28.0,-8,0.0);
         glColor3f(0.75, 0.75, 0.75);
         glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=1.7;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );

            }
         glEnd();
         glPopMatrix();
    }


        void ship()
    {
        glPushMatrix();
        glColor3f(0.4,0.7, 0.6);
        glBegin(GL_POLYGON);
        glVertex2f(0.0,51.0);
        glVertex2f(-20.0,65.0);
        glVertex2f(40.0,65.0);
        glVertex2f(20.0,51.0);
        glEnd();

        glColor3f(0.5,0.7, 0);
        glBegin(GL_POLYGON);
        glVertex2f(5.0,65.0);
        glVertex2f(5.0,79.0);
        glVertex2f(20.0,79.0);
        glVertex2f(20.0,65.0);
        glEnd();

        glPopMatrix();
    }


void cloud()
    {

         glPushMatrix();
         glTranslatef(-10.0,12.0,0.0 ); // ..............total translate cloud
         glScalef(2.0,0.7,0.0);
         //glColor3f(1.0, 1.0, 1.0);
            glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=3.0;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );

            }
         glEnd();
         glPopMatrix();

         glPushMatrix();
         glTranslatef(-6.0,14.0,0.0);
         glScalef(2.0,0.8,0.0);
            glBegin(GL_POLYGON);

            for(int i=0;i<60;i++) //Move cloud
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=3.0;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );

            }
         glEnd();
         glPopMatrix();

         glPushMatrix();
         glTranslatef(-0.0,14.0,0.0);
         glScalef(1.5,0.8,0.0);
            glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=3.0;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );

            }
         glEnd();
         glPopMatrix();

         glPushMatrix();
         glTranslatef(-7.0,12.0,0.0);
         glScalef(1.8,0.9,0.0);
            glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=3.0;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );

            }
            glEnd();
            glPopMatrix();
    }


void frontSide(int x) //Road,Tree and house
    {



        glColor3f(vlgr, vlgg, vlgb);
        glBegin(GL_POLYGON);
        glVertex2f(50.0,1.0);
        glColor3f (0.25, 0.25, 0.25);  //footpath
        glVertex2f(-50.0,4.0);
        glVertex2f(-50.0,-4.0);
        glVertex2f(50.5,-4.0);
        glEnd();

        glColor3f(vlgr, vlgg, vlgb);
        glBegin(GL_POLYGON);
        glVertex2f(50.0,1.0);
        glColor3f (0.5, 0.2, 0.0);  //river side
        glVertex2f(-50.0,4.0);
        glVertex2f(-50.0,-1.5);
        glVertex2f(50.5,-1.5);
        glEnd();

        glColor3f(vlgr, vlgg, vlgb);
        glBegin(GL_POLYGON);
        glVertex2f(50.0,-3.5);
        glColor3f (0.5, 0.2, 0.4);  //footpath border
        glVertex2f(-50.0,-3.5);
        glVertex2f(-50.0,-4);
        glVertex2f(50.5,-4);
        glEnd();

    //building
    glPushMatrix();
    //glTranslatef(5.0, -10.0, 0.0);
    glColor3f(0.25, 0.0, 0.0);

    glBegin(GL_POLYGON);
    glVertex3f(-50.0, -2.0, 0.0);
    glVertex3f(-50, 12.0, 0.0);
    glVertex3f(-40.0, 12.0, 0.0);
    glVertex3f(-40.0, -2.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 0.0, 0.0);
    glVertex3f(-50, 1.0, 0.0);          //line 1
    glVertex3f(-40.0, 1.0, 0.0);
    glVertex3f(-40.0, 0.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 3.0, 0.0);
    glVertex3f(-50, 4.0, 0.0);
    glVertex3f(-40.0, 4.0, 0.0);        //line 2
    glVertex3f(-40.0, 3.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 6.0, 0.0);  //line 3
    glVertex3f(-50, 7.0, 0.0);
    glVertex3f(-40.0, 7.0, 0.0);
    glVertex3f(-40.0, 6.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 9.0, 0.0);
    glVertex3f(-50, 10.0, 0.0);            //line 4
    glVertex3f(-40.0, 10.0, 0.0);
    glVertex3f(-40.0, 9.0, 0.0);
    glEnd();

    glPushMatrix();
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 1,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(6.0, 0.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 1,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -3.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 2,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0, -3, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 2,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -6.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 3,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0, -6, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 3,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -9.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 4,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0, -9, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 4,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.5, -12.5, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 12.5, 0.0);            //door
    glVertex3f(-48.0, 12.5, 0.0);
    glVertex3f(-48.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPopMatrix();

    //building 2
    glPushMatrix();
    glTranslatef(12.0, -0.0, 0.0);
    glColor3f(0.25, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-50.0, -2.0, 0.0);
    glVertex3f(-50, 12.0, 0.0);
    glVertex3f(-40.0, 12.0, 0.0);
    glVertex3f(-40.0, -2.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 0.0, 0.0);
    glVertex3f(-50, 1.0, 0.0);          //line 1
    glVertex3f(-40.0, 1.0, 0.0);
    glVertex3f(-40.0, 0.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 3.0, 0.0);
    glVertex3f(-50, 4.0, 0.0);
    glVertex3f(-40.0, 4.0, 0.0);        //line 2
    glVertex3f(-40.0, 3.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 6.0, 0.0);  //line 3
    glVertex3f(-50, 7.0, 0.0);
    glVertex3f(-40.0, 7.0, 0.0);
    glVertex3f(-40.0, 6.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 9.0, 0.0);
    glVertex3f(-50, 10.0, 0.0);            //line 4
    glVertex3f(-40.0, 10.0, 0.0);
    glVertex3f(-40.0, 9.0, 0.0);
    glEnd();

    glPushMatrix();
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 1,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(6.0, 0.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 1,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -3.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 2,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0, -3, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 2,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -6.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 3,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0, -6, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 3,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -9.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 4,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0, -9, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 4,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.5, -12.5, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 12.5, 0.0);            //door
    glVertex3f(-48.0, 12.5, 0.0);
    glVertex3f(-48.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();
    glPopMatrix();


    //small building

    glPushMatrix();
    //glTranslatef(3.5, -12.5, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-18.5, -2, 0.0);
    glVertex3f(-18.5, 2, 0.0);            //body
    glVertex3f(-27.5, 2, 0.0);
    glVertex3f(-27.5, -2, 0.0);
    glEnd();

    glColor3f(0.25, 0.5, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-18.5, 2, 0.0);
    glVertex3f(-18.5, 4, 0.0);            //body upper
    glVertex3f(-27.5, 4, 0.0);
    glVertex3f(-27.5, 2, 0.0);
    glEnd();
    Sprint(.7,0,text);
    glPopMatrix();

    glColor3f(0.25, 0.5, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-19, -2, 0.0);
    glVertex3f(-19, 0, 0.0);            //door
    glVertex3f(-20.5, 0, 0.0);
    glVertex3f(-20.5, -2, 0.0);
    glEnd();

    glColor3f(0.25, 0.5, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-27, -1.5, 0.0);
    glVertex3f(-27, 1.5, 0.0);            //glass
    glVertex3f(-22, 1.5, 0.0);
    glVertex3f(-22, -1.5, 0.0);
    glEnd();
    glPopMatrix();

     //building 3
    glPushMatrix();
    glTranslatef(32.0, -0.0, 0.0);
    glColor3f(0.25, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-50.0, -2.0, 0.0);
    glVertex3f(-50, 12.0, 0.0);
    glVertex3f(-40.0, 12.0, 0.0);
    glVertex3f(-40.0, -2.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 0.0, 0.0);
    glVertex3f(-50, 1.0, 0.0);          //line 1
    glVertex3f(-40.0, 1.0, 0.0);
    glVertex3f(-40.0, 0.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 3.0, 0.0);
    glVertex3f(-50, 4.0, 0.0);
    glVertex3f(-40.0, 4.0, 0.0);        //line 2
    glVertex3f(-40.0, 3.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 6.0, 0.0);  //line 3
    glVertex3f(-50, 7.0, 0.0);
    glVertex3f(-40.0, 7.0, 0.0);
    glVertex3f(-40.0, 6.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 9.0, 0.0);
    glVertex3f(-50, 10.0, 0.0);            //line 4
    glVertex3f(-40.0, 10.0, 0.0);
    glVertex3f(-40.0, 9.0, 0.0);
    glEnd();

    glPushMatrix();
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 1,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(6.0, 0.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 1,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -3.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 2,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0, -3, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 2,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -6.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 3,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0, -6, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 3,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -9.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 4,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0, -9, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 4,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.5, -12.5, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 12.5, 0.0);            //door
    glVertex3f(-48.0, 12.5, 0.0);
    glVertex3f(-48.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();
    glPopMatrix();


     //building 4
    glPushMatrix();
    glTranslatef(44.0, -0.0, 0.0);
    glColor3f(0.25, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-50.0, -2.0, 0.0);
    glVertex3f(-50, 12.0, 0.0);
    glVertex3f(-40.0, 12.0, 0.0);
    glVertex3f(-40.0, -2.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 0.0, 0.0);
    glVertex3f(-50, 1.0, 0.0);          //line 1
    glVertex3f(-40.0, 1.0, 0.0);
    glVertex3f(-40.0, 0.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 3.0, 0.0);
    glVertex3f(-50, 4.0, 0.0);
    glVertex3f(-40.0, 4.0, 0.0);        //line 2
    glVertex3f(-40.0, 3.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 6.0, 0.0);  //line 3
    glVertex3f(-50, 7.0, 0.0);
    glVertex3f(-40.0, 7.0, 0.0);
    glVertex3f(-40.0, 6.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 9.0, 0.0);
    glVertex3f(-50, 10.0, 0.0);            //line 4
    glVertex3f(-40.0, 10.0, 0.0);
    glVertex3f(-40.0, 9.0, 0.0);
    glEnd();

    glPushMatrix();
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 1,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(6.0, 0.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 1,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -3.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 2,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0, -3, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 2,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -6.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 3,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0, -6, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 3,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -9.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 4,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0, -9, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 4,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.5, -12.5, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 12.5, 0.0);            //door
    glVertex3f(-48.0, 12.5, 0.0);
    glVertex3f(-48.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();
    glPopMatrix();




//building 5
    glPushMatrix();
    glTranslatef(56.0, -0.0, 0.0);
    glColor3f(0.25, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-50.0, -2.0, 0.0);
    glVertex3f(-50, 12.0, 0.0);
    glVertex3f(-40.0, 12.0, 0.0);
    glVertex3f(-40.0, -2.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 0.0, 0.0);
    glVertex3f(-50, 1.0, 0.0);          //line 1
    glVertex3f(-40.0, 1.0, 0.0);
    glVertex3f(-40.0, 0.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 3.0, 0.0);
    glVertex3f(-50, 4.0, 0.0);
    glVertex3f(-40.0, 4.0, 0.0);        //line 2
    glVertex3f(-40.0, 3.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 6.0, 0.0);  //line 3
    glVertex3f(-50, 7.0, 0.0);
    glVertex3f(-40.0, 7.0, 0.0);
    glVertex3f(-40.0, 6.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 9.0, 0.0);
    glVertex3f(-50, 10.0, 0.0);            //line 4
    glVertex3f(-40.0, 10.0, 0.0);
    glVertex3f(-40.0, 9.0, 0.0);
    glEnd();

    glPushMatrix();
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 1,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(6.0, 0.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 1,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -3.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 2,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0, -3, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 2,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -6.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 3,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0, -6, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 3,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -9.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 4,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0, -9, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 4,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.5, -12.5, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 12.5, 0.0);            //door
    glVertex3f(-48.0, 12.5, 0.0);
    glVertex3f(-48.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();
    glPopMatrix();


    //small building 2

    glPushMatrix();
    glTranslatef(44,0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-18.5, -2, 0.0);
    glVertex3f(-18.5, 2, 0.0);            //body
    glVertex3f(-27.5, 2, 0.0);
    glVertex3f(-27.5, -2, 0.0);
    glEnd();

    glColor3f(0.25, 0.5, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-18.5, 2, 0.0);
    glVertex3f(-18.5, 4, 0.0);            //body upper
    glVertex3f(-27.5, 4, 0.0);
    glVertex3f(-27.5, 2, 0.0);
    glEnd();
    Sprint2(.7,0,text2);


    glColor3f(0.25, 0.5, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-19, -2, 0.0);
    glVertex3f(-19, 0, 0.0);            //door
    glVertex3f(-20.5, 0, 0.0);
    glVertex3f(-20.5, -2, 0.0);
    glEnd();

    glColor3f(0.25, 0.5, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-27, -1.5, 0.0);
    glVertex3f(-27, 1.5, 0.0);            //glass
    glVertex3f(-22, 1.5, 0.0);
    glVertex3f(-22, -1.5, 0.0);
    glEnd();
    glPopMatrix();



    //building 6
    glPushMatrix();
    glTranslatef(76.0, -0.0, 0.0);
    glColor3f(0.25, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-50.0, -2.0, 0.0);
    glVertex3f(-50, 12.0, 0.0);
    glVertex3f(-40.0, 12.0, 0.0);
    glVertex3f(-40.0, -2.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 0.0, 0.0);
    glVertex3f(-50, 1.0, 0.0);          //line 1
    glVertex3f(-40.0, 1.0, 0.0);
    glVertex3f(-40.0, 0.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 3.0, 0.0);
    glVertex3f(-50, 4.0, 0.0);
    glVertex3f(-40.0, 4.0, 0.0);        //line 2
    glVertex3f(-40.0, 3.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 6.0, 0.0);  //line 3
    glVertex3f(-50, 7.0, 0.0);
    glVertex3f(-40.0, 7.0, 0.0);
    glVertex3f(-40.0, 6.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 9.0, 0.0);
    glVertex3f(-50, 10.0, 0.0);            //line 4
    glVertex3f(-40.0, 10.0, 0.0);
    glVertex3f(-40.0, 9.0, 0.0);
    glEnd();

    glPushMatrix();
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 1,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(6.0, 0.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 1,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -3.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 2,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0, -3, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 2,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -6.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 3,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0, -6, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 3,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -9.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 4,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0, -9, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 4,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.5, -12.5, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 12.5, 0.0);            //door
    glVertex3f(-48.0, 12.5, 0.0);
    glVertex3f(-48.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();
    glPopMatrix();



    //building 7
    glPushMatrix();
    glTranslatef(88.0, -0.0, 0.0);
    glColor3f(0.25, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-50.0, -2.0, 0.0);
    glVertex3f(-50, 12.0, 0.0);
    glVertex3f(-40.0, 12.0, 0.0);
    glVertex3f(-40.0, -2.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 0.0, 0.0);
    glVertex3f(-50, 1.0, 0.0);          //line 1
    glVertex3f(-40.0, 1.0, 0.0);
    glVertex3f(-40.0, 0.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 3.0, 0.0);
    glVertex3f(-50, 4.0, 0.0);
    glVertex3f(-40.0, 4.0, 0.0);        //line 2
    glVertex3f(-40.0, 3.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 6.0, 0.0);  //line 3
    glVertex3f(-50, 7.0, 0.0);
    glVertex3f(-40.0, 7.0, 0.0);
    glVertex3f(-40.0, 6.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.2, 0.0);
    glVertex3f(-50.0, 9.0, 0.0);
    glVertex3f(-50, 10.0, 0.0);            //line 4
    glVertex3f(-40.0, 10.0, 0.0);
    glVertex3f(-40.0, 9.0, 0.0);
    glEnd();

    glPushMatrix();
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 1,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(6.0, 0.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 1,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -3.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 2,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0, -3, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 2,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -6.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 3,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0, -6, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 3,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -9.0, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 4,1
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0, -9, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 11.5, 0.0);            //window 4,2
    glVertex3f(-47.0, 11.5, 0.0);
    glVertex3f(-47.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.5, -12.5, 0.0);
    glColor3f(0.25, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-49.5, 10.5, 0.0);
    glVertex3f(-49.5, 12.5, 0.0);            //door
    glVertex3f(-48.0, 12.5, 0.0);
    glVertex3f(-48.0, 10.5, 0.0);
    glEnd();
    glPopMatrix();
    glPopMatrix();




        //Road
        glPushMatrix();
        glColor3f(0, 0.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex2f(-50.0,-4.0);
        glVertex2f(-50.0,-13.0);
        glVertex2f(50.0,-13.0);
        glVertex2f(50.0,-4.0);
        glEnd();
        Sprint3(.7,0,text3);





        glPushMatrix();
        glColor3f(0.1, 0.3, 0.2);
        glBegin(GL_POLYGON);
        glVertex2f(-50.0,-13.0);   //divider border
        glVertex2f(-50.0,-14.0);
        glVertex2f(50.0,-14.0);
        glVertex2f(50.0,-13.0);
        glEnd();


        glColor3f(0.7, 0.3, 0.2);
        glBegin(GL_POLYGON);
        glVertex2f(-50.0,-14.0);
        glVertex2f(-50.0,-16.0);   //divider
        glVertex2f(50.0,-16.0);
        glVertex2f(50.0,-14.0);
        glEnd();






        //white space
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex2f(-45.0,-8);
        glVertex2f(-45.0,-8.5);
        glVertex2f(-35.0,-8.5);
        glVertex2f(-35.0,-8);
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex2f(-25.0,-8.5);
        glVertex2f(-25.0,-9);
        glVertex2f(-15.0,-9);
        glVertex2f(-15.0,-8.5);
        glEnd();



        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex2f(-5.0,-8.5);
        glVertex2f(-5.0,-9);
        glVertex2f(5.0,-9);
        glVertex2f(5.0,-8.5);
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex2f(15.0,-8.5);
        glVertex2f(15.0,-9);
        glVertex2f(25.0,-9);
        glVertex2f(25.0,-8.5);
        glEnd();

         glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex2f(35.0,-8.5);
        glVertex2f(35.0,-9);
        glVertex2f(45.0,-9);
        glVertex2f(45.0,-8.5);
        glEnd();

        //white space 2nd road

         glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex2f(-45.0,-20.5);
        glVertex2f(-45.0,-21);
        glVertex2f(-35.0,-21);
        glVertex2f(-35.0,-20.5);
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex2f(-25.0,-20.5);
        glVertex2f(-25.0,-21);
        glVertex2f(-15.0,-21);
        glVertex2f(-15.0,-20.5);
        glEnd();



        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex2f(-5.0,-20.5);
        glVertex2f(-5.0,-21);
        glVertex2f(5.0,-21);
        glVertex2f(5.0,-20.5);
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex2f(15.0,-20.5);
        glVertex2f(15.0,-21);
        glVertex2f(25.0,-21);
        glVertex2f(25.0,-20.5);
        glEnd();

         glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex2f(35.0,-20.5);
        glVertex2f(35.0,-21);
        glVertex2f(45.0,-21);
        glVertex2f(45.0,-20.5);
        glEnd();

         //CAR
        glPushMatrix();
        glTranslatef(tc,tc2,0);
        glScalef(.6,.6,0);
        car();
        glPopMatrix();

         //divider trees
        glPushMatrix();
        glTranslatef(-20.0,5.0,0);
        glScalef(0.6,0.8,0);
        tree1();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-10.0,5.0,0);
        glScalef(0.6,0.8,0);
        tree1();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.0,5.0,0);
        glScalef(0.6,0.8,0);
        tree1();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(10.0,5.0,0);
        glScalef(0.6,0.8,0);
        tree1();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(20.0,5.0,0);
        glScalef(0.6,0.8,0);
        tree1();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(30.0,5.0,0);
        glScalef(0.6,0.8,0);
        tree1();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(40.0,5.0,0);
        glScalef(0.6,0.8,0);
        tree1();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(50.0,5.0,0);
        glScalef(0.6,0.8,0);
        tree1();
        glPopMatrix();


        //Rain
if(x==1){
    glPushMatrix();
        //glTranslatef(tc,tc2,0);
        glScalef(4.6,2.5,0);
        drawRain();
        glPopMatrix();
}else if(x==2){

glPushMatrix();
        //glTranslatef(tc,tc2,0);
        glScalef(4.6,2.5,0);
        drawHail();
        glPopMatrix();

}else if(x==3){
glPushMatrix();
        //glTranslatef(tc,tc2,0);
        glScalef(4.6,2.5,0);
        drawSnow();
        glPopMatrix();


}


        glPushMatrix();
        glTranslatef(60.0,5.0,0);
        glScalef(0.6,0.8,0);
        tree1();
        glPopMatrix();



        glPopMatrix();


        //Bus
        glPushMatrix();
        glTranslatef(tc3,-14.0,0);
        glScalef(.7,.7,0);
        bus();
        glPopMatrix();



    }


void backSide()  // hill,Sun and Ship
    {
         //sky
         glPushMatrix();
         glBegin(GL_POLYGON);
         glColor3f(skr, skg, skb);
         glVertex2f(-50.0,30.0);
         glVertex2f(50.0,30.0);
         glColor3f(skr2, skg2, skb2);
         glVertex2f(50.0,9.0);
         glVertex2f(-50.0,9.0);
         glEnd();
          Sprint4(.7,0,text4);
         glPopMatrix();

         //Star 1
        glPushMatrix();
        glTranslatef(st,0,0);
        glScalef(1,1,0);
        star();
        glPopMatrix();
           //Star 2
        glPushMatrix();
        glTranslatef(st2,st2y,0);
        glScalef(1,1,0);
        star();
        glPopMatrix();
           //Star 3
        glPushMatrix();
        glTranslatef(st3,0,0);
        glScalef(1,1,0);
        star();
        glPopMatrix();
           //Star 4
        glPushMatrix();
        glTranslatef(st4,0,0);
        glScalef(1,1,0);
        star();
        glPopMatrix();
           //Star 5
        glPushMatrix();
        glTranslatef(st5,0,0);
        glScalef(1,1,0);
        star();
        glPopMatrix();


          //Sun
         glPushMatrix();
         glTranslatef(10.0,suny,0.0);
         glColor3f(snr,sng,snb);
         glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=6.0;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,13+y );

            }
        glEnd();
        glPopMatrix();

         //Moon
         glPushMatrix();
         glTranslatef(-38.0,moon,0.0);
         glColor3f(1.0,1.0,1.0);
         glBegin(GL_POLYGON);
            for(int i=0;i<60;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/50;
                float r=4.0;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );

            }
        glEnd();
        glPopMatrix();


        //River
        glColor3f(0.07, rvg2, 0.93);
        glBegin(GL_POLYGON);
        glVertex2f(50.0,1.0);
        glVertex2f(-50.0,4.0);
        glVertex2f(-50.0,9.0);
        glColor3f(0.75,rvg, 0.0);
        glVertex2f(50.5,9.0);
        glEnd();

        //Cloud
        glPushMatrix();
        glColor3f(1.0, 1.0, 1.0);
        glTranslatef(cloud1,0.0,0.0);
        cloud();
        glPopMatrix();

        glPushMatrix();
        glColor3f(1.0, 1.0, 1.0);
        glTranslatef(cloud2,3.0,0.0);
        cloud();
        glPopMatrix();

        //Ship
        glPushMatrix();
        glTranslatef(ts,-2.0,0.0);
        glScalef(0.3,0.15,0.0);
        ship();
        glPopMatrix();



        glPopMatrix();

    }

void night()
    {
        skr=0;
        skg=0;
        skb=0;
        skr2=0.0;skg2=0.0;skb2=0.25;

        suny=15;
        sc=1;

        snr=1.0;sng=0.0;snb=0.0;

        rvg=0.04;rvg2=0.40;

        cloud1=2000.0;cloud2=2000.0;

        moon=30.0;

        st=0;st2=40;st3=50;st4=25;st5=65;

        shr=1;shg=0.9;

        vlgr=0;vlgg=.10;vlgb=0;
    }

void day()
    {
        skr=0.10;
        skg=0.53;
        skb=0.84;
        skr2=0.50;skg2=0.93;skb2=0.94;

        sc=0;

        snr=0.93;sng=0.72;snb=0.07;

        rvg=0.75;rvg2=0.87;

        cloud1=-20.0;cloud2=30.0;

        moon=0.0;

        st=-1000;st2=-1000;st3=-1000;st4=-1000;st5=-1000;

        shr=0;shg=0;

        vlgr=.49;vlgg=.86;vlgb=.35;

    }

void specialKeys(int key, int x, int y) {



    switch (key) {
      case GLUT_KEY_RIGHT:
          speed+=0.05f;
          updateCar(0);
          break;

      case GLUT_KEY_LEFT:
          speed-=0.1f;
          break;
    //Car Up and Down
     /* case GLUT_KEY_UP:
          tc2+=0.2f;
          break;
      case GLUT_KEY_DOWN:
          tc2-=0.2f;

        break;*/

    }
}

void keyboard(unsigned char key, int x, int y)
{

  //Rain keys

    if (key == 'r') { // Rain
    fall = RAIN;
    glutPostRedisplay();
  }
  if (key == 'h') { // Hail
    fall = HAIL;
    glutPostRedisplay();
  }
  if (key == 's') { // Snow
    fall = SNOW;
    glutPostRedisplay();
  }
    if (key == 'p') { // Snow
    fall = 5;
    glutPostRedisplay();
  }

    //end Rain keys



    switch(key)
    {
     case 27:     // ESC key
         exit(0);
         break;
     case 'n':
        night();
        break;
    case 'd':
        day();
        break;

    default:
        break;
    }
}
void updateCar (int v)
    {
        //Car Front

        if(speed>1 || speed<0)
        {
            speed = 0.0;
        }

        tc+=speed;
            if(tc>=45.0)
            {
                tc=-69;
            }


        glutPostRedisplay();
        glutTimerFunc(15,updateCar,0);

    }


void update (int v)
    {

        ////Move cloud and ship
        if(cloud1<=-60.0)
            {
                cloud1=68.5;
            }
        else
            {
                cloud1+=-0.04;
            }
        if(cloud2<=-60.0)
            {
                cloud2=68.5;
            }
        else
            {
                cloud2+=-0.04;
            }
        //Ship
        if(ts<=-50.0)
            {
                ts=50;
            }
        else
            {
                ts+=-0.03;
            }

        //car 2

         if(tc3<=-70.0)
            {
                tc3=50;
            }
        else
            {
                tc3-=0.2;
            }

         if (sc==0)
        {
           if(suny<=7.0)
            {
                suny+=0.05;
            }
        }

        else
        {
           if(suny>=-9)
            {
                suny-=0.05;
            }
        }
        //Moon
        if(moon>=18.0)
            {
                moon-=0.009;
            }




        glutPostRedisplay();
        glutTimerFunc(15,update,0);

    }
       //rain code started
    void initParticles(int i) {
    par_sys[i].alive = true;
    par_sys[i].life = 1.0;
    par_sys[i].fade = float(rand()%100)/1000.0f+0.003f;

    par_sys[i].xpos = (float) (rand() % 21) - 10;
    par_sys[i].ypos = 10.0;
    par_sys[i].zpos = (float) (rand() % 21) - 10;

    par_sys[i].red = 0.5;
    par_sys[i].green = 0.5;
    par_sys[i].blue = 1.0;

    par_sys[i].vel = velocity;
    par_sys[i].gravity = -0.8;//-0.8;

}

    //rain code ended


    //rain code started
    // For Rain
void drawRain() {
  float x, y, z;
  for (loop = 0; loop < MAX_PARTICLES; loop=loop+2) {
    if (par_sys[loop].alive == true) {
      x = par_sys[loop].xpos;
      y = par_sys[loop].ypos;
      z = par_sys[loop].zpos + zoom;

      // Draw particles
      glColor3f(0.5, 0.5, 1.0);
      glBegin(GL_LINES);
        glVertex3f(x, y, z);
        glVertex3f(x, y+0.5, z);
      glEnd();

      // Update values
      //Move
      // Adjust slowdown for speed!
      par_sys[loop].ypos += par_sys[loop].vel / (slowdown*1000);
      par_sys[loop].vel += par_sys[loop].gravity;
      // Decay
      par_sys[loop].life -= par_sys[loop].fade;

      if (par_sys[loop].ypos <= -10) {
        par_sys[loop].life = -1.0;
      }
      //Revive
      if (par_sys[loop].life < 0.0) {
        initParticles(loop);
      }
    }
  }
}

// For Hail
void drawHail() {
  float x, y, z;

  for (loop = 0; loop < MAX_PARTICLES; loop=loop+2) {
    if (par_sys[loop].alive == true) {
      x = par_sys[loop].xpos;
      y = par_sys[loop].ypos;
      z = par_sys[loop].zpos + zoom;

      // Draw particles
      glColor3f(0.8, 0.8, 0.9);
      glBegin(GL_QUADS);
        // Front
        glVertex3f(x-hailsize, y-hailsize, z+hailsize); // lower left
        glVertex3f(x-hailsize, y+hailsize, z+hailsize); // upper left
        glVertex3f(x+hailsize, y+hailsize, z+hailsize); // upper right
        glVertex3f(x+hailsize, y-hailsize, z+hailsize); // lower left
        //Left
        glVertex3f(x-hailsize, y-hailsize, z+hailsize);
        glVertex3f(x-hailsize, y-hailsize, z-hailsize);
        glVertex3f(x-hailsize, y+hailsize, z-hailsize);
        glVertex3f(x-hailsize, y+hailsize, z+hailsize);
        // Back
        glVertex3f(x-hailsize, y-hailsize, z-hailsize);
        glVertex3f(x-hailsize, y+hailsize, z-hailsize);
        glVertex3f(x+hailsize, y+hailsize, z-hailsize);
        glVertex3f(x+hailsize, y-hailsize, z-hailsize);
        //Right
        glVertex3f(x+hailsize, y+hailsize, z+hailsize);
        glVertex3f(x+hailsize, y+hailsize, z-hailsize);
        glVertex3f(x+hailsize, y-hailsize, z-hailsize);
        glVertex3f(x+hailsize, y-hailsize, z+hailsize);
        //Top
        glVertex3f(x-hailsize, y+hailsize, z+hailsize);
        glVertex3f(x-hailsize, y+hailsize, z-hailsize);
        glVertex3f(x+hailsize, y+hailsize, z-hailsize);
        glVertex3f(x+hailsize, y+hailsize, z+hailsize);
        //Bottom
        glVertex3f(x-hailsize, y-hailsize, z+hailsize);
        glVertex3f(x-hailsize, y-hailsize, z-hailsize);
        glVertex3f(x+hailsize, y-hailsize, z-hailsize);
        glVertex3f(x+hailsize, y-hailsize, z+hailsize);
      glEnd();

      // Update values
      //Move
      if (par_sys[loop].ypos <= -10) {
        par_sys[loop].vel = par_sys[loop].vel * -1.0;
      }
      par_sys[loop].ypos += par_sys[loop].vel / (slowdown*1000); // * 1000
      par_sys[loop].vel += par_sys[loop].gravity;

      // Decay
      par_sys[loop].life -= par_sys[loop].fade;

      //Revive
      if (par_sys[loop].life < 0.0) {
        initParticles(loop);
      }
    }
  }
}

// For Snow
void drawSnow() {
  float x, y, z;
  for (loop = 0; loop < MAX_PARTICLES; loop=loop+2) {
    if (par_sys[loop].alive == true) {
      x = par_sys[loop].xpos;
      y = par_sys[loop].ypos;
      z = par_sys[loop].zpos + zoom;

      // Draw particles
      glColor3f(1.0, 1.0, 1.0);
      glPushMatrix();
      glTranslatef(x, y, z);
      glutSolidSphere(0.2, 16, 16);
      glPopMatrix();

      // Update values
      //Move
      par_sys[loop].ypos += par_sys[loop].vel / (slowdown*1000);
      par_sys[loop].vel += par_sys[loop].gravity;
      // Decay
      par_sys[loop].life -= par_sys[loop].fade;

      if (par_sys[loop].ypos <= -10) {
        int zi = z - zoom + 10;
        int xi = x + 10;
        ground_colors[zi][xi][0] = 1.0;
        ground_colors[zi][xi][2] = 1.0;
        ground_colors[zi][xi][3] += 1.0;
        if (ground_colors[zi][xi][3] > 1.0) {
          ground_points[xi][zi][1] += 0.1;
        }
        par_sys[loop].life = -1.0;
      }

      //Revive
      if (par_sys[loop].life < 0.0) {
        initParticles(loop);
      }
    }
  }
}


    //rain code ended

void display(void)
    {


        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);

        //rain code


        glLoadIdentity();


          glRotatef(pan, 0.0, 1.0, 0.0);
          glRotatef(tilt, 1.0, 0.0, 0.0);

          if (fall == RAIN) {
            drawRain();
            glPushMatrix();


                backSide();
                frontSide(1);


        glPopMatrix();
        glFlush();
          }else if (fall == HAIL) {
            drawHail();
            glPushMatrix();


                backSide();
                frontSide(2);


        glPopMatrix();
        glFlush();
          }else if (fall == SNOW) {
            drawSnow();
            glPushMatrix();


                backSide();
                frontSide(3);


        glPopMatrix();
        glFlush();
          }else{

          drawSnow();
            glPushMatrix();


                backSide();
                frontSide(5);


        glPopMatrix();
        glFlush();

          }

          glutSwapBuffers();

        //end rain code





    }

void init(void)
    {
        //rain code

        glShadeModel(GL_SMOOTH);
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClearDepth(1.0);

        //end rain code


        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        gluOrtho2D(-50.0,50.0,-25.0,25.0);


        //rain code
        for (loop = 0; loop < MAX_PARTICLES; loop++) {
        initParticles(loop);
        }
        //end rain code
    }

    //rain
    void reshape(int w, int h) {
    if (h == 0) h = 1;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45, (float) w / (float) h, .1, 200);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

    //rain

    void idle ( ) {
  glutPostRedisplay();
}
//end


int main(int argc, char** argv)
    {
                glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(1400, 700);
        glutInitWindowPosition(100, 100);
        glutCreateWindow("Scenario");
        init();
        glutDisplayFunc(display);

          //glutReshapeFunc(reshape);//rain


        glutSpecialFunc(specialKeys); //Special Key Handler
        glutKeyboardFunc(keyboard);   //Basic keyboard key handler


  glutIdleFunc(idle);//rain

        glutTimerFunc(15,update,0);
        glutMainLoop();
        return 0;
    }
