//
//  Slider.cpp
//  Teste
//
//  Created by Guilherme Gazzo on 20/08/14.
//  Copyright (c) 2014 Guilherme Gazzo. All rights reserved.
//

#include "Slider.h"

Slider::Slider(float x, float y) : Drawable(x,y){
    
}
void Slider::_draw(float x, float y) {
    
    int value = 30;
    
    
    /*
     valor
     */
    
    
    glColor3ub (255, 255, 255);
    glBegin(GL_QUAD_STRIP);
    glVertex2d (x + this->x, y - this->y);
    glVertex2d (x + 100 + this->x, y - this->y);
    glVertex2d (x +  this->x, y - 5- this->y);
    glVertex2d (x + 100 + this->x, y - 5 - this->y);
    
    glEnd();
    
    glColor3ub (255, 0, 0);
    glBegin(GL_QUAD_STRIP);
    glVertex2d (x + this->x, y - this->y);
    glVertex2d (x + value + this->x, y - this->y);
    glVertex2d (x +  this->x, y - 5- this->y);
    glVertex2d (x + value + this->x, y - 5 - this->y);
    
    glEnd();
    
    /*
     
     Contorno
     
     */
    
    
    glColor3ub (150, 150, 150);
    glBegin(GL_LINE_LOOP);
    glVertex2d (x + this->x, y - this->y);
    glVertex2d (x + this->x+ 100, y - this->y);
    glVertex2d (x + this->x+ 100 , y - 5 - this->y);
    glVertex2d (x + this->x, y - 5 - this->y);
    glColor3ub (0, 0, 0);
    glEnd();
    
    
    
}
