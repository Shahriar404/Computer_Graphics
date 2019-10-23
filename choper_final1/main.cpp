#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI acos(-1.0)
#define pi 3.1416

static int slices = 16;
static int stacks = 16;

static float da = 0, db = 0, dc = 0;
static float dx = 0, dy = 0, dz = 0;
static float ex = 0, ey = 0, ez = 30;
static float zx = 1, zy = 1, zz = 1;
static float degreex = 0, degreey = 0, degreez = 0;
static float theta = 0;
static int height = 640, width = 480;
static int flag = 0, flag2 = 0;

/* GLUT callback Handlers */

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

//redefinition
//float ex=10*sin(0);
//float ey=-1;
//float ez=10*cos(PI/180);
int ll=0;
float d=(5*PI)/360;
float cx=0,cy=1,cz=-6,upx=0,upy=1,upz=0,pitch=0,roll=0;
//

float eye_x=0;
float eye_y=0;
float eye_z=8;
int f=0;

int countuu=0;

const GLfloat light_ambient_green[]  = { .0f, 1.0f, 0.0f, 1.0f };
const GLfloat light_diffuse_green[]  = { .0f, 1.0f, 0.0f, 1.0f };
const GLfloat light_specular_green[] = { .0f, 1.0f, 0.0f, 1.0f };
const GLfloat light_position_green[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat light_ambient_red[]  = { 1.0f, .0f, .0f, 1.0f };
const GLfloat light_diffuse_red[]  = { 1.0f, .0f, .0f, 1.0f };
const GLfloat light_specular_red[] = { 1.0f, .0f, .0f, 1.0f };
const GLfloat light_position_red[] = { -5.0f, 5.0f, 5.0f, 0.0f };

const GLfloat light_ambient_white[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_diffuse_white[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular_white[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position_white[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat light_ambient_nl[]  = { .1f, .1f,  .1f, 1.0f };
const GLfloat light_diffuse_nl[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_specular_nl[] = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_position_nl[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_no_color[]   = { 0.0f, 0.0f, 0.0f, 1.0f };

const GLfloat mat_ambient_red[]    = { 1.0f, 0.0f, 0.0f, 1.0f };
const GLfloat mat_diffuse_red[]    = { 1.0f, 0.0f, 0.0f, 1.0f };
const GLfloat mat_specular_red[]   = { 1.0f, 0.0f, 0.0f, 1.0f };
const GLfloat high_shininess_red[] = { 100.0f };

const GLfloat mat_ambient_green[]    = { 0.0f, 1.0f, 0.0f, 1.0f };
const GLfloat mat_diffuse_green[]    = { 0.0f, 1.0f, 0.0f, 1.0f };
const GLfloat mat_specular_green[]   = { 0.0f, 1.0f, 0.0f, 1.0f };
const GLfloat high_shininess_green[] = { 100.0f };

const GLfloat mat_ambient_blue[]    = { 0.0f, 0.0f, 1.0f, 1.0f };
const GLfloat mat_diffuse_blue[]    = { 0.0f, 0.0f, 1.0f, 1.0f };
const GLfloat mat_specular_blue[]   = { 0.0f, 0.0f, 1.0f, 1.0f };
const GLfloat high_shininess_blue[] = { 100.0f };

const GLfloat mat_ambient_black[]    = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat mat_diffuse_black[]    = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat mat_specular_black[]   = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat high_shininess_black[] = { 100.0f };

const GLfloat mat_ambient_rg[]    = { 1.0f, 1.0f, 0.0f, 1.0f };
const GLfloat mat_diffuse_rg[]    = { 1.0f, 1.0f, 0.0f, 1.0f };
const GLfloat mat_specular_rg[]   = { 1.0f, 1.0f, 0.0f, 1.0f };
const GLfloat high_shininess_rg[] = { 100.0f };

const GLfloat mat_ambient_rb[]    = { 1.0f, 0.0f, 1.0f, 1.0f };
const GLfloat mat_diffuse_rb[]    = { 1.0f, 0.0f, 1.0f, 1.0f };
const GLfloat mat_specular_rb[]   = { 1.0f, 0.0f, 1.0f, 1.0f };
const GLfloat high_shininess_rb[] = { 100.0f };

const GLfloat mat_ambient_rbs[]    = { .20f, 0.0f, .50f, 1.0f };
const GLfloat mat_diffuse_rbs[]    = { .20f, 0.0f, .50f, 1.0f };
const GLfloat mat_specular_rbs[]   = { .20f, 0.0f, .50f, 1.0f };
const GLfloat high_shininess_rbs[] = { 100.0f };


const GLfloat mat_ambient_gb[]    = { 0.0f, 1.0f, 1.0f, 1.0f };
const GLfloat mat_diffuse_gb[]    = { 0.0f, 1.0f, 1.0f, 1.0f };
const GLfloat mat_specular_gb[]   = { 0.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess_gb[] = { 100.0f };

const GLfloat mat_ambient_gbs[]    = { 0.0f, .5f, 1.0f, 1.0f };
const GLfloat mat_diffuse_gbs[]    = { 0.0f, .5f, 1.0f, 1.0f };
const GLfloat mat_specular_gbs[]   = { 0.0f, .5f, 1.0f, 1.0f };
const GLfloat high_shininess_gbs[] = { 100.0f };

const GLfloat mat_ambient_rgs[]    = { 1.0f, .5f, .0f, 1.0f };
const GLfloat mat_diffuse_rgs[]    = { 1.0f, .5f, .0f, 1.0f };
const GLfloat mat_specular_rgs[]   = { 1.0f, .5f, .0f, 1.0f };
const GLfloat high_shininess_rgs[] = { 100.0f };

const GLfloat mat_ambient_table[]    = { .32f, 0.21f, 0.15f, 1.0f };
const GLfloat mat_diffuse_table[]    = { .32f, .21f, 0.15f, 1.0f };
const GLfloat mat_specular_table[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess_table[] = { 100.0f };

const GLfloat mat_ambient_tableleg[]    = { .41f, 0.26f, 0.18f, 1.0f };
const GLfloat mat_diffuse_tableleg[]    = { .41f, .26f, 0.18f, 1.0f };
const GLfloat mat_specular_tableleg[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess_tableleg[] = { 100.0f };

const GLfloat mat_ambient_fl[]    = { .51f, 0.44f, 0.38f, 1.0f };
const GLfloat mat_diffuse_fl[]    = { .51f, 0.44f, 0.38f, 1.0f };
const GLfloat mat_specular_fl[]   = { .51f, 0.44f, 0.38f, 1.0f };
const GLfloat high_shininess_fl[] = { 100.0f };

const GLfloat mat_ambient_wb[]    = { .48f, 0.39f, 0.13f, 1.0f };
const GLfloat mat_diffuse_wb[]    = { .48f, 0.39f, 0.13f, 1.0f };
const GLfloat mat_specular_wb[]   = { .48f, 0.39f, 0.13f, 1.0f };
const GLfloat high_shininess_wb[] = { 100.0f };

const GLfloat mat_ambient_ws[]    = { .74f, 0.66f, 0.51f, 1.0f };
const GLfloat mat_diffuse_ws[]    = { .74f, 0.66f, 0.51f, 1.0f };
const GLfloat mat_specular_ws[]   = { .74f, 0.66f, 0.51f, 1.0f };
const GLfloat high_shininess_ws[] = { 100.0f };

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

        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient_red);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse_red);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular_red);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess_red);

        //glColor3d(r,g,b);
        glVertex3f(12,0,0);
        glVertex3f(12,.3,0);
        glVertex3f(12,.3,2);
        glVertex3f(12,0,2);

        //glColor3d(r,g,b);
        glVertex3f(12,0,2);
        glVertex3f(12,.3,2);
        glVertex3f(6,.3,2);
        glVertex3f(6,0,2);

        //glColor3d(r,g,b);
        glVertex3f(6,.3,0);
        glVertex3f(6,0,0);
        glVertex3f(6,0,2);
        glVertex3f(6,.3,2);

        //glColor3d(r,g,b);
        glVertex3f(6,.3,0);
        glVertex3f(12,.3,0);
        glVertex3f(12,0,0);
        glVertex3f(6,0,0);

        //glColor3d(r,g,b);
        glVertex3f(12,.3,0);
        glVertex3f(6,.3,0);
        glVertex3f(6,.3,2);
        glVertex3f(12,.3,2);

        //glColor3d(r,g,b);
        glVertex3f(6,0,0);
        glVertex3f(12,0,0);
        glVertex3f(12,0,2);
        glVertex3f(6,0,2);
    glEnd();
}

void drawQuadUpLeg(double r,double g,double b)
{
    glBegin(GL_QUADS);

        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient_green);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse_green);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular_green);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess_green);
        //glColor3d(r,b,g);
        glVertex3f(11,.3,.9);
        glVertex3f(11,2,.9);
        glVertex3f(11,2,1.1);
        glVertex3f(11,.3,1.1);

        //glColor3d(r,b,g);
        glVertex3f(7,2,.9);
        glVertex3f(7,.3,.9);
        glVertex3f(7,.3,1.1);
        glVertex3f(7,2,1.1);

        //glColor3d(r,b,g);
        glVertex3f(7,.3,1.1);
        glVertex3f(11,.3,1.1);
        glVertex3f(11,2,1.1);
        glVertex3f(7,2,1.1);

        //glColor3d(r,b,g);
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

        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient_blue);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse_blue);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular_blue);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess_blue);
        //glColor3d(b,g,r);
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
        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient_blue);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse_blue);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular_blue);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess_blue);

        //glColor3d(r,g,b);
        glVertex3f(9,2,0);
        glVertex3f(9,9,0);
        glVertex3f(12,10,0);
        glVertex3f(12,2,0);
        //glColor3d(r,g,b);
        glVertex3f(12,2,6);
        glVertex3f(12,10,6);
        glVertex3f(9,9,6);
        glVertex3f(9,2,6);
        //glColor3d(r,g,b);
        glVertex3f(12,10,0);
        glVertex3f(9,9,0);
        glVertex3f(9,9,6);
        glVertex3f(12,10,6);
        //glColor3d(r,g,b);
        glVertex3f(9,2,0);
        glVertex3f(4,2,0);
        glVertex3f(4,5,0);
        glVertex3f(9,9,0);
        //glColor3d(r,g,b);
        glVertex3f(9,9,6);
        glVertex3f(4,5,6);
        glVertex3f(4,2,6);
        glVertex3f(9,2,6);
        //glColor3d(r,g,b);
        glVertex3f(7,7.4,0);
        glVertex3f(4,5,0);
        glVertex3f(4,5,6);
        glVertex3f(7,7.4,6);
        //glColor3d(r,g,b);
        glVertex3f(12,2,0);
        glVertex3f(12,2,6);
        glVertex3f(4,2,6);
        glVertex3f(4,2,0);

        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient_black);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse_black);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular_black);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess_black);
        //glColor3d(0,0,0);
        glVertex3f(12,2,0);
        glVertex3f(12,10,0);
        glVertex3f(9,9,0);
        glVertex3f(9,2,0);
        //glColor3d(0,0,0);
        glVertex3f(9,2,6);
        glVertex3f(9,9,6);
        glVertex3f(12,10,6);
        glVertex3f(12,2,6);
        //glColor3d(0,0,0);
        glVertex3f(12,2,6);
        glVertex3f(12,10,6);
        glVertex3f(12,10,0);
        glVertex3f(12,2,0);
        //glColor3d(0,0,0);
        glVertex3f(12,10,6);
        glVertex3f(9,9,6);
        glVertex3f(9,9,0);
        glVertex3f(12,10,0);
        //glColor3d(0,0,0);
        glVertex3f(9,9,0);
        glVertex3f(4,5,0);
        glVertex3f(4,2,0);
        glVertex3f(9,2,0);
        //glColor3d(0,0,0);
        glVertex3f(9,2,6);
        glVertex3f(4,2,6);
        glVertex3f(4,5,6);
        glVertex3f(9,9,6);
        //glColor3d(0,0,0);
        glVertex3f(7,7.4,6);
        glVertex3f(4,5,6);
        glVertex3f(4,5,0);
        glVertex3f(7,7.4,0);
        //glColor3d(0,0,0);
        glVertex3f(4,5,0);
        glVertex3f(4,5,6);
        glVertex3f(4,2,6);
        glVertex3f(4,2,0);
        //glColor3d(0,0,0);
        glVertex3f(4,2,0);
        glVertex3f(4,2,6);
        glVertex3f(12,2,6);
        glVertex3f(12,2,0);

        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient_gb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse_gb);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular_gb);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess_gb);
        //glColor3d(r,1,b);
        glVertex3f(12,2,0);
        glVertex3f(12,10,0);
        glVertex3f(12,10,6);
        glVertex3f(12,2,6);
        //glColor3d(r,1,b);
        glVertex3f(4,2,0);
        glVertex3f(4,2,6);
        glVertex3f(4,5,6);
        glVertex3f(4,5,0);


        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient_rb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse_rb);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular_rb);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess_rb);
        //glColor3d(b,g,1);
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


        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient_red);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse_red);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular_red);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess_red);
        //glColor3d(b,g,r);
        glVertex3f(18,5,2);
        glVertex3f(18,7,2);
        glVertex3f(18,7,4);
        glVertex3f(18,5,4);







        //tail

        //glColor3d(b,g,r);
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


        //glColor3f(1,0,0);
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
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient_rgs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse_rgs);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular_rgs);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess_rgs);
    //glColor3d(1,.5,.8);
    gluCylinder(quadratic,.3,.3,3.0f,32,32);
}


