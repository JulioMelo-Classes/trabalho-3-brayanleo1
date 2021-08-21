#include "Snake.h"

using namespace std;

Snake::Snake(int mode_, int x, int y){
    bodySize = 0;
    mode = mode_;
    lives = 5;
    position.first = x;
    position.second = y;
}

void Snake::incrBody() {
    bodySize = bodySize + 1;
}

void Snake::resetBody(){
    bodySize = 0;
}

void Snake::moveUp(){
    position.second = position.second - 1;
}

void Snake::moveDown(){
    position.second = position.second + 1;
}

void Snake::moveLeft(){
    position.first = position.first - 1;
}

void Snake::moveRight(){
    position.first = position.first + 1;
}

void Snake::realocateSnake(int x, int y){
    position.first = x;
    position.second = y;
}

void Snake::removeLife(){
    lives = lives - 1;
}