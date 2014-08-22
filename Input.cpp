//
//  Input.cpp
//  Teste
//
//  Created by Guilherme Gazzo on 19/08/14.
//  Copyright (c) 2014 Guilherme Gazzo. All rights reserved.
//

#include "Input.h"



Input::Input(string value, float x, float y) : Drawable(x,y){
    
    this->value = value;
}
void _write(string text){
    
    
    // don't forget to enable it later when you need it
    
    for(int i = 0; i < text.length(); i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text.data()[i]);
    }
    
   }
//float drawText(char *msg, int msgLength, float x, float y, float charWidth){
//    for (int i = 0; i < msgLength; i++) {
//        glRasterPos2d(x, y);
//        // A fonte, neste caso, é uma constante da GLUT. Que pode ser um param
//        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *(msg++)); // inc ponteiro msg
//        x += charWidth;
//    } 
//    return x;
//}
 void Input::_draw(float x, float y) {
     if(this->status){
         return;
     }
     this->rx = x + this->x;
     this->ry =y - this->y;
    glColor3ub (255, 255,255);
    glBegin(GL_QUAD_STRIP);
    glVertex2d (x + this->x, y - this->y);
    glVertex2d (x + 50 + this->x, y - this->y);
    glVertex2d (x + this->x, y - 10- this->y);
    glVertex2d (x + 50 + this->x, y - 10- this->y);
    glEnd();
    switch (this->status) {
        case 1:
            break;
        default: // normal
            glColor3ub (150, 150, 150);
            glBegin(GL_LINE_LOOP);
            glVertex2d (x + this->x, y - this->y);
            glVertex2d (x + this->x+ 50, y - this->y);
            glVertex2d (x + this->x+ 50 , y - 10 - this->y);
            glVertex2d (x + this->x, y - 10 - this->y);
            glColor3ub (0, 0, 0);
            glEnd();
            break;
    }
    glRasterPos2d(x+ 1+ this->x, y -7 - this->y );

    if(cursor){
        _write(this->value+'_');
    }else{
        _write(this->value);
    }
    this->cursor = !this->cursor;

}
void Input::addChar(char c){
    if(this->value.size() >= 14)
        return;
    this->value += c;
}
void Input::removeChar(){
    this->value = this->value.substr(0, this->value.size()-1);
}



Label::Label(string value, float x, float y) : Drawable(x,y){
    this->value = value;
}

void Label::_draw(float x, float y) {
    glColor3ub (0, 0, 0);
    glRasterPos2d(x, y - 5 - this->y);
    _write(this->value);
}