void helicopter()
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 100.0;
    const double a = t*90.0;

    glPushMatrix();

//        const GLfloat mat_ambient3[]    = { .5, 0.0f, 0.0f, 1.0f };
//        const GLfloat mat_diffuse3[]    = { .8, 0.0f, 0.0f, 1.0f };
//        const GLfloat mat_specular3[]   = { .5, 0.0f, 0.0f, 1.0f };
//        const GLfloat high_shininess3[] = { 100.0f };
//
//        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient3);
//        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse3);
//        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular3);
//        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess3);



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
    gluLookAt(eye_x, eye_y, eye_z, g, h, i, j, k, l);
    //roll, pitch, yaw alternative method
    //gluLookAt(ex, ey, ez, g, h, 1, j, 1, l);
    //gluLookAt(eye_x,eye_y,4,cx,cy,cz,upx,upy,upz);
}









void cube(){
    glBegin(GL_QUADS);
        //r = g = b = 1;
        //glColor3f(r, g, b);
        glVertex3f(-1, -1, 1);
        glVertex3f(1, -1, 1);
        glVertex3f(1, 1, 1);
        glVertex3f(-1, 1, 1);

        //glColor3f(r, g, b);
        glVertex3f(1, 1, 1);
        glVertex3f(1, -1, 1);
        glVertex3f(1, -1, -1);
        glVertex3f(1, 1, -1);

        //glColor3f(r, g, b);
        glVertex3f(-1, 1, -1);
        glVertex3f(-1, -1, -1);
        glVertex3f(-1, -1, 1);
        glVertex3f(-1, 1, 1);

        //glColor3f(r, g, b);
        glVertex3f(-1, 1, -1);
        glVertex3f(1, 1, -1);
        glVertex3f(1, -1, -1);
        glVertex3f(-1, -1, -1);

        //glColor3f(r, g, b);
        glVertex3f(-1, 1, -1);
        glVertex3f(-1, 1, 1);
        glVertex3f(1, 1, 1);
        glVertex3f(1, 1, -1);

        //glColor3f(r, g, b);
        glVertex3f(-1, -1, 1);
        glVertex3f(-1, -1, -1);
        glVertex3f(1, -1, -1);
        glVertex3f(1, -1, 1);
    glEnd();
}

