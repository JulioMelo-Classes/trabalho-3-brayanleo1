#ifndef SnakeGame_h
#define SnakeGame_h
#include <iostream>
#include <vector>

#include "Arquivo.h"
#include "Snake.h"
#include "Level.h"
#include "Player.h"


class SnakeGame{
    public:
        /**
        * @brief descreve os possíveis estados do jogo, fique à vontade para adicionar outros se necessário
        **/
        enum GameStates{
            RUNNING, //<! quando o jogo está executando o estado é RUNNING
            GAME_OVER, //<! quando o jogo deve terminar o estado é GAME_OVER
            WAITING_USER, //<! quando o jogo deve esperar por uma entrada do usuário o estado é WAITING_USER
            DEATH, //! quando o jogo detectou a batida da cobra e faz os procedimentos necessários
            NEXT_LEVEL, //! quando o jogo detectou que a cobra comeu tudo daquele nível e faz o que o usuário desejar
            RESET, //! quando o jogo recebe o comando de resetar o nível atual
            RESTART, //! quando o jogo recebe o comando de recomeçar do primeiro nível
            WIN //! quando o jogo detecta que todas as fases foram concluídas
        };

    private:
        //<! atributos adicione outros se quiser
        std::vector<Level> mazes; //<! vector contendo os labirintos da partida
        int frameCount; //<! contador de frames, usado apenas como exemplo
        std::string choice; //<! usado na função process_actions para guardar a escolha do usuário
        GameStates state; //<! guarda o estado do jogo
        Arquivo arquivo; //<! guarda o caminho do arquivo dos níveis
        Snake snake; //<! guarda o objeto do tipo snake daquele jogo
        int mode; //<! guarda o modo de jogo escolhido (0 = sem rabo, 1 = com rabo)
        Player player; //<! guarda o objeto do tipo player daquele jogo
        int score; //<! guarda a pontuação da cobra
        int levelsGone; //<! guarda a quantidade de níveis que já foram passados
    public:
        /**
        * @brief construtor padrão, fique à vontade para adicionar parâmetros se desejar
        **/
        SnakeGame(char *arquivo_[]);

        /**
        * @brief chamado no main, este loop executa o jogo indefinidamente até que o usuário escolha terminar!
        */
        void loop();

    private:
        /**
        * @brief realiza a inicialização geral do jogo, fique à vontade para adicionar parâmetros se achar que deve
        **/
        void initialize_game(int mode_);

        /**
        * @brief atualiza o estado do jogo, basicamente movendo os objetos, sorteando novas posições de comida
        **/
        void update();

        /**
        * @brief processa as entradas do jogador
        **/
        void process_actions();

        /**
        * @brief testa o estado do jogo e desenha a tela correspondente
        **/
        void render();

        /**
        * @brief é chamada quando o jogo termina a fim de destruir/resetar elementos do estado do jogo
        **/
        void game_over();
};

#endif //SnakeGame_h