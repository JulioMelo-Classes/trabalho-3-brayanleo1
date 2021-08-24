#include "Snake.h"

using namespace std;

Snake::Snake(){}

Snake::Snake(int x, int y){
    lives = 5;
    position.first = x;
    position.second = y;
    direction = 'v';
}

void Snake::moveUp(){
    position.first = position.first - 1;
    direction = 'v';
}

void Snake::moveDown(){
    position.first = position.first + 1;
    direction = '^';
}

void Snake::moveLeft(){
    position.second = position.second - 1;
    direction = '>';
}

void Snake::moveRight(){
    position.second = position.second + 1;
    direction = '<';
}

void Snake::realocateSnake(int x, int y){
    position.first = x;
    position.second = y;
}

void Snake::removeLife(){
    lives = lives - 1;
}

void Snake::lookUp(){
    direction = 'v';
}

std::pair<int, int> Snake::getPos(){
    return position;
}


char Snake::getDirection(){
    return direction;
}

int Snake::getLives(){
    return lives;
}

void Snake::resetLives(){
    lives = 5;
}