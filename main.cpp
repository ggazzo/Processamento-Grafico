
#define W_WIDTH 600
#define W_HEIGHT 600

#include "Game.h"




/****************************************************************************************************************************/
#include <stdio.h>              /* I/O lib         ISOC  */
#include <stdlib.h>             /* Standard Lib    ISOC  */

/**********************************************************************************************************************************/
/* Apple puts GLUT into a framework named GLUT, while the rest of the world just sticks GLUT into the GL include directory... */
#include "includes.h"

#include <string>

#include <math.h>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <string>		// Necessário para usar strings



#include "Rectangle.h"
#include "Input.h"
#include "Modal.h"
using namespace std;

#define COLOR 1, .56 ,.7
#define LINES 4
#define COLLUMNS 4
#define WIDTH .3
#define HEIGHT .2
#define BORDER .2

#include "Objects.h"


Game game;

#define xi 0.0
#define xf 200.0
#define yi 0.0
#define yf 200.0
#define h yf-yi
#define w xf-xi





int states = 0;

void write(string text){
    glColor3f (0, 0, 0);
    for(int i = 0; i < text.length(); i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text.data()[i]);
    }
}




void display(void)
{
    /*  clear all pixels  */
    glClear (GL_COLOR_BUFFER_BIT);
    
   // drawGrid();
    game.display();
    glRasterPos2f(0.1,0.1);
    write("Guilherme e Carlos");
    glColor3f (1, 1, 1);
    //arco(.25, 180, 360, 1.5,1);
	//arco(.25, 0, 360, .5,1.75);
    
	//donut(.25, .1, 0, 180, .5,.75);
    
    /*  don't wait!
     *  start processing buffered OpenGL routines
     */
    glFlush ();
}