void circle(double r, double g, double b){
    glBegin(GL_POLYGON);
    r = g = b = 1;
    glColor3f(1, g, 1);
    for(double i = 360; i >=180; i--)

    {
        double theta = 2.0f * 3.1416 * i / 360;

        double x = 2 * cosf(theta);
        double y = 2 * sinf(theta);

        glVertex3f(x, y, -.1);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
    for(double i = 180; i >=0; i--)

    {
        double theta = 2.0f * 3.1416 * i / 360;

        double x = 2 * cosf(theta);
        double y = 2 * sinf(theta);

        glVertex3f(x, y, -.1);
    }
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
    for(double i = 0; i <= 180; i++)
    {
        double theta = 2 * 3.1416 * i / 360;

        double x = 2 * cosf(theta);
        double y = 2 * sinf(theta);

        glVertex3f(x, y, .1);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1, g, 1);
    for(double i = 180; i <=360; i++)

    {
        double theta = 2 * 3.1416 * i / 360;

        double x = 2 * cosf(theta);
        double y = 2 * sinf(theta);

        glVertex3f(x, y, .1);
    }
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(r, g, b);
    for(double i = 0; i <= 180; i++)
    {
        double theta = 2 * 3.1416 * i / 360;

        double x = 2 * cosf(theta);
        double y = 2 * sinf(theta);

        glVertex3f(x, y, .1);
        glVertex3f(x, y, -.1);

    }
     glBegin(GL_QUAD_STRIP);
    glColor3f(1, g, 1);
    for(double i = 180; i <= 360; i++)
    {
        double theta = 2 * 3.1416 * i / 360;

        double x = 2 * cosf(theta);
        double y = 2 * sinf(theta);

        glVertex3f(x, y, .1);
        glVertex3f(x, y, -.1);

    }

    glEnd();
}

void Jack(){

    glPushMatrix(); //Jack
        glScaled(.1,.5,.1);
        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient_rbs);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse_rbs);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular_rbs);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess_rbs);
        //glColor3d(.2,0,.5);
        glutSolidSphere(2,10,10);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,1,0);
        glScaled(.1,.1,.1);
        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient_red);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse_red);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular_red);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess_red);
        //glColor3d(1,0,0);
        glutSolidSphere(2,10,10);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,-1,0);
        glScaled(.1,.1,.1);
        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient_red);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse_red);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular_red);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess_red);
        //glColor3d(1,0,0);
        glutSolidSphere(2,10,10);
    glPopMatrix();

}

