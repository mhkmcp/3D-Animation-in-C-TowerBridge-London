#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<cmath>
#include<iostream>

using namespace std;
/* Global variables */
char title[] = "3D Animation | Tower Bridge London";
void specialKeys();
double rotate_y=0;
double rotate_x=0;
float xr=0,yr=0,car_x=0,car_y=0;
int ship_z=0;

/// Initialize OpenGL Graphics
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); /// Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

void specialKeys( int key, int x, int y ) {

  /// F2 -> Plates Up & Ship Forwards, F3 -> Car Go, F4 -> Plates Down
  /// Arrow Keys for Rotation
  switch(key)
    {
    case GLUT_KEY_F2:
        if(car_x >= 3 && car_x < 8 || xr > 1.1 )
        {
            yr = yr;
            xr = xr;
            if(xr >= 1.1)
                ship_z++;
            else
                ship_z+=0;
        }
       else if ((car_x < 3.4 || car_x >= 8) || (xr >= 0 && xr <= 1.1)){
            yr=yr+.3;
            xr=xr+.3;
            ship_z ++;
       }
       else  if (xr > 1.1){
            yr = yr;
            xr = xr;
        }
        glutPostRedisplay();
        break;

    case GLUT_KEY_F3:
        if(yr < 0.1 || car_x >= 2.5){
            if(car_x >= 2.5)
                car_x += 0;
            else
                car_x = car_x + 0.5;
            if(xr < 0.1)
                car_x += 0.5;
        }
        glutPostRedisplay();
        break;

    case GLUT_KEY_F4:
        if((ship_z>=1&&ship_z<=5))
        {
            if(xr > 0.3 && ship_z >=5 ){
                yr -= 0.3;
                xr -= 0.3;
            }
            else {
                xr = xr;
                yr = yr;
            }
         }
        else if(ship_z >= 1 && xr > 0.3){

            xr = xr - 0.3;
            yr = yr -0.3;
        }
        glutPostRedisplay();
        break;

     case GLUT_KEY_UP:
        rotate_x += 5;
        glutPostRedisplay();
        break;

    case GLUT_KEY_DOWN:
        rotate_x -= 5;
        glutPostRedisplay();
        break;

    case GLUT_KEY_LEFT:
        rotate_y += 5;
        glutPostRedisplay();
        break;

    case GLUT_KEY_RIGHT:
        rotate_y -= 5;
        glutPostRedisplay();
        break;
    }

}
/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix


     glLoadIdentity();
    // Reset the model-view matrix
    glTranslatef(1.0f, -0.0f, -13.0f);  // Move right and into the screen
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 0.0, 1.0 );
    glScaled(1,1,1);

     /**Ship Start */
    glBegin(GL_QUADS);
        glColor3d(1.0f, 1.0f, 0.0f);
        glVertex3d(0.5, -3, -2+ship_z);
        glVertex3d(0.5, -3, -3+ship_z);
        glVertex3d(-0.5, -3, -3+ship_z);
        glVertex3d(-0.5, -3, -2+ship_z);
    glEnd();

    glBegin(GL_TRIANGLES); /// golui
        glColor3d(1.0f, 1.0f, 0.0f);
        glVertex3d(0.5, -3, -3+ship_z);
        glVertex3d(0, -2.5, -3.5+ship_z);
        glVertex3d(-0.5, -3, -3+ship_z);

        glColor3d(1.0f, 1.0f, 0.0f);
        glVertex3d(0.5, -3, -2+ship_z);
        glVertex3d(0, -2.5, -1.5+ship_z);
        glVertex3d(-0.5, -3, -2+ship_z);
    glEnd();

    glBegin(GL_POLYGON); /// two sides start
        glColor3d(1.0f, 0.0f, 1.0f);
        glVertex3d(0.5, -3, -2+ship_z);
        glVertex3d(0.2, -3.8, -2+ship_z);
        glVertex3d(0, -4, -2+ship_z);
        glVertex3d(0, -4, -3+ship_z);
        glVertex3d(0.2, -3.8, -3+ship_z);
        glVertex3d(0.5, -3, -3+ship_z);
    glEnd();

     glBegin(GL_POLYGON);
        glColor3d(1.0f, 0.0f, 1.0f);
        glVertex3d(-0.5, -3, -2+ship_z);
        glVertex3d(-0.2, -3.8, -2+ship_z);
        glVertex3d(0, -4, -2+ship_z);
        glVertex3d(0, -4, -3+ship_z);
        glVertex3d(-0.2, -3.8, -3+ship_z);
        glVertex3d(-0.5, -3, -3+ship_z);
    glEnd();  /// two sides End


    glBegin(GL_POLYGON); ///back to view
        glColor3d(1.0f, 1.0, 1.0f);
        glVertex3d(0, -2.5, -3.5+ship_z);
        glVertex3d(0, -4, -3+ship_z);
        glVertex3d(0.2, -3.8, -3+ship_z);
        glVertex3d(0.5, -3, -3+ship_z);

        glColor3d(1.0f, 1.0, 1.0f);
        glVertex3d(0, -2.5, -3.5+ship_z);
        glVertex3d(0, -4, -3+ship_z);
        glVertex3d(-0.2, -3.8, -3+ship_z);
        glVertex3d(-0.5, -3, -3+ship_z);
    glEnd();


    glBegin(GL_POLYGON); ///front to view
        glColor3d(1.0f, 1.0, 1.0f);
        glVertex3d(0, -2.5, -1.5+ship_z);
        glVertex3d(0, -4, -2+ship_z);
        glVertex3d(0.2, -3.8, -2+ship_z);
        glVertex3d(0.5, -3, -2+ship_z);

        glColor3d(1.0f, 1.0, 1.0f);
        glVertex3d(0, -2.5, -1.5+ship_z);
        glVertex3d(0, -4, -2+ship_z);
        glVertex3d(-0.2, -3.8, -2+ship_z);
        glVertex3d(-0.5, -3, -2+ship_z);
    glEnd();


    glBegin(GL_QUADS);      ///four upper sides
        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(0.3, -3, -2.2+ship_z);
        glVertex3d(0.3, -2.6, -2.2+ship_z);
        glVertex3d(-0.3, -2.6, -2.2+ship_z);
        glVertex3d(-0.3, -3, -2.2+ship_z);


        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(0.3, -3, -2.8+ship_z);
        glVertex3d(0.3, -2.6, -2.8+ship_z);
        glVertex3d(-0.3, -2.6, -2.8+ship_z);
        glVertex3d(-0.3, -3, -2.8+ship_z);

        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(0.3, -3, -2.8+ship_z);
        glVertex3d(0.3, -2.6, -2.8+ship_z);
        glVertex3d(-0.3, -2.6, -2.8+ship_z);
        glVertex3d(-0.3, -3, -2.8+ship_z);

        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(0.3, -2.6, -2.2+ship_z);
        glVertex3d(0.3, -3, -2.2+ship_z);
        glVertex3d(0.3, -3, -2.8+ship_z);
        glVertex3d(0.3, -2.6, -2.8+ship_z);


        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(-0.3, -2.6, -2.2+ship_z);
        glVertex3d(-0.3, -3, -2.2+ship_z);
        glVertex3d(-0.3, -3, -2.8+ship_z);
        glVertex3d(-0.3, -2.6, -2.8+ship_z);

       ///starting car
        glColor3d(1.0f, 1.0f, 1.0f);
        glVertex3d(-4.5+car_x, -2,0.2);
        glVertex3d(-5.5+car_x, -2,0.2);
        glVertex3d(-5.5+car_x, -2,-.2);
        glVertex3d(-4.5+car_x, -2,-.2);

        glColor3d(1.0f, 0.0f, 0.0f);
        glVertex3d(-5.5+car_x, -2,.2);
        glVertex3d(-5.5+car_x, -2,-.2);
        glVertex3d(-5.5+car_x, -1.5,-.2);
        glVertex3d(-5.5+car_x, -1.5,.2);

        glColor3d(1.0f, 0.0f, 0.0f);
        glVertex3d(-4.5+car_x, -2,.2);
        glVertex3d(-4.5+car_x, -2,-.2);
        glVertex3d(-4.5+car_x, -1.5,-.2);
        glVertex3d(-4.5+car_x, -1.5,.2);

        glColor3d(1.0f, 1.0f, 0.0f);
        glVertex3d(-4.8+car_x, -1.2,0.2);
        glVertex3d(-5.2+car_x, -1.2,0.2);
        glVertex3d(-5.2+car_x, -1.2,-.2);
        glVertex3d(-4.8+car_x, -1.2,-.2);
        glEnd();

       ///back side of car(blue)
        glBegin(GL_POLYGON);
        glColor3d(0.0f, 0.0f, 1.0f);
        glVertex3d(-5.5+car_x, -2,-.2);
        glVertex3d(-5.5+car_x, -1.5,-.2);
        glVertex3d(-5.2+car_x, -1.2,-.2);
        glVertex3d(-4.8+car_x, -1.2,-.2);
        glVertex3d(-4.5+car_x, -1.5,-.2);
        glVertex3d(-4.5+car_x, -2,-.2);
        glEnd();

        /// front side of car(violet)
        glBegin(GL_POLYGON);
        glColor3d(1.0f, 0.0f, 1.0f);
        glVertex3d(-5.5+car_x,-2,.2);
        glVertex3d(-5.5+car_x,-1.5,.2);
        glVertex3d(-5.2+car_x,-1.2,.2);
        glVertex3d(-4.8+car_x,-1.2,.2);
        glVertex3d(-4.5+car_x,-1.5,.2);
        glVertex3d(-4.5+car_x,-2,.2);
         glEnd();

        glBegin(GL_QUADS);
        glColor3d(1.0f, 1.0f, 1.0f);
        glVertex3d(-5.2+car_x,-1.2,-.2);
        glVertex3d(-5.2+car_x,-1.2,.2);
        glVertex3d(-5.5+car_x,-1.5,.2);
        glVertex3d(-5.5+car_x,-1.5,-.2);

        glColor3d(1.0f, 1.0f, 1.0f);
        glVertex3d(-4.8+car_x,-1.2,-.2);
        glVertex3d(-4.8+car_x,-1.2,.2);
        glVertex3d(-4.5+car_x,-1.5,.2);
        glVertex3d(-4.5+car_x,-1.5,-.2);
        glEnd();

        ///end of car


    /**Ship Ship End */


    glBegin(GL_QUADS); ///main road
    ///left thake first tol
        glColor3d(0.5f, 0.0f, 0.0f);
        glVertex3d(-6, -2, 1);
        glVertex3d(-6, -2, -1);
        glVertex3d(-2, -2, -1);
        glVertex3d(-2, -2, 1);

  ///left thake 2nd tol

        glColor3d(0.5f, 1.0f, 0.0f);
        glVertex3d(-2, -2, 1);
        glVertex3d(-2, -2, -1);
        glVertex3d(0-xr, -2+yr, -1);
        glVertex3d(0-xr, -2+yr, 1);

        glColor3d(1.0f, 1.0f, 0.0f);
        glVertex3d(0+xr, -2+yr, 1);
        glVertex3d(0+xr, -2+yr, -1);
        glVertex3d(2, -2, -1);
        glVertex3d(2, -2, 1);

        glColor3d(1.0f, 1.0f, 0.0f);
        glVertex3d(2, -2, 1);
        glVertex3d(2, -2, -1);
        glVertex3d(6, -2, -1);
        glVertex3d(6, -2, 1);

        ///uporer tol ses

        /// nicher tol start

        glColor3d(0.0f, 1.0f, 1.0f);
        glVertex3d(-6, -2.5, 1);
        glVertex3d(-6, -2.5, -1);
        glVertex3d(-2, -2.5, -1);
        glVertex3d(-2, -2.5, 1);

        glColor3d(0.5f, 1.0f, 0.0f);
        glVertex3d(-2, -2.5, 1);
        glVertex3d(-2, -2.5, -1);
        glVertex3d(0-xr, -2.5+yr, -1);
        glVertex3d(0-xr, -2.5+yr, 1);

        glColor3d(1.0f, 1.0f, 0.0f);
        glVertex3d(0+xr, -2.5+yr, 1);
        glVertex3d(0+xr, -2.5+yr, -1);
        glVertex3d(2, -2.5, -1);
        glVertex3d(2, -2.5, 1);

        glColor3d(1.0f, 1.0f, 1.0f);
        glVertex3d(2, -2.5, 1);
        glVertex3d(2, -2.5, -1);
        glVertex3d(6, -2.5, -1);
        glVertex3d(6, -2.5, 1);
        ///nicher tol ses

        ///shamner tol start

        glColor3d(0.0f, 1.0f, 1.0f);
        glVertex3d(-6, -2.5, 1);
        glVertex3d(-6, -2, 1);
        glVertex3d(-2, -2, 1);
        glVertex3d(-2, -2.5, 1);

        glColor3d(0.5f, 1.0f, 0.0f);
        glVertex3d(-2, -2.5, 1);
        glVertex3d(-2, -2, 1);
        glVertex3d(0-xr, -2+yr, 1);
        glVertex3d(0-xr, -2.5+yr, 1);

        glColor3d(1.0f, 1.0f, 0.0f);
        glVertex3d(0+xr, -2.5+yr, 1);
        glVertex3d(0+xr, -2+yr, 1);
        glVertex3d(2, -2, 1);
        glVertex3d(2, -2.5, 1);

        glColor3d(1.0f, 1.0f, 1.0f);
        glVertex3d(2, -2.5, 1);
        glVertex3d(2, -2, 1);
        glVertex3d(6, -2, 1);
        glVertex3d(6, -2.5, 1);

        ///shamner tol ses

        ///pisoner tol start

        glColor3d(0.0f, 1.0f, 1.0f);
        glVertex3d(-6, -2.5, -1);
        glVertex3d(-6, -2, -1);
        glVertex3d(-2, -2, -1);
        glVertex3d(-2, -2.5, -1);

        glColor3d(0.5f, 1.0f, 0.0f);
        glVertex3d(-2, -2.5, -1);
        glVertex3d(-2, -2, -1);
        glVertex3d(0-xr, -2+yr, -1);
        glVertex3d(0-xr, -2.5+yr, -1);

        glColor3d(1.0f, 1.0f, 0.0f);
        glVertex3d(0+xr, -2.5+yr, -1);
        glVertex3d(0+xr, -2+yr, -1);
        glVertex3d(2, -2, -1);
        glVertex3d(2, -2.5, -1);

        glColor3d(1.0f, 1.0f, 1.0f);
        glVertex3d(2, -2.5, -1);
        glVertex3d(2, -2, -1);
        glVertex3d(6, -2, -1);
        glVertex3d(6, -2.5, -1);

        ///pisoner tol ses

        ///jointing tol

        glColor3d(1.0f, 1.0f, 1.0f);
        glVertex3d(0-xr, -2.5+yr, -1);
        glVertex3d(0-xr, -2+yr, -1);
        glVertex3d(0-xr, -2+yr, 1);
        glVertex3d(0-xr, -2.5+yr, 1);

        glColor3d(1.0f, 1.0f, 1.0f);
        glVertex3d(0+xr, -2.5+yr, -1);
        glVertex3d(0+xr, -2+yr, -1);
        glVertex3d(0+xr, -2+yr, 1);
        glVertex3d(0+xr, -2.5+yr, 1);

        ///jointing tol ses


        ///end of road

        ///pillar joint plane front
        ///1st plane

        glColor3d(1.0f, 1.0f, 1.0f);
        glVertex3d(-2,3.5,1);
        glVertex3d(-2,3,1);
        glVertex3d(2,3,1);
        glVertex3d(2,3.5,1);

        glColor3d(1.0f, 1.0f, 1.0f);
        glVertex3d(-2,3.5,.5);
        glVertex3d(-2,3,.5);
        glVertex3d(2,3,.5);
        glVertex3d(2,3.5,.5);

        glColor3d(1.0f, 1.0f, 1.0f);
        glVertex3d(-2,3.5,.5);
        glVertex3d(-2,3.5,1);
        glVertex3d(2,3.5,1);
        glVertex3d(2,3.5,.5);

        glColor3d(1.0f, 1.0f, 0.0f);
        glVertex3d(-2,3,.5);
        glVertex3d(-2,3,1);
        glVertex3d(2,3,1);
        glVertex3d(2,3,.5);

        ///pillar joint plane back
        ///1st plane

        glColor3d(1.0f, 1.0f, 1.0f);
        glVertex3d(-2,3.5,-1);
        glVertex3d(-2,3,-1);
        glVertex3d(2,3,-1);
        glVertex3d(2,3.5,-1);

        glColor3d(1.0f, 1.0f, 1.0f);
        glVertex3d(-2,3.5,-.5);
        glVertex3d(-2,3,-.5);
        glVertex3d(2,3,-.5);
        glVertex3d(2,3.5,-.5);

        glColor3d(1.0f, 1.0f, 1.0f);
        glVertex3d(-2,3.5,-.5);
        glVertex3d(-2,3.5,-1);
        glVertex3d(2,3.5,-1);
        glVertex3d(2,3.5,-.5);

        glColor3d(1.0f, 1.0f, 0.0f);
        glVertex3d(-2,3,-.5);
        glVertex3d(-2,3,-1);
        glVertex3d(2,3,-1);
        glVertex3d(2,3,-.5);

