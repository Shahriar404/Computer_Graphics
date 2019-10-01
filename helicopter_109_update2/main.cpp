/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include<math.h>
#define PI acos(-1.0)
#define pi 3.1416

float rotation_degree=0;
float rotation_degree2=0;
float rotation_degree3=0;
float z = 1;
float t1=1;
float t2=-4;
float t3=-12;
float s1=.25;
float s2=.25;
float s3=.25;

float g=0,h=0,i=0,j=0,k=1,l=0;

//
float ex=10*sin(0);
float ey=-1;
float ez=10*cos(PI/180);
int ll=0;
float d=(5*PI)/360;
float cx=0,cy=1,cz=-6,upx=0,upy=1,upz=0,pitch=0,roll=0;
//

float eye_x=0;
float eye_y=0;
float eye_z=8;
int f=0;

static int slices = 16;
static int stacks = 16;

/* GLUT callback Handlers */

void ownScaled(double x, double y, double z){
    GLfloat mat[] ={
        x, 0, 0, 0,
        0, y, 0, 0,
        0, 0, z, 0,
        0, 0, 0, 1
    };
    glMatrixMode(GL_MODELVIEW);
    glMultMatrixf(mat);
}


static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

void drawQuadLeg(double r,double g,double b)
{
    glBegin(GL_QUADS);
        glColor3d(r,g,b);
        glVertex3f(12,0,0);
        glVertex3f(12,.3,0);
        glVertex3f(12,.3,2);
        glVertex3f(12,0,2);

        glColor3d(r,g,b);
        glVertex3f(12,0,2);
        glVertex3f(12,.3,2);
        glVertex3f(6,.3,2);
        glVertex3f(6,0,2);

        glColor3d(r,g,b);
        glVertex3f(6,.3,0);
        glVertex3f(6,0,0);
        glVertex3f(6,0,2);
        glVertex3f(6,.3,2);

        glColor3d(r,g,b);
        glVertex3f(6,.3,0);
        glVertex3f(12,.3,0);
        glVertex3f(12,0,0);
        glVertex3f(6,0,0);

        glColor3d(r,g,b);
        glVertex3f(12,.3,0);
        glVertex3f(6,.3,0);
        glVertex3f(6,.3,2);
        glVertex3f(12,.3,2);

        glColor3d(r,g,b);
        glVertex3f(6,0,0);
        glVertex3f(12,0,0);
        glVertex3f(12,0,2);
        glVertex3f(6,0,2);
    glEnd();
}

void drawQuadUpLeg(double r,double g,double b)
{
    glBegin(GL_QUADS);
        glColor3d(r,b,g);
        glVertex3f(11,.3,.9);
        glVertex3f(11,2,.9);
        glVertex3f(11,2,1.1);
        glVertex3f(11,.3,1.1);

        glColor3d(r,b,g);
        glVertex3f(7,2,.9);
        glVertex3f(7,.3,.9);
        glVertex3f(7,.3,1.1);
        glVertex3f(7,2,1.1);

        glColor3d(r,b,g);
        glVertex3f(7,.3,1.1);
        glVertex3f(11,.3,1.1);
        glVertex3f(11,2,1.1);
        glVertex3f(7,2,1.1);

        glColor3d(r,b,g);
        glVertex3f(7,.3,.9);
        glVertex3f(7,2,.9);
        glVertex3f(11,2,.9);
        glVertex3f(11,.3,.9);
    glEnd();
}

