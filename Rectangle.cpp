//
//  Rectangle.cpp
//  Teste
//
//  Created by Guilherme Gazzo on 19/08/14.
//  Copyright (c) 2014 Guilherme Gazzo. All rights reserved.
//

#include "Rectangle.h"
Retangle::Retangle( unsigned char r, unsigned char g,unsigned char b ){
    this->setColors(r, g, b);
}

void Retangle::setColors(unsigned char r, unsigned char g, unsigned char b){
    this->r = r;
    this->g = g;
    this->b = b;
}

void Retangle::draw(float x, float y){
    glColor3ub (this->r, this->g, this->b);
    glBegin(GL_QUAD_STRIP);
        glVertex2d (x + 1, y + 1 );
        glVertex2d (x + 9, y  + 1);
        glVertex2d (x + 1 , y + 4);
        glVertex2d (x + 9 , y + 4);
    glEnd();
}
