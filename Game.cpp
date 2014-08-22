//
//  Game.cpp
//  Teste
//
//  Created by Guilherme Gazzo on 21/08/14.
//  Copyright (c) 2014 Guilherme Gazzo. All rights reserved.
//

#include "Game.h"

Game::Game(){
    this->name = new Input("Player1",5,20);
    states.push_back(new StateInicio(this->name, this));
    states.push_back(new StateGame(this));
    states.push_back(new StateGameFinal(this));
    
}



void Game::click(float x, float y, float xx, float yy, int state){
    this->states[this->state_n]->click(x,y,xx,yy,state);
}

void Game::mouse(float x, float y, float xx, float yy, int state){
    this->click(x,y,xx,yy,state);
}

void Game::keyboard(unsigned char key){
    this->states[this->state_n]->keyboard(key);
}

void Game::display(){
    this->states[this->state_n]->display();
}
