//
//  Rectangle.h
//  Teste
//
//  Created by Guilherme Gazzo on 19/08/14.
//  Copyright (c) 2014 Guilherme Gazzo. All rights reserved.
//

#ifndef __Teste__Rectangle__
#define __Teste__Rectangle__

#include <iostream>
#include "includes.h"
class Retangle
{
private:
    bool visible = true;

public:
    unsigned char r;
    unsigned char g;
    unsigned char b;
    void setVisible(bool);
    bool getVisible(void);
    void setColors(unsigned  char ,unsigned char , unsigned char );
    Retangle(unsigned  char ,unsigned char , unsigned char );
    
    void draw(float, float);
};
#endif /* defined(__Teste__Rectangle__) */