void drawFan(double r,double g,double b)
{
    glBegin(GL_QUADS);
        //fan1
        glColor3d(b,g,r);
        glVertex3f(14,12,2);
        glVertex3f(8,12,2);
        glVertex3f(8,12,4);
        glVertex3f(14,12,4);

        //glColor3d(b,g,r);
        glVertex3f(14,11.6,2);
        glVertex3f(14,11.6,4);
        glVertex3f(8,11.6,4);
        glVertex3f(8,11.6,2);

        //glColor3d(b,g,r);
        glVertex3f(14,11.6,4);
        glVertex3f(14,12,4);
        glVertex3f(8,12,4);
        glVertex3f(8,11.6,4);

        //glColor3d(b,g,r);
        glVertex3f(14,11.6,2);
        glVertex3f(8,11.6,2);
        glVertex3f(8,12,2);
        glVertex3f(14,12,2);

        //glColor3d(b,g,r);
        glVertex3f(8,12,2);
        glVertex3f(7,12,2.5);
        glVertex3f(7,12,3.5);
        glVertex3f(8,12,4);
        //glColor3d(b,g,r);
        glVertex3f(8,11.6,2);
        glVertex3f(8,11.6,4);
        glVertex3f(7,11.6,3.5);
        glVertex3f(7,11.6,2.5);
        //glColor3d(b,g,r);
        glVertex3f(8,11.6,4);
        glVertex3f(8,12,4);
        glVertex3f(7,12,3.5);
        glVertex3f(7,11.6,3.5);
        //glColor3d(b,g,r);
        glVertex3f(8,11.6,2);
        glVertex3f(7,11.6,2.5);
        glVertex3f(7,12,2.5);
        glVertex3f(8,12,2);
        //glColor3d(b,g,r);
        glVertex3f(7,11.6,2.5);
        glVertex3f(7,11.6,3.5);
        glVertex3f(7,12,3.5);
        glVertex3f(7,12,2.5);

        //glColor3d(b,g,r);
        glVertex3f(14,12,2);
        glVertex3f(14,12,4);
        glVertex3f(15,12,3.5);
        glVertex3f(15,12,2.5);
        //glColor3d(b,g,r);
        glVertex3f(14,11.6,2);
        glVertex3f(15,11.6,2.5);
        glVertex3f(15,11.6,3.5);
        glVertex3f(14,11.6,4);
        //glColor3d(b,g,r);
        glVertex3f(15,11.6,3.5);
        glVertex3f(15,12,3.5);
        glVertex3f(14,12,4);
        glVertex3f(14,11.6,4);
        //glColor3d(b,g,r);
        glVertex3f(14,11.6,2);
        glVertex3f(14,12,2);
        glVertex3f(15,12,2.5);
        glVertex3f(15,11.6,2.5);
        //glColor3d(b,g,r);
        glVertex3f(15,11.6,2.5);
        glVertex3f(15,12,2.5);
        glVertex3f(15,12,3.5);
        glVertex3f(15,11.6,3.5);


        //fan2
        glColor3d(b,g,r);
        glVertex3f(12,12.4,0);
        glVertex3f(10,12.4,0);
        glVertex3f(10,12.4,6);
        glVertex3f(12,12.4,6);

        glColor3d(b,g,r);
        glVertex3f(12,12,6);
        glVertex3f(10,12,6);
        glVertex3f(10,12,0);
        glVertex3f(12,12,0);

        glColor3d(b,g,r);
        glVertex3f(10,12.4,0);
        glVertex3f(10,12,0);
        glVertex3f(10,12,6);
        glVertex3f(10,12.4,6);

        glColor3d(b,g,r);
        glVertex3f(12,12,0);
        glVertex3f(12,12.4,0);
        glVertex3f(12,12.4,6);
        glVertex3f(12,12,6);


        glColor3d(b,g,r);
        glVertex3f(12,12.4,0);
        glVertex3f(11.5,12.4,-1);
        glVertex3f(10.5,12.4,-1);
        glVertex3f(10,12.4,0);
        glColor3d(b,g,r);
        glVertex3f(12,12,0);
        glVertex3f(10,12,0);
        glVertex3f(10.5,12,-1);
        glVertex3f(11.5,12,-1);
        glColor3d(b,g,r);
        glVertex3f(12,12,0);
        glVertex3f(11.5,12,-1);
        glVertex3f(11.5,12.4,-1);
        glVertex3f(12,12.4,0);
        glColor3d(b,g,r);
        glVertex3f(10,12.4,0);
        glVertex3f(10.5,12.4,-1);
        glVertex3f(10.5,12,-1);
        glVertex3f(10,12,0);
        glColor3d(b,g,r);
        glVertex3f(10.5,12.4,-1);
        glVertex3f(11.5,12.4,-1);
        glVertex3f(11.5,12,-1);
        glVertex3f(10.5,12,-1);

//
        glColor3d(b,g,r);
        glVertex3f(10,12.4,6);
        glVertex3f(10.5,12.4,7);
        glVertex3f(11.5,12.4,7);
        glVertex3f(12,12.4,6);
        glColor3d(b,g,r);
        glVertex3f(10,12,6);
        glVertex3f(12,12,6);
        glVertex3f(11.5,12,7);
        glVertex3f(10.5,12,7);
        //glColor3d(b,g,r);
        glVertex3f(10.5,12,7);
        glVertex3f(11.5,12,7);
        glVertex3f(11.5,12.4,7);
        glVertex3f(10.5,12.4,7);
        glColor3d(b,g,r);
        glVertex3f(12,12,6);
        glVertex3f(12,12.4,6);
        glVertex3f(11.5,12.4,7);
        glVertex3f(11.5,12,7);
        glColor3d(b,g,r);
        glVertex3f(10,12,6);
        glVertex3f(10.5,12,7);
        glVertex3f(10.5,12.4,7);
        glVertex3f(10,12.4,6);


    glEnd();
}


