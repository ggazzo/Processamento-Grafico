//
//  State.cpp
//  Teste
//
//  Created by Guilherme Gazzo on 21/08/14.
//  Copyright (c) 2014 Guilherme Gazzo. All rights reserved.
//

#include "State.h"


State::State(Game* game){
    this->game = game;
};
void State::display(){
    
}
void State::keyboard(unsigned char key){
    
}
void State::click(float x, float y, float xx, float yy, int state){

};

StateInicio::StateInicio(Input * name, Game * game): State(game){
    this->name = name;
    this->m = new Modal(50.0,50.0);
    this->m->addChild(name);
    this->m->addChild(new Label("insira o nome",1,10));
}
void StateInicio::showModal(void){
    this->m->draw(25.0,25.0);
};

void StateInicio::display(){
    this->showModal();
};

void StateInicio::keyboard(unsigned char key){
    if(key == 127){
        this->name->removeChar();
    }else if(key == 13){
        this->game->state_n = STATE_JOGO;
    }else{
        //printf("KEY: %d with mod: %s\n", key, m);
        this->name->addChar(key);
        glutPostRedisplay();
    }
};

StateGame::StateGame(Game * game) : State(game){
    this->r = new Retangle*[800];
    this->tentativas = 3;
    this->pontos = new int[3]{5,10,20};
    this->pontuacao = 0;
    for(int i = 0; i < 40;i++){
        for(int j= 0; j < 20 ; j++){
            r[i*20+j] = new Retangle(rand()%255,rand()%255,rand()%255);
        }
    }
};

void StateGame::click(float x, float y, float xx, float yy, int state){
   
    if(this->tentativas){
    
    
        if(r[799 - ( (int)y/5 )*20+(int)x/10 +1]->getVisible()){
            this->tentativas--;
            r[799 - ( (int)y/5 )*20+(int)x/10 +1]->setVisible(false);
            this->hideElements(r[799 - ( (int)y/5 )*20+(int)x/10 +1]->r, r[799 - ( (int)y/5 )*20+(int)x/10 +1]->g,r[799 - ( (int)y/5 )*20+(int)x/10 +1]->b);
            
        }
        
    }else {
    
        this->game->state_n = STATE_FIM;
    }
}


void StateGame::display(){
    this->drawGrid();
};

void StateGame::drawGrid(){
    for(int i = 0; i < 40;i++){
        for(int j= 0; j < 20 ; j++){
            this->r[i*20+j]->draw(j*10.0,200-i*5.0);
        }
    }
};
void StateGame::newGrid(){
    delete [] this->r;
    for(int i = 0; i < 40;i++){
        for(int j= 0; j < 20 ; j++){
            r[i*20+j] = new Retangle(rand()%255,rand()%255,rand()%255);
        }
    }

};
bool calcRange(int r1, int g1, int b1, int r2 , int g2, int b2 ){
    double tolerancia = .1;
    double dmax = sqrt(pow(255.0, 2)*3);
    // calcula dist‚ncia entre as duas cores
	double d = sqrt(pow(r1-r2, 2.0) + pow(g1-g2, 2.0) + pow(b1-b2, 2.0));
	double dd = d / dmax;
    return (dd <= tolerancia? true : false);
}

void StateGame::hideElements(int r1, int g1, int b1){
        for(int i = 0; i < 40;i++){
            for(int j= 0; j < 20 ; j++){
                r[i*20+j]->draw(j*10.0,200-i*5.0);
                if(calcRange(r1, g1, b1, r[i*20+j]->r, r[i*20+j]->g, r[i*20+j]->b)){
                    this->pontuacao += this->pontos[this->tentativas];
                    r[i*20+j]->setVisible(false);
                }
            }
        }
}





StateGameFinal::StateGameFinal(Game * game) : State(game){
    this->m = new Modal(50.0,50.0);
    //printf("%d",(((StateGame*)this->game->states[STATE_JOGO])->pontuacao));
    this->label = new Label("Pontos: "+to_string(((StateGame*)this->game->states[STATE_JOGO])->pontuacao),1,10);
    this->m->addChild(this->label);
}
void StateGameFinal::display(){
    this->label->value= "Pontos: "+to_string(((StateGame*)this->game->states[STATE_JOGO])->pontuacao);
    this->m->draw(10.0, 10.0);
};
