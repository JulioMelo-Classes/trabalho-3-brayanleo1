#include "Player.h"

using namespace std;

Player::Player(){
    std::vector<char> dVazio;
    directions = dVazio;

    way = false;
}

void Player::find_solution(std::pair<int, int> snkPos, char snkDir, std::pair<int, int> foodPos, std::vector<std::vector<char>>::iterator maze){
    for(int i = 0; i < 3; i++){
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
                directions.push_back('U');
            } else if(snkDir == '^'){
                directions.push_back('D');
            } else if(snkDir == '>'){
                directions.push_back('L');
            } else {
                directions.push_back('R');
            }
            i = 3;
        } else { //Não vai bater, randomize o próximo passo
            int pos = rand() % possib.size();
            directions.push_back(possib[pos]);

            //Atualize a cobra aqui a depender do movimento escolhido
            if(possib[pos] == 'U'){
                snkPos.first = snkPos.first - 1;
                snkDir = 'v';
            } else if(possib[pos] == 'D'){
                snkPos.first = snkPos.first + 1;
                snkDir = '^';
            } else if(possib[pos] == 'L'){
                snkPos.second = snkPos.second - 1;
                snkDir = '>';
            } else {
                snkPos.second = snkPos.second + 1;
                snkDir = '<';
            }
        }
        
    }

    way = true; //Sempre retornará true (por agora)
}

char Player::next_move(){
    auto dir = directions[0];
    directions.erase(directions.begin());

    if(directions.size() == 0){
        way = false;
    }
    return dir;
}

bool Player::getWay(){
    return way;
}