///front Pillar Start
/// Left Pillar 1st Plane
        glColor3d(1.0f, 0.0f, 0.0f);
        glVertex3d(-2, -2, 1);
        glVertex3d(-2, 4, 1);
        glVertex3d(-4, 4, 1);
        glVertex3d(-4, -2, 1);

/// Left Pillar 2nd Plane
        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(-2, -2, 0.5);
        glVertex3d(-2, 4, 0.5);
        glVertex3d(-2, 4, 1);
        glVertex3d(-2, -2, 1);

/// Left Pillar 3rd Plane
        glColor3d(1.0f, 0.0f, 0.0f);
        glVertex3d(-2, -2, 0.5);
        glVertex3d(-2, 4, 0.5);
        glVertex3d(-4, 4, 0.5);
        glVertex3d(-4, -2, 0.5);


/// Left Pillar 4th Plane
        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(-4, -2, 0.5);
        glVertex3d(-4, 4, 0.5);
        glVertex3d(-4, 4, 1);
        glVertex3d(-4, -2, 1);

///front Pillar Start


///back Pillar Start
/// Left Pillar 1st Plane
        glColor3d(1.0f, 0.0f, 0.0f);
        glVertex3d(-2, -2, -1);
        glVertex3d(-2, 4, -1);
        glVertex3d(-4, 4, -1);
        glVertex3d(-4, -2, -1);