void env(){
//    glTranslated(2,0,-7);
//
//    glRotated(-10,0,1,0);
//
//    glRotated(da,1,0,0);
//    glRotated(db,0,1,0);
//    glRotated(dc,0,0,1);


    glPushMatrix();   //front wall
        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient_wb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse_wb);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular_wb);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess_wb);

        glRotated(-10,0,1,0);
        glScaled(7,3,.4);
        cube();
    glPopMatrix();

    glPushMatrix();   //left wall
        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient_gbs);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse_gbs);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular_gbs);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess_gbs);

        glTranslated(-7.6,0,5.5);
        glRotated(-100,0,1,0);
        glScaled(7,3,.4);
        cube();
    glPopMatrix();

    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient_fl);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse_fl);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular_fl);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess_fl);

        glTranslated(0,-3,6.5);
        glRotated(-10,0,1,0);
        glScaled(15,.1,15);
        cube();
    glPopMatrix();

    glPushMatrix(); //Table

        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient_table);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse_table);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular_table);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess_table);
        glTranslated(0,0,7);
        glRotated(-10,0,1,0);
        glRotated(90,1,0,0);
        glScaled(2.5,2.5,2.5);
        circle(.5,0,.2);
    glPopMatrix();

    glPushMatrix(); //leg0
        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient_tableleg);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse_tableleg);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular_tableleg);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess_tableleg);
        glTranslated(1.5,-1.5,8.6);
        glScaled(.1,1.5,.1);
        cube();
    glPopMatrix();

    glPushMatrix(); //leg1
        glTranslated(-1.5,-1.5,8.5);
        glScaled(.1,1.5,.1);
        cube();
    glPopMatrix();

    glPushMatrix(); //leg2
       glTranslated(1.5,-1.5,5.6);
        glScaled(.1,1.5,.1);
        cube();
    glPopMatrix();

    glPushMatrix(); //leg3
        glTranslated(-1.5,-1.5,5.6);
        glScaled(.1,1.5,.1);
        cube();
    glPopMatrix();

    glTranslated(-2,0,-2);

    glPushMatrix(); //Jack
        glTranslated(0,1.1,7);
        glRotated(-45,1,0,0);
        Jack();
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,1.1,7);
        glRotated(15,1,0,0);
        glRotated(-45,0,0,1);
        Jack();
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,1.1,7);
        glRotated(45,1,0,1);
        Jack();
    glPopMatrix();

}