void drawQuadBodyBack(double r,double g,double b)
{
    glBegin(GL_QUADS);
        glColor3d(r,g,b);
        glVertex3f(9,2,0);
        glVertex3f(9,9,0);
        glVertex3f(12,10,0);
        glVertex3f(12,2,0);

        glColor3d(0,0,0);
        glVertex3f(12,2,0);
        glVertex3f(12,10,0);
        glVertex3f(9,9,0);
        glVertex3f(9,2,0);


        glColor3d(r,g,b);
        glVertex3f(12,2,6);
        glVertex3f(12,10,6);
        glVertex3f(9,9,6);
        glVertex3f(9,2,6);

        glColor3d(0,0,0);
        glVertex3f(9,2,6);
        glVertex3f(9,9,6);
        glVertex3f(12,10,6);
        glVertex3f(12,2,6);


        glColor3d(r,1,b);
        glVertex3f(12,2,0);
        glVertex3f(12,10,0);
        glVertex3f(12,10,6);
        glVertex3f(12,2,6);

        glColor3d(0,0,0);
        glVertex3f(12,2,6);
        glVertex3f(12,10,6);
        glVertex3f(12,10,0);
        glVertex3f(12,2,0);

        glColor3d(r,g,b);
        glVertex3f(12,10,0);
        glVertex3f(9,9,0);
        glVertex3f(9,9,6);
        glVertex3f(12,10,6);

        glColor3d(0,0,0);
        glVertex3f(12,10,6);
        glVertex3f(9,9,6);
        glVertex3f(9,9,0);
        glVertex3f(12,10,0);

        glColor3d(r,g,b);
        glVertex3f(9,2,0);
        glVertex3f(4,2,0);
        glVertex3f(4,5,0);
        glVertex3f(9,9,0);

        glColor3d(0,0,0);
        glVertex3f(9,9,0);
        glVertex3f(4,5,0);
        glVertex3f(4,2,0);
        glVertex3f(9,2,0);


        glColor3d(r,g,b);
        glVertex3f(9,9,6);
        glVertex3f(4,5,6);
        glVertex3f(4,2,6);
        glVertex3f(9,2,6);

        glColor3d(0,0,0);
        glVertex3f(9,2,6);
        glVertex3f(4,2,6);
        glVertex3f(4,5,6);
        glVertex3f(9,9,6);

        glColor3d(r,g,b);
        glVertex3f(7,7.4,0);
        glVertex3f(4,5,0);
        glVertex3f(4,5,6);
        glVertex3f(7,7.4,6);

        glColor3d(0,0,0);
        glVertex3f(7,7.4,6);
        glVertex3f(4,5,6);
        glVertex3f(4,5,0);
        glVertex3f(7,7.4,0);

        glColor3d(r,1,b);
        glVertex3f(4,2,0);
        glVertex3f(4,2,6);
        glVertex3f(4,5,6);
        glVertex3f(4,5,0);

        glColor3d(0,0,0);
        glVertex3f(4,5,0);
        glVertex3f(4,5,6);
        glVertex3f(4,2,6);
        glVertex3f(4,2,0);

        glColor3d(r,g,b);
        glVertex3f(12,2,0);
        glVertex3f(12,2,6);
        glVertex3f(4,2,6);
        glVertex3f(4,2,0);

        glColor3d(0,0,0);
        glVertex3f(4,2,0);
        glVertex3f(4,2,6);
        glVertex3f(12,2,6);
        glVertex3f(12,2,0);

         glColor3d(b,g,1);
        //glColor3d(b,g,r);
        glVertex3f(12,5,2);
        glVertex3f(12,7,2);
        glVertex3f(18,7,2);
        glVertex3f(18,5,2);

        //glColor3d(b,g,r);
        glVertex3f(18,5,4);
        glVertex3f(18,7,4);
        glVertex3f(12,7,4);
        glVertex3f(12,5,4);

        //glColor3d(b,g,r);
        glVertex3f(12,7,2);
        glVertex3f(12,7,4);
        glVertex3f(18,7,4);
        glVertex3f(18,7,2);

        //glColor3d(b,g,r);
        glVertex3f(18,5,2);
        glVertex3f(18,5,4);
        glVertex3f(12,5,4);
        glVertex3f(12,5,2);


        glColor3d(b,g,r);
        glVertex3f(18,5,2);
        glVertex3f(18,7,2);
        glVertex3f(18,7,4);
        glVertex3f(18,5,4);







        //tail

        glColor3d(b,g,r);
        glVertex3f(18,5,2.7);
        glVertex3f(18,7,2.7);
        glVertex3f(21,10,2.7);
        glVertex3f(22,9,2.7);
        //glColor3d(b,g,r);
        glVertex3f(22,9,3.3);
        glVertex3f(21,10,3.3);
        glVertex3f(18,7,3.3);
        glVertex3f(18,5,3.3);
        //glColor3d(b,g,r);
        glVertex3f(18,7,2.7);
        glVertex3f(18,7,3.3);
        glVertex3f(21,10,3.3);
        glVertex3f(21,10,2.7);
        //glColor3d(b,g,r);
        glVertex3f(18,5,2.7);
        glVertex3f(22,9,2.7);
        glVertex3f(22,9,3.3);
        glVertex3f(18,5,3.3);

        //tailend

        glVertex3f(21,10,2.7);
        glVertex3f(21.4,10.2,2.7);
        glVertex3f(22,10,2.7);
        glVertex3f(22,9,2.7);

        glVertex3f(22,9,3.3);
        glVertex3f(22,10,3.3);
        glVertex3f(21.4,10.2,3.3);
        glVertex3f(21,10,3.3);

        glVertex3f(22,9,3.3);
        glVertex3f(22,9,2.7);
        glVertex3f(22,10,2.7);
        glVertex3f(22,10,3.3);

        glVertex3f(21.4,10.2,2.7);
        glVertex3f(21.4,10.2,3.3);
        glVertex3f(22,10,3.3);
        glVertex3f(22,10,2.7);

        glVertex3f(21,10,2.7);
        glVertex3f(21,10,3.3);
        glVertex3f(21.4,10.2,3.3);
        glVertex3f(21.4,10.2,2.7);


        glColor3f(1,0,0);
        glVertex3f(12,5,4);
        glVertex3f(12,4,4);
        glVertex3f(14,4.99,4);
        glVertex3f(14,5,4);

        glVertex3f(12,5,2);
        glVertex3f(14,5,2);
        glVertex3f(14,4.99,2);
        glVertex3f(12,4,2);

        glVertex3f(12,4,2);
        glVertex3f(14,4.99,2);
        glVertex3f(14,4.99,4);
        glVertex3f(12,4,4);

    glEnd();
}

