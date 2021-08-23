#include "Level.h"
#include<time.h>

using namespace std;

Level::Level(){}

void Level::makeLab(std::vector<std::string>::iterator labIt, int foods){
    foodStatus.first = 0;
    foodStatus.second = foods;
    std::vector<std::vector<char>> lab;
    for(int x = 0; x != dim.first; x++) {
        std::vector<char> linha;
        for(int y = 0; y != dim.second; y++) {
            linha.push_back((*labIt)[y]);
            if((*labIt)[y] == '*'){
                initPos.first = x;
                initPos.second = y;
            }
        }
        
        ++labIt;
        lab.push_back(linha);
    }

    maze = lab;
}

void Level::genFood(){
    srand(time(0));
    int xPos = rand() % dim.first;
    int yPos = rand() % dim.second;
    maze[xPos][yPos] = 'F'; //Inicialmente só pega a posição e coloca a comida
    foodPos.first = xPos;
    foodPos.second = yPos;
}

void Level::setDim(int x, int y){
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

//Eat and Move

void Level::printMaze(std::pair<int, int> snkPos, char snkDir){
    for (int i = 0; i != dim.first; i++) {
        for(int j = 0; j != dim.second; j++) {
            if(snkPos.first == i && snkPos.second == j) {
                cout << snkDir;
            } else {
                cout << maze[i][j];
            }
        }
        cout << endl;
    }
    
}

std::pair<int, int> Level::getInitPos(){
    return initPos;
}