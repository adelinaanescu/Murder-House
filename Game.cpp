//
// Created by AsuszA on 27/05/2021.
//

#include "Game.h"
#include<cstdlib>
#include<iostream>
#include<string.h>
#include <time.h>
using namespace std;
int Game::Killer::getPositionk()
{
    return this->position;
}
void Game::Killer::setPositionk(int i) {
    this->position=i;
}


void Game::Player::go_to_room(int new_position) {
    this->position=new_position;
}


void Game::Player::setPosition(int i) {
    this->position = i;
}

int Game::Player::getPosition() {
    return this->position;
}

const char* Game::Player::getName()
{
    return this->name;
}

Game::Player::Player(const char* s){
    this->position = 5;
    this->name=new char[strlen(s)+1];
    strcpy(this->name,s);
    this->key=false;
}

Game::Killer::Killer(){
    this->position = 1;
}

Game::House::House()
    : hall{1}, living{2}, kitchen{3}, office{4}, bedroom{5}, storageroom{6}, bathroom{7}, closet{8}{
    srand(time(NULL));
    int random_number = rand() % 8 + 2;
    this->key=random_number;
}

int Game::House::getKeyh(){
    return this->key;
}

bool Game::Player::getKey(){
    return this->key;
}

void Game::Player::setKey(bool key){
    this->key = key;
}

Game::Game(const char* s):h(),k(),p(s){

}
