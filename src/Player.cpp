#include "Player.h"
#include <algorithm>//std::find

using namespace std;

Player::Player(){
    std::vector<char> dVazio;
    directions = dVazio;

    way = false;
}

void Player::find_solution(std::pair<int, int> snkPos, char snkDir, std::pair<int, int> foodPos, std::vector<std::vector<char>> maze){
    bool sol = false;
    auto msol = maze;

    vector<pair<int,int>> checkPos; //posições a se checar
    checkPos.push_back(make_pair(snkPos.first - 1, snkPos.second));
    checkPos.push_back(make_pair(snkPos.first + 1, snkPos.second));
    checkPos.push_back(make_pair(snkPos.first, snkPos.second - 1));
    checkPos.push_back(make_pair(snkPos.first, snkPos.second + 1));

    //Eliminar posição não importante para haver solução
    if(snkDir == 'v') { //Apague o segundo
        checkPos.erase(checkPos.begin() + 1);
    } else if(snkDir == '^') {//Apague o primeiro
        checkPos.erase(checkPos.begin());
    } else if(snkDir == '<') {//Apague o terceiro
        checkPos.erase(checkPos.begin() + 2);
    }
    //Não apaga o quarto pois só serão olhados os 3 primeiros
    

    //Enquanto os espaços importantes forem vazios ou enquanto não houver solução
    while(sol == false && (msol[checkPos[0].first][checkPos[0].second] == ' ' || msol[checkPos[1].first][checkPos[1].second] == ' ' || msol[checkPos[2].first][checkPos[2].second] == ' ')){
        auto mtest(msol); //Maze para teste de solução atual
        auto it = mtest.begin();
        auto spostest = snkPos; //Posição da cobra para testes
        auto sdirtest = snkDir; //Direção da cobra para testes

        auto res = lookAround(spostest, sdirtest, foodPos, it);//Pega uma cordenada, seja um local sem saída ou o local da comida

        if(res == foodPos){//Posição da comida encontrada
            sol = true; //Bora sair do laço, a sequência já está preparada
        } else {//Posição de local sem saída, bora tirar ele da solução
            directions.clear();
            msol[res.first][res.second] = '#';
        }
    }

    way = sol; //Bool que representa se há ou não solução
}

char Player::next_move(std::pair<int, int> snkPos, char snkDir, std::vector<std::vector<char>>::iterator maze){

    if(directions.size() != 0){ //Há uma solução
        auto dir = directions[0];
        directions.erase(directions.begin());

        if(directions.size() == 0){
            way = false;
        }
        
        return dir;
    }

    //Não há solução
    char dir; //Direção que será seguida

    //Quais são as possíveis regiões?
    std::vector<char> possib;
    if(maze[snkPos.first - 1][snkPos.second] == ' ') {
        possib.push_back('U');
    }

    if(maze[snkPos.first + 1][snkPos.second] == ' ') {
        possib.push_back('D');
    }

    if(maze[snkPos.first][snkPos.second - 1] == ' ') {
        possib.push_back('L');
    }

    if(maze[snkPos.first][snkPos.second + 1] == ' ') {
        possib.push_back('R');
    }

    if(snkDir == 'v'){//Olhando para cima
        auto pos = std::find(possib.begin(), possib.end(), 'D');
        if(pos != possib.end()) {
            possib.erase(pos);
        }
    } else if(snkDir == '^'){//Olhando para baixo
        auto pos = std::find(possib.begin(), possib.end(), 'U');
        if(pos != possib.end()) {
            possib.erase(pos);
        }
    } else if(snkDir == '>'){//Olhando para a esquerda
        auto pos = std::find(possib.begin(), possib.end(), 'R');
        if(pos != possib.end()) {
            possib.erase(pos);
        }
    } else {//Olhando para a direita
        auto pos = std::find(possib.begin(), possib.end(), 'L');
        if(pos != possib.end()) {
            possib.erase(pos);
        }
    }

    if(possib.size() == 0) { //Vai bater, siga reto e bora lá
        if(snkDir == 'v') {
            dir = 'U';
        } else if(snkDir == '^'){
            dir = 'D';
        } else if(snkDir == '>'){
            dir = 'L';
        } else {
            dir = 'R';
        }
    } else { //Não vai bater, randomize o próximo passo
        int pos = rand() % possib.size();
        dir = possib[pos];
    }
   return dir;
}

bool Player::getWay(){
    return way;
}

void Player::resetCommands(){
    directions.clear();
    way = false;
}