/// Left Pillar 2nd Plane
        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(-2, -2, -0.5);
        glVertex3d(-2, 4, -0.5);
        glVertex3d(-2, 4, -1);
        glVertex3d(-2, -2, -1);

/// Left Pillar 3rd Plane
        glColor3d(1.0f, 0.0f, 0.0f);
        glVertex3d(-2, -2, -0.5);
        glVertex3d(-2, 4, -0.5);
        glVertex3d(-4, 4, -0.5);
        glVertex3d(-4, -2, -0.5);


/// Left Pillar 4th Plane
        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(-4, -2, -0.5);
        glVertex3d(-4, 4, -0.5);
        glVertex3d(-4, 4, -1);
        glVertex3d(-4, -2, -1);

        ///left front pillar 5th plane
        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(-4, .5, 0.5);
        glVertex3d(-4, 4, 0.5);
        glVertex3d(-4, 4, -.5);
        glVertex3d(-4, .5, -.5);

        ///left front pillar 6th plane
        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(-2, .5, 0.5);
        glVertex3d(-2, 4, 0.5);
        glVertex3d(-2, 4, -.5);
        glVertex3d(-2, .5, -.5);

        ///left pillar roof
       glColor3d(1.0f, 1.0f, 0.0f);
        glVertex3d(-2, 4, 1);
        glVertex3d(-2, 4, -1);
        glVertex3d(-4, 4, -1);
        glVertex3d(-4, 4, 1);




