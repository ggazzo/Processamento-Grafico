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
    Drawable(float,float);
};



class Modal : public Drawable
{
private:
    int childs = 0;

    vector <Drawable*> d;
public:
    unsigned char status;
    void _draw(float, float);
    void addChild(Drawable*);
    Modal(float,float);
};


#endif /* defined(__Teste__Modal__) */