static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);

    glRotated(da,1,0,0);
    glRotated(db,0,1,0);
    glRotated(dc,0,0,1);

    glScaled(zx,zy,zz);

    if(flag == 0){

        glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient_white);
        glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse_white);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular_white);
        glLightfv(GL_LIGHT0, GL_POSITION, light_position_white);
    }
    if(flag == 1){

        glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient_red);
        glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_ambient_red);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_ambient_red);
        glLightfv(GL_LIGHT0, GL_POSITION, light_ambient_red);
    }
    if(flag == 2){

        glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient_nl);
        glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_ambient_nl);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_ambient_nl);
        glLightfv(GL_LIGHT0, GL_POSITION, light_ambient_nl);

        glLightfv(GL_LIGHT1, GL_AMBIENT,  light_ambient_green);
        glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_diffuse_green);
        glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular_green);
        glLightfv(GL_LIGHT1, GL_POSITION, light_position_green);
    }
    if(flag == 3){

        glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient_red);
        glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse_red);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular_red);
        glLightfv(GL_LIGHT0, GL_POSITION, light_position_red);

        glLightfv(GL_LIGHT1, GL_AMBIENT,  light_ambient_green);
        glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_diffuse_green);
        glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular_green);
        glLightfv(GL_LIGHT1, GL_POSITION, light_position_green);
    }

    if(flag == 4){

        glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient_nl);
        glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse_nl);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular_nl);
        glLightfv(GL_LIGHT0, GL_POSITION, light_position_nl);

        glLightfv(GL_LIGHT1, GL_AMBIENT,  light_ambient_nl);
        glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_ambient_nl);
        glLightfv(GL_LIGHT1, GL_SPECULAR, light_ambient_nl);
        glLightfv(GL_LIGHT1, GL_POSITION, light_ambient_nl);
    }


    glPushMatrix();
        glTranslated(2,0,-7);
        glRotated(-10,0,1,0);
        env();
    glPopMatrix();


    glPushMatrix();
        glTranslated(1,1.5,2);
        glRotated(-10,0,1,0);
        glScaled(.4,.3,.4);
        helicopter();
    glPopMatrix();


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;

    gluLookAt(0,0,25,0,0,0,0,1,0);

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

        case '7':
            da +=5;
            break;

        case ',':
            db +=5;
            break;

        case '[':
            dc +=5;
            break;

        case '8':
            da -=5;
            break;

        case '.':
            db -=5;
            break;

        case ']':
            dc -=5;
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
            countuu++;
            break;
        case 'h':
            if(countuu>0){
                    t2--;
                    countuu--;
            }
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
        case 'E':
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
            while(f<=5000)
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