///back Pillar End

///Right back Pillar Start
/// right Pillar 1st Plane
        glColor3d(1.0f, 0.0f, 0.0f);
        glVertex3d(2, -2, -1);
        glVertex3d(2, 4, -1);
        glVertex3d(4, 4, -1);
        glVertex3d(4, -2, -1);

/// right Pillar 2nd Plane
        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(2, -2, -0.5);
        glVertex3d(2, 4, -0.5);
        glVertex3d(2, 4, -1);
        glVertex3d(2, -2, -1);

/// right Pillar 3rd Plane
        glColor3d(1.0f, 0.0f, 0.0f);
        glVertex3d(2, -2, -0.5);
        glVertex3d(2, 4, -0.5);
        glVertex3d(4, 4, -0.5);
        glVertex3d(4, -2, -0.5);


/// right Pillar 4th Plane
        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(4, -2, -0.5);
        glVertex3d(4, 4, -0.5);
        glVertex3d(4, 4, -1);
        glVertex3d(4, -2, -1);

///right front Pillar End

///Right front Pillar Start
/// right Pillar 1st Plane
        glColor3d(1.0f, 0.0f, 0.0f);
        glVertex3d(2, -2, 1);
        glVertex3d(2, 4, 1);
        glVertex3d(4, 4, 1);
        glVertex3d(4, -2, 1);

