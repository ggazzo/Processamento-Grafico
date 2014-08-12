/* -*- Mode:C; Coding:us-ascii-unix; fill-column:132 -*- */
/**********************************************************************************************************************************/
/**
 @file      interact.c
 @author    Mitch Richling <http://www.mitchr.me/>
 @Copyright Copyright 1997 by Mitch Richling.  All rights reserved.
 @brief     How to get input and process it with GLUT.@EOL
 @Keywords  input mouse keyboard glut
 @Std       C99
 
 This little program demonstrates how to get input from the keyboard and detect various mouse events.  Also demonstrated are
 several callbacks: display callback, timer callbacks, and the idle callback.
 ***********************************************************************************************************************************/

/**********************************************************************************************************************************/
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
using namespace std;

#define COLOR 1, .56 ,.7
#define LINES 4
#define COLLUMNS 4
#define WIDTH .3
#define HEIGHT .2
#define BORDER .2

#include "Objects.h"
void drawLand(GLfloat x, GLfloat y, float r, float g, float b, int * block){
    
    GLfloat x1 , y1;
    
    
    for (int i = LINES ; i > 0 ; i--) {
        //x -= .15;
        y1 = y + HEIGHT * i / 2 ;
        x1 = x - WIDTH *i / 2;
        
        for (int j = COLLUMNS ; j > 0 ; j--) {
            
            x1 -= WIDTH / 2  ;
            y1 -= (HEIGHT /2 ) ;
            if( *block++ > 0){
                losangulo25D( x1 , y1 , WIDTH , HEIGHT, COLOR);
            }
        }
        
    }
    
    
    
}

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
    
    glRasterPos2f(0.1,0.1);
    
    
    
    int array2 [4][4] = {1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1};
    int array1 [4][4] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    
    write("Guilherme e Carlos");

    
    drawLand(1.5, .9 - BORDER * 2, COLOR, array1[0]);
    
    drawLand(1.5, .9 - BORDER, COLOR, array1[0]);
    
    drawLand(1.5, .9, COLOR, array2[0]);
    /*  draw white polygon (rectangle) with corners at
     *  (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
     */
    //    glColor3f (1.0, 1.0, 1.0);
    
    //	circle(0.3 , 0.1, 0.2);
    //	losangulo25D( 0.55 , 0.65 , .3 , .1, 1,.56,.7);
	
	
	
	//bloco( 0.4 , 0.6 , .3 , .1, .05);
	
	
    
    /*  don't wait!
     *  start processing buffered OpenGL routines
     */
    glFlush ();
}



void init (void)
{
    /*  select clearing (background) color       */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    
    /*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 2.0, 0.0, 2.0, -2.0, 2.0);
}

/*
 *  Declare initial window size, position, and display mode
 *  (single buffer and RGBA).  Open window with "hello"
 *  in its title bar.  Call initialization routines.
 *  Register callback function to display graphics.
 *  Enter main loop and process events.
 */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600, 600);
    glutInitWindowPosition (200, 200);
    glutCreateWindow ("hello");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;   /* ISO C requires main to return int. */
}