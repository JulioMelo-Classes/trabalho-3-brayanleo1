#include "Level.h"
#include <utility>

using namespace std;

Level::Level(){}

bool Level::makeLab(std::vector<std::string>::iterator labIt, int foods){
    foodStatus.first = 0;
    foodStatus.second = foods;
    std::vector<std::vector<char>> lab;
    int labLiv = 0;
    for(int x = 0; x != dim.first; x++) {
        std::vector<char> linha;
        for(int y = 0; y != dim.second; y++) {
            if((*labIt)[y] == '*'){ //Se for posição inicial do mapa, bote vazio e pegue posição
                initPos.first = x;
                initPos.second = y;
                linha.push_back(' ');
            } else { //Se não, bote o que está no mapa mesmo
                linha.push_back((*labIt)[y]);
            }

            if((*labIt)[y] == ' '){
                labLiv = labLiv + 1;
            }
        }
        
        ++labIt;
        lab.push_back(linha);
    }

    maze = lab;
    if(labLiv <= foods + 1){
        return false;
    }
    return true;
}

void Level::genFood(std::pair <int, int> snkPos){
    if(foodStatus.first != foodStatus.second){
      int xPos = rand() % dim.first;
      int yPos = rand() % dim.second;
      bool posVal = false;
      while(posVal == false) {
          if(maze[xPos][yPos] == ' ') {
              if(xPos == snkPos.first) {
                  if(yPos != snkPos.second){
                      posVal = true;
                  }
              } else {
                  posVal = true;
              }
          }
          
          if(posVal == false) {
              xPos = rand() % dim.first;
              yPos = rand() % dim.second;
          }
      }
      foodPos.first = xPos;
      foodPos.second = yPos;
    }
}

void Level::setDim(int x, int y){
    dim.first = x;
    dim.second = y;
}

bool Level::verifyDim(){
    bool correct = true;
    if(dim.first > 100 || dim.first <= 0 || dim.second > 100 || dim.second <= 0) {
        correct = false;
    }
    return correct;
}

bool Level::eatFood(std::pair<int, int> snkPos, char snkDir, int mode){
    bool comeu = false;
    if(foodPos == snkPos){//Posição da cobra = Posição da comida
    comeu = true;
        if(mode == 1) {//Modo da cobra igual a 1 (com cauda)
            if(snkDir == 'v') {
                int x = snkPos.first + 1;//Pos abaixo
                auto b = make_pair(x, snkPos.second);
                body.push_back(b);//Bota a posição do corpo para mais recente
                maze[x][snkPos.second] = 'O';//Bota o corpo no mapa na pos indicada
            } else if(snkDir == '^') {
                int x = snkPos.first - 1;//Pos acima
                auto b = make_pair(x, snkPos.second);
                body.push_back(b);//Bota a posição do corpo para mais recente
                maze[x][snkPos.second] = 'O';//Bota o corpo no mapa na pos indicada
            } else if(snkDir == '>') {
                int y = snkPos.second + 1;//Pos a direita
                auto b = make_pair(snkPos.first, y);
                body.push_back(b);//Bota a posição do corpo para mais recente
                maze[snkPos.first][y] = 'O';//Bota o corpo no mapa na pos indicada
            } else {
                int y = snkPos.second - 1;//Pos a esquerda
                auto b = make_pair(snkPos.first, y);
                body.push_back(b);//Bota a posição do corpo para mais recente
                maze[snkPos.first][y] = 'O';//Bota o corpo no mapa na pos indicada
            }
        }
        foodStatus.first = foodStatus.first + 1; //Registra comida consumida
        genFood(snkPos); //Gera nova comida
    }
    return comeu;
}

void Level::move(std::pair<int, int> snkPos, char snkDir){
    if(snkDir == 'v') {
        int x = snkPos.first + 1;//Pos abaixo
        auto b = make_pair(x, snkPos.second);
        body.push_back(b);//Bota a posição do corpo para mais recente
        maze[x][snkPos.second] = 'O';//Bota o corpo no mapa na pos indicada
    } else if(snkDir == '^') {
        int x = snkPos.first - 1;//Pos acima
        auto b = make_pair(x, snkPos.second);
        body.push_back(b);//Bota a posição do corpo para mais recente
        maze[x][snkPos.second] = 'O';//Bota o corpo no mapa na pos indicada
    } else if(snkDir == '>') {
        int y = snkPos.second + 1;//Pos a direita
        auto b = make_pair(snkPos.first, y);
        body.push_back(b);//Bota a posição do corpo para mais recente
        maze[snkPos.first][y] = 'O';//Bota o corpo no mapa na pos indicada
    } else {
        int y = snkPos.second - 1;//Pos a esquerda
        auto b = make_pair(snkPos.first, y);
        body.push_back(b);//Bota a posição do corpo para mais recente
        maze[snkPos.first][y] = 'O';//Bota o corpo no mapa na pos indicada
    }

    //Remover última parte do corpo
    maze[body[0].first][body[0].second] = ' '; //Remove do mapa
    body.erase(body.begin()); //Remove do vetor corpo o mais antigo(primeiro)
}

void Level::printMaze(std::pair<int, int> snkPos, char snkDir){
    for (int i = 0; i != dim.first; i++) {
        for(int j = 0; j != dim.second; j++) {
            if(snkPos.first == i && snkPos.second == j) {
                cout << snkDir;
            } else if(foodPos.first == i && foodPos.second == j) {
                cout << 'F';
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

void Level::printHUD(int vidas){
    cout << "Quantidade de vidas: " << vidas << "| Já foram consumidas " << foodStatus.first << " de " << foodStatus.second << " desse nível";
}

std::pair<int, int> Level::getFoodPos(){
    return foodPos;
}

std::vector<std::vector<char>>::iterator Level::getMazeIt(){
    return maze.begin();
}

bool Level::verifyCrash(std::pair <int, int> snkPos){
    bool bateu = false;
        if(maze[snkPos.first][snkPos.second] != ' '){
            bateu = true;
        }
    return bateu;
}

void Level::resetFood(){
    foodStatus.first = 0;
    if(body.size() != 0) {
        int i = 0;
        while(i != body.size()){
            maze[body[0].first][body[0].second] = ' ';
            body.erase(body.begin());
        }
    }
}

bool Level::verifyWin(){
    bool status = false;

    if(foodStatus.first == foodStatus.second){
        status = true;
    }

    return status;
}