/// right Pillar 2nd Plane
        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(2, -2, 0.5);
        glVertex3d(2, 4, 0.5);
        glVertex3d(2, 4, 1);
        glVertex3d(2, -2, 1);

/// right Pillar 3rd Plane
        glColor3d(1.0f, 0.0f, 0.0f);
        glVertex3d(2, -2, 0.5);
        glVertex3d(2, 4, 0.5);
        glVertex3d(4, 4, 0.5);
        glVertex3d(4, -2, 0.5);


/// right Pillar 4th Plane
        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(4, -2, 0.5);
        glVertex3d(4, 4, 0.5);
        glVertex3d(4, 4, 1);
        glVertex3d(4, -2, 1);

///right front pillar 5th plane
        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(4, .5, 0.5);
        glVertex3d(4, 4, 0.5);
        glVertex3d(4, 4, -.5);
        glVertex3d(4, .5, -.5);

        ///right front pillar 6th plane
        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(2, .5, 0.5);
        glVertex3d(2, 4, 0.5);
        glVertex3d(2, 4, -.5);
        glVertex3d(2, .5, -.5);


       ///right pillar roof
       glColor3d(1.0f, 1.0f, 0.0f);
        glVertex3d(2, 4, 1);
        glVertex3d(2, 4, -1);
        glVertex3d(4, 4, -1);
        glVertex3d(4, 4, 1);


