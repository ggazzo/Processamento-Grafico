//
//  Slider.h
//  Teste
//
//  Created by Guilherme Gazzo on 20/08/14.
//  Copyright (c) 2014 Guilherme Gazzo. All rights reserved.
//

#ifndef __Teste__Slider__
#define __Teste__Slider__

#include <iostream>
#include "includes.h"
#include "Modal.h"
class Slider : public Drawable
{
public:
    Slider(float , float );
    float value;
    float min;
    float max;
    void _draw(float,float);
};


#endif /* defined(__Teste__Slider__) */