std::pair<int, int> Player::lookAround(std::pair<int, int> snkPos, char snkDir, std::pair<int, int> foodPos, std::vector<std::vector<char>>::iterator maze){
    if(snkPos == foodPos){//A cobra tá na comida
        return snkPos;
    }

    //A cobra ainda não chegou na comida
    std::vector<char> possib;
    if(maze[snkPos.first - 1][snkPos.second] == ' ') {
        possib.push_back('U');
    }

    if(maze[snkPos.first + 1][snkPos.second] == ' ') {
        possib.push_back('D');
    }

    if(maze[snkPos.first][snkPos.second - 1] == ' ') {
        possib.push_back('L');
    }

    if(maze[snkPos.first][snkPos.second + 1] == ' ') {
        possib.push_back('R');
    }

    if(snkDir == 'v'){//Olhando para cima
        auto pos = std::find(possib.begin(), possib.end(), 'D');
        if(pos != possib.end()) {
            possib.erase(pos);
        }
    } else if(snkDir == '^'){//Olhando para baixo
        auto pos = std::find(possib.begin(), possib.end(), 'U');
        if(pos != possib.end()) {
            possib.erase(pos);
        }
    } else if(snkDir == '>'){//Olhando para a esquerda
        auto pos = std::find(possib.begin(), possib.end(), 'R');
        if(pos != possib.end()) {
            possib.erase(pos);
        }
    } else {//Olhando para a direita
        auto pos = std::find(possib.begin(), possib.end(), 'L');
        if(pos != possib.end()) {
            possib.erase(pos);
        }
    }

    if(possib.size() != 0){//Tiver caminho a percorrer
        maze[snkPos.first][snkPos.second] = '#';//Marcar como caminho já verificado no teste atual

        if(foodPos.first < snkPos.first){ //Comida acima
        if(std::find(possib.begin(), possib.end(), 'U') != possib.end()) {//Posso ir para cima?
            directions.push_back('U');
            snkPos.first = snkPos.first - 1;
            snkDir = 'v';
            return lookAround(snkPos, snkDir, foodPos, maze);
        } else if(std::find(possib.begin(), possib.end(), 'L') != possib.end()) {//Para a esquerda?
            directions.push_back('L');
            snkPos.second = snkPos.second - 1;
            snkDir = '>';
            return lookAround(snkPos, snkDir, foodPos, maze);
        } else if(std::find(possib.begin(), possib.end(), 'R') != possib.end()) {//Para a direita?
            directions.push_back('R');
            snkPos.second = snkPos.second + 1;
            snkDir = '<';
            return lookAround(snkPos, snkDir, foodPos, maze);
        } else {//Para baixo então
            directions.push_back('D');
            snkPos.first = snkPos.first + 1;
            snkDir = '^';
            return lookAround(snkPos, snkDir, foodPos, maze);
        }

    } else if(foodPos.first > snkPos.first){ //Comida abaixo
        if(std::find(possib.begin(), possib.end(), 'D') != possib.end()) {//Posso ir para baixo?
            directions.push_back('D');
            snkPos.first = snkPos.first + 1;
            snkDir = '^';
            return lookAround(snkPos, snkDir, foodPos, maze);
        } else if(std::find(possib.begin(), possib.end(), 'L') != possib.end()) {//Para a esquerda?
            directions.push_back('L');
            snkPos.second = snkPos.second - 1;
            snkDir = '>';
            return lookAround(snkPos, snkDir, foodPos, maze);
        } else if(std::find(possib.begin(), possib.end(), 'R') != possib.end()) {//Para a direita?
            directions.push_back('R');
            snkPos.second = snkPos.second + 1;
            snkDir = '<';
            return lookAround(snkPos, snkDir, foodPos, maze);
        } else {//Para cima então
            directions.push_back('U');
            snkPos.first = snkPos.first - 1;
            snkDir = 'v';
            return lookAround(snkPos, snkDir, foodPos, maze);
        }
    } else if(foodPos.second < snkPos.second){ //Comida a esquerda
        if(std::find(possib.begin(), possib.end(), 'L') != possib.end()) {//Posso ir para a esquerda?
            directions.push_back('L');
            snkPos.second = snkPos.second - 1;
            snkDir = '>';
            return lookAround(snkPos, snkDir, foodPos, maze);
        } else if(std::find(possib.begin(), possib.end(), 'U') != possib.end()) {//Para cima?
            directions.push_back('U');
            snkPos.first = snkPos.first - 1;
            snkDir = 'v';
            return lookAround(snkPos, snkDir, foodPos, maze);
        } else if(std::find(possib.begin(), possib.end(), 'D') != possib.end()) {//Para baixo?
            directions.push_back('D');
            snkPos.first = snkPos.first + 1;
            snkDir = '^';
            return lookAround(snkPos, snkDir, foodPos, maze);
        } else {//Para a direita então
            directions.push_back('R');
            snkPos.second = snkPos.second + 1;
            snkDir = '<';
            return lookAround(snkPos, snkDir, foodPos, maze);
        }
    } else { //Comida a direita
        if(std::find(possib.begin(), possib.end(), 'R') != possib.end()) {//Posso ir para a esquerda?
            directions.push_back('R');
            snkPos.second = snkPos.second + 1;
            snkDir = '>';
            return lookAround(snkPos, snkDir, foodPos, maze);
        } else if(std::find(possib.begin(), possib.end(), 'U') != possib.end()) {//Para cima?
            directions.push_back('U');
            snkPos.first = snkPos.first - 1;
            snkDir = 'v';
            return lookAround(snkPos, snkDir, foodPos, maze);
        } else if(std::find(possib.begin(), possib.end(), 'D') != possib.end()) {//Para baixo?
            directions.push_back('D');
            snkPos.first = snkPos.first + 1;
            snkDir = '^';
            return lookAround(snkPos, snkDir, foodPos, maze);
        } else {//Para a direita então
            directions.push_back('L');
            snkPos.second = snkPos.second - 1;
            snkDir = '<';
            return lookAround(snkPos, snkDir, foodPos, maze);
        }
    }
    }

    //Não tem caminho a percorrer
    return snkPos;
}