#include "SnakeGame.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include<time.h>

#include <chrono> //por causa do sleep
#include <thread> //por causa do sleep

using namespace std;

SnakeGame::SnakeGame(char *arquivo_[]){
    choice = "";
    frameCount = 0;
    Arquivo aq(arquivo_[1]);
    arquivo = aq; //Cria um arquivo
    srand(time(0));
    Player player_;
    player = player_;
    score = 1000;
    levelsGone = 0;
    initialize_game(arquivo_[2][0]);
}

void SnakeGame::initialize_game(int mode_){
    //Carregar arquivo
    auto r = arquivo.lerLinhas();
    auto i = r.begin();
    if(mode_ == 49) {//Representação de 1
        mode = 1;
    } else {
        mode = 0;
    }

    //Carregar nível ou níveis
    while(i != r.end()) {
        Level lev;
        std::string campoAtual = *i;
        stringstream ss1;

        ss1<<campoAtual;
        int linhas;
        ss1 >> linhas;
        int colunas;
        ss1 >> colunas;
        int comidas;
        ss1 >> comidas;

        ++i;
        lev.setDim(linhas, colunas);

        if(lev.verifyDim()){//Verificando se as dimensões são válidas
            bool gerou = lev.makeLab(i, comidas);
            if(gerou == true && mode == 1){
                lev.genFood(snake.getPos());
                mazes.push_back(lev);
            } else if(mode == 0){
                lev.genFood(snake.getPos());
                mazes.push_back(lev);
            }
            
        }

    }

    Snake snk(mazes[levelsGone].getInitPos().first, mazes[levelsGone].getInitPos().second);
    snake = snk;

    state = RUNNING;
}



void SnakeGame::process_actions(){
    //processa as entradas do jogador de acordo com o estado do jogo
    //o jogo tem 5 estados, WAITING_USER, RUNNING, GAME_OVER, DEATH e NEXT_LEVEL.
    //no caso deste trabalho temos 2 tipos de entrada, uma que vem da classe Player, como resultado do processamento da IA
    //outra vem do próprio usuário na forma de uma entrada do teclado.
    switch(state){
        case WAITING_USER: //o jogo bloqueia aqui esperando o usuário digitar a escolha dele
            cin>>std::ws>>choice;
            break;
        case RUNNING: //o jogo recebe informações de Player(IA)
            {
                if(player.getWay() == false){
                    player.find_solution(snake.getPos(), snake.getDirection(), mazes[levelsGone].getFoodPos(), mazes[levelsGone].getMazeRef());
                }

                nextMove = player.next_move(snake.getPos(), snake.getDirection(), mazes[levelsGone].getMazeIt());

                break;
            }
        case DEATH:
            cin>>std::ws>>choice;
            break;
        case RESTART:
            cin>>std::ws>>choice;
            break;
        case NEXT_LEVEL:
            cin>>std::ws>>choice;
            break;
        case RESET:
            cin>>std::ws>>choice;
            break;
        default:
            //nada pra fazer aqui
            break;
    }
}

