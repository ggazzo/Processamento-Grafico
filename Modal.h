//
//  Modal.h
//  Teste
//
//  Created by Guilherme Gazzo on 19/08/14.
//  Copyright (c) 2014 Guilherme Gazzo. All rights reserved.
//

#ifndef __Teste__Modal__
#define __Teste__Modal__

#include <iostream>
#include <vector>
using namespace std;

class Drawable{
public:
    virtual void draw(float, float);
    virtual void _draw(float, float);
    float x;
    float y;
    float rx;
    float ry;
    float h;
    float w;
    int status = 0;
    Drawable(float,float);
    //Drawable *testClick(float , float);
   // virtual void click(void (*f)(void), float, float);
};

//void Drawable::click(void (*f)(void), float x, float y){
//    f();
//}

class Modal : public Drawable
{
private:
    int childs = 0;
public:
    vector <Drawable*> d;
    unsigned char status;
    void _draw(float, float);
    void draw(float, float);
    void addChild(Drawable*);
    Modal(float,float);
};


#endif /* defined(__Teste__Modal__) */