void cylinder() // only call once on startup
{
    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();
    //glTranslated(1.5,-10.5,-13);
    glTranslated(11,1,9);
    glRotatef(0.0, 0.0, 1.0, 0.0);
    glColor3d(1,.5,.8);
    gluCylinder(quadratic,.3,.3,3.0f,32,32);
}


static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 400.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glTranslated(t1,t2,t3);
        glRotated(rotation_degree,0,1,0);
        glRotated(rotation_degree2,1,0,0);
        glRotated(rotation_degree3,0,0,1);
        glScaled(z, z, z);
        //glScalef(.25,.25,.25);
        //glScalef(s1,s2,s3);
        ownScaled(s1,s2,s3);

        glTranslated(-11,0,-3);

        drawQuadLeg(1,0,0);

        glTranslated(0,0,-4);
        drawQuadLeg(1,0,0);



        drawQuadBodyBack(0,0,1);
        //drawFan(0,0,1);

        drawQuadUpLeg(0,0,1);
        glTranslated(0,0,4);
        drawQuadUpLeg(0,0,1);

        glRotated(-90,1,0,0);
        //glTranslated(0,0,-8);
        cylinder();


        //cylinder2();


//        glRotated(-90,1,0,0);
//        glTranslated(0,-.9,.1);
//        glTranslated(6.5,0,0);
//        glScalef(.5,.7,1);
//        glTranslated(-4,0,0);
//        drawQuadLeg(0,1,0);
//
//        glTranslated(0,5.5,.1);
//        drawQuadLeg(0,1,0);

    glPopMatrix();

    glPushMatrix();
        glTranslated(t1,t2,t3);
        glRotated(rotation_degree,0,1,0);
        glRotated(rotation_degree2,1,0,0);
        glRotated(rotation_degree3,0,0,1);
        glScaled(z, z, z);
        //glScalef(s1,s2,s3);



        ownScaled(s1,s2,s3);
        //glRotated(a,0,0,1);
        //glTranslated(-t1,-t2,-t3);
        glRotated(-90,1,0,0);
        glTranslated(15.5,-6.2,8);
        glScalef(.5,.5,.5);
        //drawFan(1,.75,.1);

    glPopMatrix();

    glPushMatrix();
        glTranslated(t1,t2,t3);
        glRotated(rotation_degree,0,1,0);
        glRotated(rotation_degree2,1,0,0);
        glRotated(rotation_degree3,0,0,1);
        glScaled(z, z, z);
        //glScalef(s1,s2,s3);



        ownScaled(s1,s2,s3);
        glTranslated(-11,0,-3);
        //glRotated(a,0,0,1);
        //glTranslated(-t1,-t2,-t3);
        glRotated(-90,1,0,0);
        glTranslated(21.2,-6.1,9.4);
        glScalef(.5,.5,.5);
        glRotated(-a,0,1,0);
        glTranslated(-11,0,-3);
        drawFan(1,.75,.1);

    glPopMatrix();


    glPushMatrix();
        glTranslated(t1,t2,t3);
        glRotated(rotation_degree,0,1,0);
        glRotated(rotation_degree2,1,0,0);
        glRotated(rotation_degree3,0,0,1);
        glScaled(z, z, z);
        //glScalef(s1,s2,s3);



        ownScaled(s1,s2,s3);
        glTranslated(-11,0,-3);
        glTranslated(11,0,-1);
        glRotated(a,0,1,0);
        glTranslated(-11,0,-3);
        drawFan(0,0,1);

    glPopMatrix();

    glPushMatrix();
        glTranslated(t1,t2,t3);
        glRotated(rotation_degree,0,1,0);
        glRotated(rotation_degree2,1,0,0);
        glRotated(rotation_degree3,0,0,1);
        glScaled(z, z, z);
        //glScalef(s1,s2,s3);



        ownScaled(s1,s2,s3);
        glTranslated(-11,0,-3);
        //glRotated(-90,1,0,0);
        glTranslated(15.7,9,-5.7);
        glScalef(.5,.5,.5);
        cylinder();

    glPopMatrix();



    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
    //gluLookAt(eye_x, eye_y, eye_z, g, h, i, j, k, l);
    //roll, pitch, yaw alternative method
    //gluLookAt(ex, ey, ez, g, h, 1, j, 1, l);
    gluLookAt(eye_x,eye_y,4,cx,cy,cz,upx,upy,upz);
    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case 'j':
            rotation_degree += 2.5;
            break;
        case 'l':
            rotation_degree -= 2.5;
            break;

        case 'i':
            rotation_degree2 += 2.5;
            break;
        case 'm':
            rotation_degree2 -= 2.5;
            break;

        case 'a':
            rotation_degree3 += 2.5;
            break;
        case 'd':
            rotation_degree3 -= 2.5;
            break;

        case 't':
            t1 ++;
            break;
        case 'y':
            t1--;
            break;

        case 'g':
            t2 ++;
            break;
        case 'h':
            t2--;
            break;

        case 'v':
            t3 ++;
            break;
        case 'b':
            t3--;
            break;

        case 'J':
            g ++;
            break;
        case 'L':
            g--;
            break;

        case 'I':
            h ++;
            break;
        case 'M':
            h--;
            break;

        case 'A':
            i ++;
            break;
        case 'D':
            i--;
            break;


        case 'Q':
            j ++;
            break;
        case 'W':
            j--;
            break;

        case 'Z':
            k ++;
            break;
        case 'X':
            k--;
            break;

        case 'S':
            l ++;
            break;
        case 'F':
            l--;
            break;