void SnakeGame::update(){
    //atualiza o estado do jogo de acordo com o resultado da chamada de "process_input"
    switch(state){
        case RUNNING:
            {
                
                if(nextMove == 'U') {
                    snake.moveUp();
                } else if(nextMove == 'D') {
                    snake.moveDown();
                } else if(nextMove == 'L') {
                    snake.moveLeft();
                } else {
                    snake.moveRight();
                }
                
                //Bateu na parede?
                if(mazes[levelsGone].verifyCrash(snake.getPos())){
                    if(snake.getLives() == 1){
                        cout << "Você perdeu todas as vidas!" << endl;
                        state = RESTART;
                        break;
                    }
                    state = DEATH;
                    break;
                }

                //Venceu a fase?(Comeu todas as comidas da fase atual)
                if(mazes[levelsGone].verifyWin()){
                    //Venceu o jogo?(Essa é a última fase?)
                    if((levelsGone + 1) == mazes.size()){//Sim, última fase
                    state = WIN;
                    break;
                }
                    //Não, ainda tem mais fase pela frente
                    state = NEXT_LEVEL;
                    break;
                }


                //Diminui a pontuação por ter se movido
                score = score - 1;

                //Verifica se uma comida foi consumida
                bool comeu = mazes[levelsGone].eatFood(snake.getPos(), snake.getDirection(), mode);
                
                //Adiciona pontos por ter comido
                if(comeu == true) {
                    score = score + 10;
                }

                //Move o corpo caso o mesmo esteja ativado
                if(mode == 1 && comeu == false) {
                    mazes[levelsGone].move(snake.getPos(), snake.getDirection());
                }
                break;
            }
        case WAITING_USER: //se o jogo estava esperando pelo usuário então ele testa qual a escolha que foi feita
            if(choice == "n"){
                state = RESET;
                break;
            }
            else{
                state = RUNNING;
            }
            break;
        case DEATH:
            {

                if(choice == "n") {
                    state = RESTART;
                    break;
                }
                player.resetCommands();
                score = 1000; //Reseta o score para valor padrão
                snake.removeLife(); //Remove uma vida
                snake.realocateSnake(mazes[levelsGone].getInitPos().first, mazes[levelsGone].getInitPos().second); //Realoca a cobra
                snake.lookUp(); //Reseta direção de olhar da cobra para cima
                mazes[levelsGone].resetFood(); //Reseta o contador de comida da fase
                state = RUNNING;
                break;
            }
        case RESTART:
            {
                if(choice == "n") {
                    state = GAME_OVER;
                    game_over();
                    break;
                }
                player.resetCommands();
                levelsGone = 0;
                snake.realocateSnake(mazes[levelsGone].getInitPos().first, mazes[levelsGone].getInitPos().second); //Realoca a cobra
                score = 1000; //Reseta o score
                snake.lookUp(); //Reseta direção de olhar da cobra para cima

                //Reseta o contador de comida de todas as fases
                for(int i = 0; i != mazes.size(); i++) {
                    mazes[i].resetFood();
                }
                
                snake.resetLives();
                state = RUNNING;
                break;
            }
        case WIN: 
            {
                state = RESTART;
                break;
            }
        case NEXT_LEVEL:
            {
                //Passa para o próximo nível?
                if(choice == "n"){ //Não, então quer resetar esse nível?
                    state = RESET;
                    break;
                }

                //Sim! Então passa pro próximo mapa e reseta as vidas.
                player.resetCommands();
                snake.resetLives();
                levelsGone = levelsGone + 1; //Próximo nível
                snake.realocateSnake(mazes[levelsGone].getInitPos().first,mazes[levelsGone].getInitPos().second);
                snake.lookUp();
                state = RUNNING;
                break;
            }
        case RESET:
            {
                //Deseja só reiniciar esse nível?
                if(choice == "n"){//Não, bota pra começar tudo denovo
                    state = RESTART;
                    break;
                }

                //Sim, então apaga as frutas comidas desse nível, realoca a cobra etc.
                player.resetCommands();
                mazes[levelsGone].resetFood();
                snake.realocateSnake(mazes[levelsGone].getInitPos().first,mazes[levelsGone].getInitPos().second);
                snake.lookUp();
                state = RUNNING;
                break;
            }
        default:
            //nada pra fazer aqui
            break;
    }
}

/**
 * @brief função auxiliar para fazer o programa esperar por alguns milisegundos
 * @param ms a quantidade de segundos que o programa deve esperar
 */
void wait(int ms){
    this_thread::sleep_for(chrono::milliseconds(ms));
}

/**
 * @brief função auxiliar para limpar o terminal
 */
void clearScreen(){
//some C++ voodoo here ;D
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void SnakeGame::render(){
    clearScreen();
    switch(state){
        case RUNNING:
            //desenha HUD do jogo
            mazes[levelsGone].printHUD(snake.getLives());
            cout << "Score: " << score << endl;

            //desenha todas as linhas do labirinto
            mazes[levelsGone].printMaze(snake.getPos(), snake.getDirection());
            break;
        case WAITING_USER:
            cout<<"Você quer continuar com o jogo? (s/n)"<<endl;
            break;
        case GAME_OVER:
            cout<<"O jogo terminou!"<<endl;
            break;
        case DEATH:
            cout<<"Você acabou de perder uma vida! Deseja continuar?"<<endl;
            break;
        case RESTART:
            cout<<"Você deseja recomeçar esse jogo?"<<endl;
            break;
        case WIN:
            cout<<"Você venceu! Meus parabéns!"<<endl;
            break;
        case NEXT_LEVEL:
            cout<<"Fase concluída! Deseja passar para o próximo nível?"<<endl;
            break;
        case RESET:
            cout<<"Deseja reiniciar desse nível?"<<endl;
            break;
    }
    frameCount++;
}

void SnakeGame::game_over(){
}

void SnakeGame::loop(){
    while(state != GAME_OVER){
        process_actions();
        update();
        render();
        wait(1000);// espera 1 segundo entre cada frame
    }
}
