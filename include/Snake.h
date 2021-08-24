#ifndef Snake_h
#define Snake_h

#include <utility>

class Snake{
    private:
        std::pair<int, int> position; //<! Par contendo a posição x,y atual da cobra
        int lives; //<! Inteiro contendo a quantidade de vidas da cobra
        char direction; //<! Caractere contendo a direção que a cobra está encarando (>v^<)

    public:
        //! Construtor vazio de Snake
        Snake();

        /*! Construtor de Snake que cria um objeto Snake de acordo com as regras
                @param x O inteiro representando a posição x da cobra
                @param y O inteiro representando a posição y da cobra
        */
        Snake(int x, int y);

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

        //! Muda a direção da cobra para cima
        void lookUp();

        /*! Retorna par contendo a posição da cobra
                @return Par contendo posição x, y da cobra
        */
        std::pair<int, int> getPos();

        /*! Retorna char que indica a posição da cobra
                @return Char que indica a posição da cobra
        */
        char getDirection();

        /*! Retorna um inteiro representando a quantidade de vidas da cobra
                @return Int que indica a quantidade de vidas da cobra
        */
        int getLives();

        //! Reseta as vidas da cobra
        void resetLives();
};

#endif