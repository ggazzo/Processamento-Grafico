//
//  Game.h
//  Teste
//
//  Created by Guilherme Gazzo on 20/08/14.
//  Copyright (c) 2014 Guilherme Gazzo. All rights reserved.
//

#ifndef Teste_Game_h
#define Teste_Game_h
#include "Input.h"

#include <math.h>
#include "State.h"
class State;
class Game {
public:
    Game(void);
    void display(void);
    void keyboard(unsigned char);
    void mouse(float, float ,float, float, int);
    int state_n;
    vector<State *> states;
private:
    
    Drawable *clicked;
    Input *name;
    void click(float , float ,float, float, int);
    

};
#endif
