//
//  Modal.cpp
//  Teste
//
//  Created by Guilherme Gazzo on 19/08/14.
//  Copyright (c) 2014 Guilherme Gazzo. All rights reserved.
//

#include "Modal.h"
//
//  Input.cpp
//  Teste
//
//  Created by Guilherme Gazzo on 19/08/14.
//  Copyright (c) 2014 Guilherme Gazzo. All rights reserved.
//


#include "Input.h"

Drawable::Drawable(float x, float y){
    this->x = x;
    this->y = y;
    this->w = 100;
    this->h = 50;
}

void Drawable::draw(float x, float y){
    /*
     Pega o y e soma o h para ter a posição por cima
     */
    
    
    
    this->_draw( x, y);
}

void Drawable::_draw(float x, float y){
    
}

//Drawable *Drawable::testClick(float x, float y){
//    if(
//       ( x >= this->rx && x <= this->rx + this->w)
//       ){
//        if(
//       (y >= this->ry && y <= this->ry + this->h)){
//            this->status = 1;
//            return this;
//        }}
//    this->status = 0;
//    return NULL;
//}




Modal::Modal(float x, float y) : Drawable(x,y){
    
}

void Modal::addChild(Drawable *child){
    this->d.push_back(child);
    
}

void Modal::draw(float x, float y){
    /*
     Pega o y e soma o h para ter a posição por cima
     */
    
    
    
    
    this->_draw(this->x + x, this->y + y);
}

void Modal::_draw(float x, float y){
    this->rx = x ;
    this->ry =y ;
    glColor3ub (200, 200,200);
    glBegin(GL_QUAD_STRIP);
    glVertex2d (x , y );
    glVertex2d (x + this->w, y );
    glVertex2d (x , y + this->x);
    glVertex2d (x + this->w , y + this->x);
    glEnd();
    
    for (int i = 0; i < this->d.size(); ++i) {
        this->d[i]->draw(x, this->h + y);
    }

}
