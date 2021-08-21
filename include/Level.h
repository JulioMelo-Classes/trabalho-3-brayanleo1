#ifndef Level_h
#define Level_h

#include <iostream>
#include <vector>
#include <utility>

class Level {
    private:
        std::pair<int, int> dim; //<! Par contendo as dimensões do labirinto
        std::vector<std::vector<char>> maze; //<! Uma matriz contendo o labirinto do nível
        std::pair<int, int> foodPos; //<! Par contendo a posição x,y atual da comida
        std::pair<int, int> initPos; //<! Par contendo a posição x,y inicial da cobra
        int eatenFood; //<! Inteiro indicando quantas comidas já foram consumidas

    public:
        /*! Construtor do nível que guarda o labirinto, posição inicial e comidas consumidas
                @param labs Arquivo contendo as instruções de todos os labirintos
                @param howMany Inteiro que indica quantos labirintos já foram lidos
        */
        Level(); //a fazer

        //! Gera aleatoriamente e associa a posição da comida gerada
        void genFood();

        /*! Recebe e adiciona as dimensões do labirinto
                @param x Parâmetro de colunas que o labirinto terá
                @param y Parâmetro de linhas que o labirinto terá
        */
        void getDim(int x, int y);

        /*! Verifica se as dimensões passadas são válidas
                @return Retorna true se as dimensões forem válidas, false caso contrário
        */
        bool verifyDim();

};

#endif