//        //Pitch
//        case 'R':
//             pitch+=5;
//             cy=cos(pitch*pi/180)-sin(pitch*pi/180);
//             cz=cos(pitch*pi/180)+sin(pitch*pi/180)-30;
//             break;
//
//    //yaw
//        case '0':
//             pitch+=5;
//             cx=5*cos(pitch*pi/180)+5*sin(pitch*pi/180);
//             cz=5*cos(pitch*pi/180)-5*sin(pitch*pi/180)-30;
//             break;
//    //roll
//         case 'E':
//             roll+=5;
//             upx=5*cos(roll*pi/180)-5*sin(roll*pi/180);
//             upy=5*cos(roll*pi/180)+5*sin(roll*pi/180);
//             upz=5*sin(roll*pi/180)-5*cos(roll*pi/180);
//             break;

/*

        //roll
         case 'E':
             roll+=5;
             j=5*cos(roll*pi/180)-5*sin(roll*pi/180);
             k=5*cos(roll*pi/180)+5*sin(roll*pi/180);
             l=5*sin(roll*pi/180)-5*cos(roll*pi/180);
             break;
        //pitch
        case 'R':
             pitch+=5;
             h=cos(pitch*pi/180)-sin(pitch*pi/180);
             i=cos(pitch*pi/180)+sin(pitch*pi/180)-30;
             break;

        //yaw
        case '0':
             pitch+=5;
             g=5*cos(pitch*pi/180)+5*sin(pitch*pi/180);
             i=5*cos(pitch*pi/180)-5*sin(pitch*pi/180)-30;
             break;


*/



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

        case '-':
            if(flag == 4)
            {
                flag = 0;
            }
            else{
                flag++;
                printf("%d", flag);
            }
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


