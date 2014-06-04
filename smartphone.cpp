#include "smartphone.h"

/*
 * Sets up the OpenGL rendering context, defines display lists, etc.
 * Gets called once before the first time resizeGL() or paintGL() is called.
 */
void Smartphone::initializeGL(){
    //activate the depth buffer
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); //make the window background a blue-ish tone
}


/*
 *  Sets up the OpenGL viewport, projection, etc. Gets called whenever the widget has been resized
 *  (and also when it is shown for the first time because all newly created widgets get a resize event automatically).
 */
void Smartphone::resizeGL (int width, int height){
    glViewport( 0, 0, (GLint)width, (GLint)height );

    /* create viewing cone with near and far clipping planes */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum( -1.0, 1.0, -1.0, 1.0, 5.0, 30.0);

    glMatrixMode( GL_MODELVIEW );
}



/*
 * Renders the OpenGL scene. Gets called whenever the widget needs to be updated.
 */
void Smartphone::paintGL(){

    //delete color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f,0.0f,-20.0f); //move along z-axis
    glRotatef(rotValue_X,1.0f,0.0,0.0); //rotate 30 degress around x-axis
    glRotatef(rotValue_Y,0.0,1.0f,0.0); //rotate 30 degress around y-axis
    glRotatef(rotValue_Z,0.0,0.0,1.0f); //rotate 30 degress around y-axis
    glScalef(1.0f, 2.5f, 0.15f); //resize cube

    //Add ambient light
    GLfloat ambientColor[] = {0.2, 0.2, 0.2, 1.0};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

    /* create 3D-Cube */
    glBegin(GL_QUADS);

    //front
    glColor3f(0.0f,0.0f,0.0f);

    glVertex3f(1.0,1.0,1.0);
    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);


    //back

    glColor3f(0.0f,0.0f,0.0f);

    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(1.0,-1.0,-1.0);


    //top
    glColor3f(0.2f,0.2f,0.2f);

    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(-1.0,1.0,-1.0);


    //bottom
//    glColor3f(0.7f,0.7f,0.7f);

    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,1.0);

    //right
//    glColor3f(0.7f,0.7f,0.7f);

    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);


    //left
//    glColor3f(0.7f,0.7f,0.7f);

    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,1.0,-1.0);


    glEnd();

}

void Smartphone::setX(float value) {
    rotValue_X = value;
}

void Smartphone::setY(float value) {
    rotValue_Y = value;
}

void Smartphone::setZ(float value) {
    rotValue_Z = value;
}