///right front Pillar End


///base piller all plane
   ///front
        glColor3d(1.0f, 1.0f, 0.0f);
        glVertex3d(-2,-2.5, 1);
        glVertex3d(-2,-4,1);
        glVertex3d(-4, -4, 1);
        glVertex3d(-4, -2.5, 1);
///right
        glColor3d(1.0f, 1.0f, 0.0f);
        glVertex3d(-2,-2.5, -1);
        glVertex3d(-2,-4,-1);
        glVertex3d(-2, -4, 1);
        glVertex3d(-2, -2.5, 1);
///left
        glColor3d(1.0f, 1.0f, 0.0f);
        glVertex3d(-4,-2.5, -1);
        glVertex3d(-4,-4,-1);
        glVertex3d(-4, -4, 1);
        glVertex3d(-4, -2.5, 1);
///back
        glVertex3d(-2,-2.5, -1);
        glVertex3d(-2,-4, -1);
        glVertex3d(-4, -4, -1);
        glVertex3d(-4, -2.5, -1);
///end of left base pillar

///start of right base pillar

///front
        glColor3d(1.0f, 1.0f, 0.0f);
        glVertex3d(2,-2.5, 1);
        glVertex3d(2,-4,1);
        glVertex3d(4, -4, 1);
        glVertex3d(4, -2.5, 1);
///right
        glColor3d(1.0f, 1.0f, 0.0f);
        glVertex3d(2,-2.5, -1);
        glVertex3d(2,-4,-1);
        glVertex3d(2, -4, 1);
        glVertex3d(2, -2.5, 1);
///left
        glColor3d(1.0f, 1.0f, 0.0f);
        glVertex3d(4,-2.5, -1);
        glVertex3d(4,-4,-1);
        glVertex3d(4, -4, 1);
        glVertex3d(4, -2.5, 1);
///back
        glVertex3d(2,-2.5, -1);
        glVertex3d(2,-4, -1);
        glVertex3d(4, -4, -1);
        glVertex3d(4, -2.5, -1);
        glEnd();
///end of right base pillar



