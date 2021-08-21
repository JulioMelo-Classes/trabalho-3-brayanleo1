#ifndef Snake_h
#define Snake_h

#include <utility>

class Snake{
    private:
        std::pair<int, int> position; //<! Par contendo a posição x,y atual da cobra
        int bodySize; //<! Inteiro contendo o tamanho da cobra
        int mode; //<! Inteiro indicando o modo de jogo selecionado
        int lives; //<! Inteiro contendo a quantidade de vidas da cobra

    public:
        /*! Construtor de Snake que cria um objeto Snake de acordo com as regras
                @param mode_ O inteiro representando o modo de jogo
                @param x O inteiro representando a posição x da cobra
                @param y O inteiro representando a posição y da cobra
        */
        Snake(int mode_, int x, int y);

        //! Aumenta o tamanho do corpo da cobra
        void incrBody();

        //! Reseta o tamanho do corpo da cobra
        void resetBody();

        //! Move a cobra para cima
        void moveUp();

        //! Move a cobra para baixo
        void moveDown();

        //! Move a cobra para a esquerda
        void moveLeft();

        //! Move a cobra para a direita
        void moveRight();

        /*! Reposiciona a cobra
                    @param x O inteiro representando a posição x da cobra
                    @param y O inteiro representando a posição y da cobra
        */
        void realocateSnake(int x, int y);

        //! Remove uma vida da cobra
        void removeLife();

};

#endif