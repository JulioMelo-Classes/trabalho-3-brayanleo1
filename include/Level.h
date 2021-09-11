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
        
                @return Booleano indicando true se o mapa foi criado com sucesso ou false se há problema no mapa
        */
        bool makeLab(std::vector<std::string>::iterator labIt, int foods);

        /*! Gera aleatoriamente e associa a posição da comida gerada
                @param snkPos Par contendo a posição x, y da cobra no mapa
        */
        void genFood(std::pair <int, int> snkPos);

        /*! Recebe e adiciona as dimensões do labirinto
                @param x Parâmetro de linhas que o labirinto terá
                @param y Parâmetro de colunas que o labirinto terá
        */
        void setDim(int x, int y);

        /*! Verifica se as dimensões passadas são válidas
                @return Retorna true se as dimensões forem válidas, false caso contrário
        */
        bool verifyDim();

        /*! Processa ação de comer a comida, adicionando corpo nas costas da cobra (se necessário)
                @param snkPos Par contendo posição x,y da cobra
                @param snkDir Char representando a direção para qual a cobra está olhando
                @param mode Int que representa o modo da cobra (com ou sem cauda)

                @return Um boolean que será true se algo foi consumide e false caso contrário
        */
        bool eatFood(std::pair<int, int> snkPos, char snkDir, int mode);

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

        //! Imprime o HUD do level
        void printHUD(int vidas);

        /*! Retorna o par de inteiros da posição da comida
                @return Par contendo a posição da comida
        */
        std::pair<int, int> getFoodPos();

        /*! Retorna iterator para o primeiro elemento da posição do maze
                @return Iterator apontando para o primeiro elemento da posição do maze
        */
        std::vector<std::vector<char>>::iterator getMazeIt();

        /*! Retorna um booleano que diz se cobra se chocou contra a parede
                @param snkPos Par que representa posição da cobra

                @return Booleano de valor true se cobra se chocou contra a parede e false caso contrário
        */
        bool verifyCrash(std::pair <int, int> snkPos);

        //! Reseta a quantidade de comidas consumidas e os espaços ocupados pelo corpo
        void resetFood();

        /*! Verifica se todas as comidas foram consumidas e retorna true se for o caso, false caso contrárioa
                @return Booleano de valor  true se todas as comidas foram consumidas e false caso contrário
        */
        bool verifyWin();

        /*! Retorna a referência da matriz de char chamada maze
                @return Referência da matriz de char chamada maze
        */
        std::vector<std::vector<char>>& getMazeRef();
};

#endif