//        case 'E':
//            while(f<=50000)
//            {
//                g+=pow(2,-10);
//                if(g>5)
//                {
//                    for(;g>-5;)
//                    {
//                        g-=pow(2,-10);
//                        display();
//                    }
//                }
//                f++;
//                display();
//            }
//            f=0;
//            g=0;
//            break;
//
//        case 'R':
//            while(f<=50000)
//            {
//                h+=pow(2,-10);
//                if(h>5)
//                {
//                    for(;h>-5;)
//                    {
//                        h-=pow(2,-10);
//                        display();
//                    }
//                }
//                f++;
//                display();
//            }
//            f=0;
//            h=0;
//            break;
//        case '0':
//            while(f<=50000)
//            {
//                j+=pow(2,-10);
//                l-=pow(2,-10);
//                if(j>3&&l<-3)
//                {
//                    for(;j>-5&&l<5;)
//                    {
//                        j-=pow(2,-10);
//                        l+=pow(2,-10);
//                        display();
//                    }
//                }
//                f++;
//                display();
//            }
//            f=0;
//            g=0;
//            break;



//roll, pitch, yaw alternative method
/*        case 'E':
            while(f<=2000)
            {
                j+=pow(2,-10);
                l-=pow(2,-10);
                if(j>1&&l<-1)
                {
                    for(;j>-1&&l<1;)
                    {
                        j-=pow(2,-10);
                        l+=pow(2,-10);
                        display();
                    }
                }
            f++;
            display();
            }
            j=0;
            l=0;
            f=0;
            break;

        case 'R':
            while(f<=2000)
            {
                h+=pow(2,-10);
                if(h>2)
                {
                    for(;h>-4;)
                    {
                        h-=pow(2,-10);
                        display();
                    }
                }
            f++;
            display();
            }
            h=0;
            f=0;
            break;
        case '0':
            while( f<=2000)
            {

                g+=pow(2,-8);
                if(g>4)
                {
                    for(;g>-4;)
                    {
                        g-=pow(2,-8);
                        display();
                    }
                }
            f++;
            display();
            }
            g=1;
            f=0;
            break;
*/





        //Pitch
        case 'R':
             pitch+=5;
             cy=cos(pitch*pi/180)-sin(pitch*pi/180);
             cz=cos(pitch*pi/180)+sin(pitch*pi/180)-30;
             break;

    //yaw
        case '0':
             pitch+=5;
             cx=5*cos(pitch*pi/180)+5*sin(pitch*pi/180);
             cz=5*cos(pitch*pi/180)-5*sin(pitch*pi/180)-30;
             break;
    //roll
         case 'E':
             roll+=5;
             upx=5*cos(roll*pi/180)-5*sin(roll*pi/180);
             upy=5*cos(roll*pi/180)+5*sin(roll*pi/180);
             upz=5*sin(roll*pi/180)-5*cos(roll*pi/180);
             break;





        case '1':
            s1+=.05;
            break;
        case '2':
            s1-=.05;
            break;

        case '3':
            s2+=.05;
            break;
        case '4':
            s2-=.05;
            break;

        case '5':
            s3+=.05;
            break;
        case '6':
            s3-=.05;
            break;

        case 'z':
            if(z >= 7.5) break;
            z += .2;
            break;
        case 'x':
            if(z <= .25) break;
            z -= .2;
            break;


        case 'T':
            if(eye_x<=40)
                eye_x++;
            break;
        case 'G':
            if(eye_y<=40)
                eye_y++;
            break;
        case 'V':
            if(eye_z<=40)
                eye_z++;
            break;

        case 'Y':
            if(eye_x>=-40)
                eye_x--;
            break;
        case 'H':
            if(eye_y>=-40)
                eye_y--;
            break;
        case 'B':
            if(eye_z>=-40)
                eye_z--;
            break;


        case '/':
            double dl=ll*PI/180;
            ex=3*sin(dl);
            ez=3*cos(dl);
            ll+=2.5;
            break;

        /*case '+':
            slices++;
            stacks++;
            break;

        case '-':
            if (slices>3 && stacks>3)
            {
                slices--;
                stacks--;
            }
            break;*/
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    /*glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);*/

    glutMainLoop();

    return EXIT_SUCCESS;
}
