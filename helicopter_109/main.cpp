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

static int slices = 16;
static int stacks = 16;

/* GLUT callback Handlers */

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
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glTranslated(t1,t2,t3);
        glRotated(rotation_degree,0,1,0);
        glRotated(rotation_degree2,1,0,0);
        glRotated(rotation_degree3,0,0,1);
        glScaled(z, z, z);
        //glScalef(.25,.25,.25);
        glScalef(s1,s2,s3);

        drawQuadLeg(1,0,0);

        glTranslated(0,0,-4);
        drawQuadLeg(1,0,0);



        drawQuadBodyBack(0,0,1);
        drawFan(0,0,1);

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
            if(z >= 1.5) break;
            z += .2;
            break;
        case 'x':
            if(z <= .5) break;
            z -= .2;
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

/*const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
*/
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
