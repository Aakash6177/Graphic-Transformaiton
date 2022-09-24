// Aakash Sharma
// CSCI-172
// 300446940
 


#define GL_SILENCE_DEPRECATION
#include <string.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GLUT/glut.h>
#endif
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

bool WireFrame=false;

/*
 Using the given framework for the Depth and Light settings, we create the following models (Sphere, Cube, Teapot) with various functions
 
 
*/

// bool values to decide whether a particular object is selected or not.
bool Cube = false;
bool Teapot = false;
bool Sphere = false;
// This flag is for the ressting the flag to obtain the original positions
bool Reset = false;

// Initial values to zoom and out
float mCube = 0.0; // to move cube
float mTeapot = 0.0; // to move teapot
float mSphere = 0.0; // to move sphere

float rCube = 0.0;      // initial value to rotate the value
float rTeapot = 0.0;    // intinal value to rotate the value
float rSphere = 0.0;    // inital value to rotate the value

const GLfloat light_ambient[]  = { 0.5f, 0.5f, 0.5f, 0.5f };
const GLfloat light_diffuse[]  = { 2.0f, 3.0f, 2.0f, 4.0f };
const GLfloat light_specular[] = { 4.0f, 4.0f, 4.0f, 4.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 4.0f, 4.0f, 4.0f, 1.0f };
const GLfloat mat_diffuse[]    = { 6.0f, 7.0f, 9.0f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = {110.0f };


/* GLUT callback Handlers */

static void resize(int width, int height) //Function scale the frame
                                          
{


   if(width<=height)
            glViewport(0,(GLsizei) (height-width)/2,(GLsizei) width,(GLsizei) width);
    else
          glViewport((GLsizei) (width-height)/2 ,0 ,(GLsizei) height,(GLsizei) height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (50.0f,1,0.1f, 100.0f);
 }



static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
//5
    gluLookAt(0,3,10,0.0,0.0,0.0,0.0,1.0,0.0);

    if(WireFrame)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);        //Draw Our Mesh In Wireframe Mesh
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);        //Toggle WIRE FRAME

    
    glColor3f(0.0, 1.0, 0);                     //setting the color
    glPushMatrix();                         //Pushing the matrix
    glTranslatef(4.0,0.0,-2.0 + mCube);      //setting the coordinates (+mCube to zoom in and Zoom out the cube of its current position
    glRotatef(rCube, 0, 1, 0);           //To rotate the Cube
    glutSolidCube(2);                       //creating the cube
    glPopMatrix();                          //Popping the matrix
    
    
    glColor3f(1.0, 0.0, 0.0);                     //setting the color
    glPushMatrix();                             //Pushing the matrix
    glTranslatef(0.0,0.0,-3.0 + mTeapot);    //setting the coordinates (+mTeapot to zoom in and Zoom out the cube of its current position
    glRotatef(rTeapot, 0, 1, 0);         // To rotate the teapot
    glutSolidTeapot(1.5);                       //creating the teapot
    glPopMatrix();                              //Popping the matrix
    
    
    glColor3f(0.0, 0.0, 1.0);                     //setting the color
    glPushMatrix();                             //Pushing the matrix
    glTranslatef(-3.5,0.0,-1.0 + mSphere);    //setting thecoordinates (+mSphere to zoom in and Zoom out the cube of its current position
    glRotatef(rSphere, 0, 1, 0);           //To rotate the Sphere
    glutSolidSphere(1.3, 30, 30);                 //creating the Sphere
    glPopMatrix();                                 //Popping the Matrix
    

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
            
        case 'c':           //if c is pressed then it will switch to c
            Cube = true;      // swithcingfor the cube case
            Teapot = false;
            Sphere = false;
            break;
            
        case 's':             // It will swithc between the s case
            Cube = false;
            Teapot = false;
            Sphere = true;
            break;
            
        case 't':              // It will switch the teapot case
            Cube = false;     // just teapot bool value is ture
            Teapot = true;
            Sphere = false;
            break;
        
        case 'r':               // If r is pressed it will makr the reset value true and reset all the positions.
            Reset = true;
        case 'w':
            WireFrame = true;
            break;
        default:
            break;
    }
}

void Specialkeys(int key, int x, int y)  // This function is for the rotation of the objects and present on the screen.
{
    switch(key)
   {
           // This switch case if for moving obejcts closer by the degree of 0.5 on command
    case GLUT_KEY_DOWN:
           if(Cube) {
               mCube += 0.5;
           }
           if(Sphere){
               mSphere += 0.5;
           }
           if (Teapot){
               mTeapot += 0.5;
           }
           if(Reset){
            mCube = mSphere = mTeapot = mCube = rSphere = rTeapot = 0;
               Reset = false;
           }
    break;
            
           
    // This switch case if for moving obejcts farther by the degree of 0.5 on command
    case GLUT_KEY_UP:
           if(Cube) {
               mCube -= 0.5;
           }
           if(Sphere){
               
            mSphere -= 0.5;
           }
           if(Teapot) {
               mTeapot -= 0.5;
           }
           if(Reset)
           {
            mCube = mSphere = mTeapot = rCube = rSphere = rTeapot = 0;
               Reset = false;
           }
    break;
           
     //This switch case is for the rotating the objects counter clockwise on comand
       case GLUT_KEY_LEFT:
           
           if(Cube) {
               rCube += 5.0;
           }
           if(Sphere){
               rSphere += 5.0;
           }
           if(Teapot){
               rTeapot += 5.0;
           }
           if(Reset)
           {
            mCube = mSphere = mTeapot = rCube = rSphere = rTeapot = 0;
               Reset = false;
           }
    break;
           
    // This switch case is for the rotating the objects in clockwise direction
       case GLUT_KEY_RIGHT:
           if(Cube) rCube -= 5.0;
           if(Sphere) rSphere -= 5.0;
           if(Teapot) rTeapot -= 5.0;
           if(Reset)
           {
            mCube = mSphere = mTeapot = rCube = rSphere = rTeapot = 0;
               Reset = false;
           }
    break;
       default:
           break;
   }
  glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

static void init(void)
{
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);

    glEnable(GL_DEPTH_TEST);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glShadeModel(GL_SMOOTH);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
}


/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);

    glutInitWindowSize(800,600);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Image Transformation and translation");
    init();
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutSpecialFunc(Specialkeys);
    glutIdleFunc(idle);
    glutMainLoop();
 
    return EXIT_SUCCESS;
}





