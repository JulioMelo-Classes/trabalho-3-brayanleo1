#include "Level.h"
#include<time.h>

using namespace std;

Level::Level(){}//Para fazer depois

void Level::genFood(){
    srand(time(0));
    int xPos = rand() % dim.first;
    int yPos = rand() % dim.second;
    maze[xPos][yPos] = 'F'; //Inicialmente só pega a posição e coloca a comida
    foodPos.first = xPos;
    foodPos.second = yPos;
}

void Level::getDim(int x, int y){
    dim.first = x;
    dim.second = y;
}

bool Level::verifyDim(){
    bool correct = true;
    if(dim.first > 100 || dim.first < 0 || dim.second > 100 || dim.second < 0) {
        correct = false;
    }
    return correct;
}