void init (void)
{/*  select clearing (background) color       */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    /*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(xi, xf, yi, yf, -200.00 , 0.0);
    
}

/*
 *  Declare initial window size, position, and display mode
 *  (single buffer and RGBA).  Open window with "hello"
 *  in its title bar.  Call initialization routines.
 *  Register callback function to display graphics.
 *  Enter main loop and process events.
 */

void keyboardUpCall(unsigned char key, int x, int y) {
} /* end func keyboardUpCall */

/**********************************************************************************************************************************/
/* Key presses */
void keyboardCall(unsigned char key, int x, int y) {
    char *m;
    int kbMod;
    /* Can only be called during mouse callback or kbd callback. */
    kbMod = glutGetModifiers();
    if(kbMod == GLUT_ACTIVE_SHIFT) {
        m = "SHIFT";
    } else if(kbMod == GLUT_ACTIVE_CTRL) {
        m = "CTRL";
    } else if(kbMod == GLUT_ACTIVE_ALT) {
        m = "ALR";
    } else {
        m = "NONE";
    } /* end if */
    game.keyboard(key);
    

} /* end func keyboardCall */

/**********************************************************************************************************************************/
/* Special Key presses */
void specialCall(int key, int x, int y) {
    if       (key == GLUT_KEY_F1       ) { printf("KEY: F1        ");
    } else if(key == GLUT_KEY_F2       ) { printf("KEY: F2        ");
    } else if(key == GLUT_KEY_F3       ) { printf("KEY: F3        ");
    } else if(key == GLUT_KEY_F4       ) { printf("KEY: F4        ");
    } else if(key == GLUT_KEY_F5       ) { printf("KEY: F5        ");
    } else if(key == GLUT_KEY_F6       ) { printf("KEY: F6        ");
    } else if(key == GLUT_KEY_F7       ) { printf("KEY: F7        ");
    } else if(key == GLUT_KEY_F8       ) { printf("KEY: F8        ");
    } else if(key == GLUT_KEY_F9       ) { printf("KEY: F9        ");
    } else if(key == GLUT_KEY_F10      ) { printf("KEY: F10       ");
    } else if(key == GLUT_KEY_F11      ) { printf("KEY: F11       ");
    } else if(key == GLUT_KEY_F12      ) { printf("KEY: F12       ");
    } else if(key == GLUT_KEY_LEFT     ) { printf("KEY: LEFT      ");
    } else if(key == GLUT_KEY_UP       ) { printf("KEY: UP        ");
    } else if(key == GLUT_KEY_RIGHT    ) { printf("KEY: RIGHT     ");
    } else if(key == GLUT_KEY_DOWN     ) { printf("KEY: DOWN      ");
    } else if(key == GLUT_KEY_PAGE_UP  ) { printf("KEY: PAGE_UP   ");
    } else if(key == GLUT_KEY_PAGE_DOWN) { printf("KEY: PAGE_DOWN ");
    } else if(key == GLUT_KEY_HOME     ) { printf("KEY: HOME      ");
    } else if(key == GLUT_KEY_END      ) { printf("KEY: END       ");
    } else if(key == GLUT_KEY_INSERT   ) { printf("KEY: INSERT    ");
    } else                               { printf("KEY: UNKNOWN   ");
    }
    printf("AT: (%d,%d)\n", x, y);
} /* end func specialCall */

/**********************************************************************************************************************************/
/* Mouse clicks */


void mouseCall(int button, int state, int x, int y) {
    char *b, *m;
    int kbMod;
    
  
    // width é a largura da janela em pixels (ver glViewport)
    float xx = x / (float) W_WIDTH; // normaliza click: xx = [0..1)
    // transformar xx em coordenadas da janela OpenGL:
    // xi é a coordenada inicial da janela e w = xf - xi (largura da janela)
    // Veja as definições de janela no comando glOrtho
    xx = xi + xx * w; // xx está em coordenadas do OpenGL (xx=[xi..xf));
    // para o y temos que considerar que o sistema OpenGL o y cresce para cima
    // e no da tela (que veio o click) o y cresce para baixo. Então, devemos
    // primeiro inverter o y e depois convertê-lo para janela OpenGL
    // height é a altura da janela em pixels (ver glViewport)
    y = W_HEIGHT - y;
    float yy = y / (float) W_HEIGHT; // normaliza click: yy = [0..1)
    // transformar xx em coordenadas da janela OpenGL:
    // xi é a coordenada inicial da janela e h = yf - yi (altura da janela)
    // Veja as definições de janela no comando glOrtho
    yy = yi + yy * h; // yy está em coordenadas do OpenGL (yy=[yi..yf));
    
    
    game.mouse(xx,yy,xx, yf - yy, state);
    
    
    
    if       (button == GLUT_LEFT_BUTTON)   {  /* MacOS X: Ctr-Click */
        b = "left button";
    } else if(button == GLUT_MIDDLE_BUTTON) {  /* MacOS X: Opt-Click */
        b = "middle button";
    } else if(button == GLUT_RIGHT_BUTTON)  {  /* MacOS X: Click */
        b = "right button";
    } else {
        b = "unknown";
    } /* end if/else */
    
    /* Can only be called during mouse callback or kbd callback.  Note that menu binding will capture clicks before they get here.
     Also note that on some platforms, MacOS X, mouse buttons may be emulated with various combinations of keys and the single mouse
     button -- so ctrl-click and alt-click may not be possible.  Shift-click is almost always possible.*/
    kbMod = glutGetModifiers();
    if(kbMod == GLUT_ACTIVE_SHIFT) {
        m = "SHIFT";
    } else if(kbMod == GLUT_ACTIVE_CTRL) {
        m = "CTRL";
    } else if(kbMod == GLUT_ACTIVE_ALT) {
        m = "ALR";
    } else {
        m = "NONE";
    } /* end if/else */
    
    if(state == GLUT_DOWN) {
        //printf("Mouse Depress: b(%s/%d/%s)@(%d,%d)\n", b, button, m, x, y);
    } else if(state == GLUT_UP) {
        //printf("Mouse Release: b(%s/%d/%s)@(%d,%d)\n", b, button, m, x, y);
        
        
        
    } else {
        printf("Unknown Mouse Click Event: b(%d/%s)@(%d,%d)\n", button, m, x, y);
    } /* end if/else */
}  /* end func mouseCall */

/**********************************************************************************************************************************/
/* Mouse move with button press */
void motionCall(int x, int y) {
    static int notInit;
    static int oldX;
    static int oldY;
    if(notInit) {
        //printf("MOTION: (%d,%d) -> (%d,%d)\n", oldX, oldY, x, y);
        oldX = x;
        oldY = y;
    } else {
       // printf("MOTION: (%d,%d)\n", x, y);
        oldX = x;
        oldY = y;
        notInit = 1;
    } /* end if/else */
} /* end func motionCall */

/* Mouse move with button press */
void joystickCall(unsigned int buttonMask, int x, int y, int z) {
    printf("JOYSTICK: %ud @ (%d,%d,%d)\n", buttonMask, x, y, z);
} /* end func joystickCall */

/*  Spaceball translation.. Passive. x, y, and z are normalized to [-1000,1000]*/
void spaceballMotionCall(int x, int y, int z) {
    printf("SPACEBALL TRN: (%d,%d,%d)\n", x, y, z);
} /* end func spaceballMotionCall */

/*  Spaceball translation.. Passive. x, y, and z are normalized to [-1000,1000]*/
void spaceballRotateFunc(int x, int y, int z) {
    printf("SPACEBALL ROT: (%d,%d,%d)\n", x, y, z);
} /* end func spaceballRotateFunc */

/**********************************************************************************************************************************/
/*  What to do for spaceball buttons.. */
void spaceballButtonFunc(int button, int state) {
    printf("SPACEBALL BUTTONS:  Button: %d    State: %d\n", button, state);
} /* end func spaceballButtonFunc */

/**********************************************************************************************************************************/
/**********************************************************************************************************************************/
void passiveMotionCall(int x, int y) {
    printf("PASSIVE MOTION: (%d,%d)\n", x, y);
} /* end func passiveMotionCall */

/**********************************************************************************************************************************/
void entryCall(int state) {
    if(state == GLUT_LEFT) {
        printf("ENTRY/EXIT EVENT: LEFT\n");
    } else if(state == GLUT_ENTERED) {
        printf("ENTRY/EXIT EVENT: ENTERED\n");
    } else {
        printf("UNKNOWN ERROR: glutEntryFunc\n");
    } /* end if/else */
} /* end func entryCall */
void timerCall(int value) {
    
    glutPostRedisplay();
    /* Note we have to start the timer up again after it fires. */
    glutTimerFunc(180 /*msecs*/, timerCall, 0 /*value to pass*/);
    /*printf("TIMER CALL\n");*/
} /* end func timerCall */


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    
    glutInitWindowSize (W_HEIGHT, W_WIDTH);
    glutInitWindowPosition (200, 200);
    glutCreateWindow ("hello");
    init ();
    
    glutKeyboardFunc(keyboardCall);
    
    /* Use the following to detect key releases
     glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
     glutKeyboardUpFunc(keyboardUpCall);
     */
    
    glutSpecialFunc(specialCall);
    glutMotionFunc(motionCall);
    /*  glutPassiveMotionFunc(passiveMotionCall); */
    glutMouseFunc(mouseCall);
    glutEntryFunc(entryCall);
    
    glutTimerFunc(50 /*msecs*/, timerCall, 0 /*value to pass*/);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;   /* ISO C requires main to return int. */
}