//static void key(unsigned char key, int x, int y)
//{
//    switch (key)
//    {
//        case 27 :
//        case 'q':
//            exit(0);
//            break;
//
//        case 'a':
//            da +=5;
//            break;
//
//        case 'b':
//            db +=5;
//            break;
//
//        case 'c':
//            dc +=5;
//            break;
//
//        case 'd':
//            da -=5;
//            break;
//
//        case 'e':
//            db -=5;
//            break;
//
//        case 'f':
//            dc -=5;
//            break;
//
//        case 'x':
//            dx +=.5;
//            dy = 0;
//            dz = 0;
//            break;
//
//        case 'y':
//        	dx = 0;
//            dy +=.5;
//            dz = 0;
//            break;
//
//        case 'z':
//        	dx = 0;
//        	dy = 0;
//            dz +=.5;
//            break;
//
//        case 'i':
//            dx -=.5;
//            dy = 0;
//            dz = 0;
//            break;
//
//        case 'o':
//        	dx = 0;
//            dy -=.5;
//            dz = 0;
//            break;
//
//        case 'p':
//        	dx = 0;
//        	dy = 0;
//            dz -=.5;
//            break;
//
//         case 'l':
//         	degreex -=2;
//         	theta = 2 * degreex * 3.1416 /180;
//    		ey = 30 * cosf(theta);
//    		ez = 30 * sinf(theta);
//            ex = 0;
//            break;
//
//         case 'k':
//         	degreex +=2;
//         	theta = 2 * degreex * 3.1416 /180;
//    		ex = 30 * cosf(theta);
//   		 	ez = 30 * sinf(theta);
//  			ey = 0;
//            break;
//
//        case 'm':
//       		degreex -=2;
//        	theta = 2 * degreex * 3.1416 /180;
//   			ex = 30 * cosf(theta);
//  			ey = 30 * sinf(theta);
//   	        ez = 0;
//            break;
//
//        case '+':
//            zx +=.05;
//            zy +=.05;
//            zz +=.05;
//            break;
//
//        case '-':
//            zx -=.05;
//            zy -=.05;
//            zz -=.05;
//            break;
//
//        case '0':
//            if(flag == 1) flag = 0;
//            else flag = 1;
//            break;
//
//    }
//
//    glutPostRedisplay();
//}

static void idle(void)
{
    glutPostRedisplay();
}



/* Program entry point */

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

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);

//    glEnable(GL_LIGHT1);
//    glEnable(GL_NORMALIZE);
//    glEnable(GL_LIGHTING);

    glutMainLoop();

    return EXIT_SUCCESS;
}
