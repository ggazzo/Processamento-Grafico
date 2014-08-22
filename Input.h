//
//  Input.h
//  Teste
//
//  Created by Guilherme Gazzo on 19/08/14.
//  Copyright (c) 2014 Guilherme Gazzo. All rights reserved.
//

#ifndef __Teste__Input__
#define __Teste__Input__

#include <iostream>
#include "includes.h"
#include <string>		// Necessário para usar strings
using std::string;
#include "Modal.h"

class Input : public Drawable
{
public:
    Input(string , float , float );
    string value;
    bool cursor;
    virtual void _draw(float, float) ;
    void addChar(char);
    void removeChar();
};

class Label : public Drawable
{
public:
    unsigned char status;
    string value;
    virtual void _draw(float, float) ;
    Label(string , float , float );
};

#endif /* defined(__Teste__Input__) */
