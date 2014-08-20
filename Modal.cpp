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
}

void Drawable::draw(float x, float y){
    this->_draw(this->x + x, this->y + y);
}

void Drawable::_draw(float x, float y){
    
}

Modal::Modal(float x, float y) : Drawable(x,y){
    
}

void Modal::addChild(Drawable *child){
    this->d.push_back(child);
    
}

void Modal::_draw(float x, float y){
    glColor3ub (200, 200,200);
    glBegin(GL_QUAD_STRIP);
    glVertex2d (x , y );
    glVertex2d (x + 100, y );
    glVertex2d (x , y + 50);
    glVertex2d (x + 100 , y + 50);
    glEnd();
    
    for (int i = 0; i < this->d.size(); ++i) {
        this->d[i]->draw(x,y);
    }


}
