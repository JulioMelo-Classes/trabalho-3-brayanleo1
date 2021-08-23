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
        std::pair<int, int> foodStatus; //<! Par de inteiros contendo a quantidade de comidas consumidas e a de comidas totais
        std::vector<std::pair<int, int>> body; //<! Vetor contendo pares das posições de membros do corpo da cobra

    public:
        //! Construtor que cria um labirinto vazio
        Level();

        /*! Método que registra o labirinto, posição inicial e comidas a serem consumidas
                @param labIt Iterator apontando para o vetor de strings do início do labirinto
                @param foods Inteiro que representa a quantidade de comida total do labirinto
        */
        void makeLab(std::vector<std::string>::iterator labIt, int foods);

        //! Gera aleatoriamente e associa a posição da comida gerada
        void genFood();

        /*! Recebe e adiciona as dimensões do labirinto
                @param x Parâmetro de colunas que o labirinto terá
                @param y Parâmetro de linhas que o labirinto terá
        */
        void setDim(int x, int y);

        /*! Verifica se as dimensões passadas são válidas
                @return Retorna true se as dimensões forem válidas, false caso contrário
        */
        bool verifyDim();

        /*! Processa ação de comer a comida, adicionando corpo nas costas da cobra
                @param snkPos Par contendo posição x,y da cobra
                @param snkDir Char representando a direção para qual a cobra está olhando
        */
        void eatFood(std::pair<int, int> snkPos, char snkDir);

        /*! Move o corpo da cobra adicionando um corpo nas costas da cobra e removendo o mais antigo colocado
                @param snkPos Par contendo posição x,y da cobra
                @param snkDir Char representando a direção para qual a cobra está olhando
        */
        void move(std::pair<int, int> snkPos, char snkDir);

        /*! Imprime o labirinto
                @param snkPos Par contendo posição x,y da cobra
                @param snkDir Char representando a direção para qual a cobra está olhando
        */
        void printMaze(std::pair<int, int> snkPos, char snkDir);

        /*! Retorna um par com a posição inicial da cobra
                @return Par contendo a posição inicial da cobra
        */
        std::pair<int, int> getInitPos();


};

#endif