///1st big triangle

        glBegin(GL_TRIANGLES);
        glColor3d(0.0f, 0.0f, 0.0f);
        glVertex3d(-2.3, 4, .7);
        glVertex3d(-3, 6, 0);
        glVertex3d(-2.3, 4, -.7);


        glColor3d(1.0f, 0.0f, 0.0f);
        glVertex3d(-2.3,4,-.7);
        glVertex3d(-3,6,0);
        glVertex3d(-3.7,4,-.7);


        glColor3d(1.0f, 1.0f, 0.0f);
        glVertex3d(-3.7,4,-.7);
        glVertex3d(-3,6,0);
        glVertex3d(-3.7,4,.7);


        glColor3d(1.0f, 0.0f, 1.0f);
        glVertex3d(-3.7,4,.7);
        glVertex3d(-3,6,0);
        glVertex3d(-2.3,4,.7);

        glEnd();

        ///2nd big triangle

        glBegin(GL_TRIANGLES);
        glColor3d(0.0f, 0.0f, 0.0f);
        glVertex3d(2.3, 4, .7);
        glVertex3d(3, 6, 0);
        glVertex3d(2.3, 4, -.7);


        glColor3d(1.0f, 0.0f, 0.0f);
        glVertex3d(2.3,4,-.7);
        glVertex3d(3,6,0);
        glVertex3d(3.7,4,-.7);


        glColor3d(1.0f, 1.0f, 0.0f);
        glVertex3d(3.7,4,-.7);
        glVertex3d(3,6,0);
        glVertex3d(3.7,4,.7);


        glColor3d(1.0f, 0.0f, 1.0f);
        glVertex3d(3.7,4,.7);
        glVertex3d(3,6,0);
        glVertex3d(2.3,4,.7);

        glEnd();


        ///end of big triangle



    ///first pillar 1st triangle

    glBegin(GL_TRIANGLES);
        glColor3d(1.0f, 0.0f, 0.0f);
        glVertex3d(-2,4,1);
        glVertex3d(-2.15,5,.85);
        glVertex3d(-2,4,.7);

        glColor3d(1.0f, 0.0f, 0.0f);
        glVertex3d(-2,4,.7);
        glVertex3d(-2.15,5,.85);
        glVertex3d(-2.3,4,.7);

        glColor3d(1.0f, 0.0f, 0.0f);
        glVertex3d(-2.3,4,.7);
        glVertex3d(-2.15,5,.85);
        glVertex3d(-2.3,4,1);

        glColor3d(1.0f,0.0f, 0.0f);
        glVertex3d(-2.3,4,1);
        glVertex3d(-2.15,5,.85);
        glVertex3d(-2,4,1);

    glEnd();

    ///2nd pillar 4th triangle

    glBegin(GL_TRIANGLES);
        glColor3d(1.0f, 0.0f, 0.0f);
        glVertex3d(2,4,1);
        glVertex3d(2.15,5,.85);
        glVertex3d(2,4,.7);

        glColor3d(1.0f, 0.0f, 0.0f);
        glVertex3d(2,4,.7);
        glVertex3d(2.15,5,.85);
        glVertex3d(2.3,4,.7);

        glColor3d(1.0f, 0.0f, 0.0f);
        glVertex3d(2.3,4,.7);
        glVertex3d(2.15,5,.85);
        glVertex3d(2.3,4,1);


        glColor3d(1.0f, 0.0f, 0.0f);
        glVertex3d(2.3,4,1);
        glVertex3d(2.15,5,.85);
        glVertex3d(2,4,1);

    glEnd();

    ///first pillar 2nd triangle

    glBegin(GL_TRIANGLES);
        glColor3d(0.0f, 0.0f, 1.0f);
        glVertex3d(-2,4,-1);
        glVertex3d(-2.15,5,-.85);
        glVertex3d(-2,4,-.7);

        glColor3d(0.0f, 0.0f, 1.0f);
        glVertex3d(-2,4,-.7);
        glVertex3d(-2.15,5,-.85);
        glVertex3d(-2.3,4,-.7);

        glColor3d(0.0f, 0.0f, 1.0f);
        glVertex3d(-2.3,4,-.7);
        glVertex3d(-2.15,5,-.85);
        glVertex3d(-2.3,4,-1);


        glColor3d(0.0f, 0.0f, 1.0f);
        glVertex3d(-2.3,4,-1);
        glVertex3d(-2.15,5,-.85);
        glVertex3d(-2,4,-1);

    glEnd();

    ///2nd pillar 3rd triangle

    glBegin(GL_TRIANGLES);
        glColor3d(0.0f, 0.0f, 1.0f);
        glVertex3d(2,4,-1);
        glVertex3d(2.15,5,-.85);
        glVertex3d(2,4,-.7);

        glColor3d(0.0f, 0.0f, 1.0f);
        glVertex3d(2,4,-.7);
        glVertex3d(2.15,5,-.85);
        glVertex3d(2.3,4,-.7);

        glColor3d(0.0f, 0.0f, 1.0f);
        glVertex3d(2.3,4,-.7);
        glVertex3d(2.15,5,-.85);
        glVertex3d(2.3,4,-1);


        glColor3d(0.0f, 0.0f, 1.0f);
        glVertex3d(2.3,4,-1);
        glVertex3d(2.15,5,-.85);
        glVertex3d(2,4,-1);

    glEnd();

    ///first pillar 3rd triangle

    glBegin(GL_TRIANGLES);
        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(-3.7,4,-1);
        glVertex3d(-3.85,5,-.85);
        glVertex3d(-3.7,4,-.7);

        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(-3.7,4,-.7);
        glVertex3d(-3.85,5,-.85);
        glVertex3d(-4,4,-.7);

        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(-4,4,-.7);
        glVertex3d(-3.85,5,-.85);
        glVertex3d(-4,4,-1);


        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(-4,4,-1);
        glVertex3d(-3.85,5,-.85);
        glVertex3d(-3.7,4,-1);

    glEnd();

    ///2nd pillar 2nd triangle


    glBegin(GL_TRIANGLES);
        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(3.7,4,1);
        glVertex3d(3.85,5,.85);
        glVertex3d(3.7,4,.7);

        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(3.7,4,.7);
        glVertex3d(3.85,5,.85);
        glVertex3d(4,4,.7);

        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(4,4,.7);
        glVertex3d(3.85,5,.85);
        glVertex3d(4,4,1);


        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(4,4,1);
        glVertex3d(3.85,5,.85);
        glVertex3d(3.7,4,1);

    glEnd();

    ///first pillar 4th triangle

    glBegin(GL_TRIANGLES);
        glColor3d(0.0f, 0.0f, 1.0f);
        glVertex3d(-3.7,4,1);
        glVertex3d(-3.85,5,.85);
        glVertex3d(-3.7,4,.7);

        glColor3d(0.0f, 1.0f, 1.0f);
        glVertex3d(-3.7,4,.7);
        glVertex3d(-3.85,5,.85);
        glVertex3d(-4,4,.7);

        glColor3d(0.0f, 1.0f, 1.0f);
        glVertex3d(-4,4,.7);
        glVertex3d(-3.85,5,.85);
        glVertex3d(-4,4,1);


        glColor3d(1.0f, 0.0f, 0.0f);
        glVertex3d(-4,4,1);
        glVertex3d(-3.85,5,.85);
        glVertex3d(-3.7,4,1);

    glEnd();

    ///2nd pillar 2nd triangle

    glBegin(GL_TRIANGLES);
        glColor3d(0.0f, 0.0f, 1.0f);
        glVertex3d(3.7,4,-1);
        glVertex3d(3.85,5,-.85);
        glVertex3d(3.7,4,-.7);

        glColor3d(0.0f, 1.0f, 1.0f);
        glVertex3d(3.7,4,-.7);
        glVertex3d(3.85,5,-.85);
        glVertex3d(4,4,-.7);

        glColor3d(0.0f, 1.0f, 1.0f);
        glVertex3d(4,4,-.7);
        glVertex3d(3.85,5,-.85);
        glVertex3d(4,4,-1);


        glColor3d(1.0f, 1.0f, 0.0f);
        glVertex3d(4,4,-1);
        glVertex3d(3.85,5,-.85);
        glVertex3d(3.7,4,-1);

    glEnd();

    ///triangle finish



    glLoadIdentity();                  // Reset the model-view matrix
   glTranslatef(-1.5f, 0.0f, -6.0f);  // Move left and into the screen



  // glTranslatef(-1.0f,1.0f,-.1);  // Move right and into the screen
    //    glScaled(2,1,2);


      glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

}


void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;



   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}




int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(1200, 720);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow(title);          // Create window with the given title

   glutDisplayFunc(display);

        // Register callback handler for window re-paint event
   glutSpecialFunc(specialKeys);

//   glutKeyboardFunc(windowKey);
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}
