//
//  Objects.h
//  Teste
//
//  Created by Guilherme Gazzo on 12/08/14.
//  Copyright (c) 2014 Guilherme Gazzo. All rights reserved.
//

#ifndef Teste_Objects_h
#define Teste_Objects_h


void circle(GLfloat raio, GLfloat x , GLfloat y){
#define PI 3.1415926535898
	GLfloat circle_points = 100.0f;
	GLfloat angle;
	glBegin(GL_LINE_LOOP);
    for (int i = 0; i < circle_points; i++) {
        angle = 2*PI*i/circle_points;
        glVertex2f(cos(angle)*raio + x, sin(angle)*raio  + y);
    }
	glEnd();
}




void losango(GLfloat x, GLfloat y, GLfloat width, GLfloat height){
	GLfloat size = .2;
    
	glBegin(GL_POLYGON);
    glVertex3f (x, y + height / 2, 0.0);
    glVertex3f (x + width / 2 , y + height , 0.0);
    glVertex3f (x + width , y +  height / 2, 0.0);
    glVertex3f (x + width / 2, y , 0.0);
	glEnd();
	glFlush ();
}

void ladoLosangoEsquerdo(GLfloat x1, GLfloat y1,GLfloat x2, GLfloat y2, GLfloat height){
    
	glBegin(GL_POLYGON);
    glVertex3f (x1, y1, 0.0);
    glVertex3f (x1 , y1 - height, 0.0);
    glVertex3f (x2 , y2 - height , 0.0);
    glVertex3f (x2, y2 , 0.0);
	glEnd();
	glColor3f (0, 0, 0);
	glBegin(GL_LINE_LOOP);
    glVertex3f (x1, y1, 0.0);
    glVertex3f (x1 , y1 - height, 0.0);
    glVertex3f (x2 , y2 - height , 0.0);
    glVertex3f (x2, y2 , 0.0);
	glEnd();
}
void ladoLosangoDireito(GLfloat x1, GLfloat y1,GLfloat x2, GLfloat y2, GLfloat height){
	
	glBegin(GL_POLYGON);
    glVertex3f (x1, y1, 0.0);
    glVertex3f (x1 , y1 - height, 0.0);
    glVertex3f (x2 , y2 - height , 0.0);
    glVertex3f (x2, y2 , 0.0);
	glEnd();
	glColor3f (0, 0, 0);
	glBegin(GL_LINE_LOOP);
    glVertex3f (x1, y1, 0.0);
    glVertex3f (x1 , y1 - height, 0.0);
    glVertex3f (x2 , y2 - height , 0.0);
    glVertex3f (x2, y2 , 0.0);
	glEnd();
}

void losangulo25D(float x, float y, float width, float height, float r, float g, float b){
    glColor3f (r, g, b);
    losango(x, y, width, height);
    glColor3f (r*.5, g*.5, b*.5);
	ladoLosangoEsquerdo(x , y + height/ 2, x + width / 2, y, BORDER);
    glColor3f (r*.8, g*.8, b*.8);
	ladoLosangoDireito(x + width , y + height/ 2, x + width / 2, y, BORDER);
    
}

#endif
