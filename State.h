//
//  State.h
//  Teste
//
//  Created by Guilherme Gazzo on 21/08/14.
//  Copyright (c) 2014 Guilherme Gazzo. All rights reserved.
//

#ifndef __Teste__State__
#define __Teste__State__

#include <iostream>
#include "Rectangle.h"
#include "Game.h"
#define STATE_TELAINICIAL 0
#define STATE_JOGO 1
#define STATE_FIM 2
class Game;
class State{
protected:
    Game * game;
public:
    State(Game *);
    virtual void display(void);
    virtual void keyboard(unsigned char key);
    virtual void click(float x, float y, float xx, float yy, int state);
};

class StateInicio : public State{
    
public:
    StateInicio(Input *, Game * game);
    void display(void);
    void keyboard(unsigned char key);
private:
    void showModal(void);
    Modal *m;
    Input * name;
    
};





class StateGame : public State{
    
public:
    StateGame(Game * game);
    void display(void);
    //void keyboard(unsigned char key);
    void click(float x, float y, float xx, float yy, int state);
    int pontuacao;
private:
    Retangle ** r;
    void drawGrid(void);
    void newGrid(void);
    void hideElements(int r1, int g1, int b1);
    int tentativas;
    int * pontos;
};


class StateGameFinal : public State{
public:
    StateGameFinal(Game * game);
    void display(void);
private:
    Modal *m;
    Label *label;
};

#endif /* defined(__Teste__State__) */
