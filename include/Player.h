#ifndef Player_h
#define Player_h

#include <vector>
#include <utility>

class Player {
    private:
        std::vector<char> directions; //<! Vetor de char contendo as direções para uma saída
        bool way; //! Booleano que contem true se há caminho até a comida e false caso contrário

    public:
        //! Contrutor padrão que inicializa o objeto player com atributo direction vazio e way false
        Player();

        /*! Método que armazena (se houver) um caminho para a comida.
                @param snkPos Par contendo a posição x, y da cobra
                @param snkDir Char representando a direção da cobra
                @param foodPos Par contendo a posição x, y da comida
                @param maze Iterator apontando para o labirínto

        */
        void find_solution(std::pair<int, int> snkPos, char snkDir, std::pair<int, int> foodPos, std::vector<std::vector<char>>::iterator maze);

        /*! Método que retorna o próximo movimento da sequência caso haja ou movimento aleatório caso não haja
                @return Char que indica a próxima posição a ser seguida
        */
        char next_move();

        /*!
                @return Booleano que representa se há atualmente uma solução
        */
        bool getWay();

        //! Reseta lista de movimentos
        void resetCommands();
    
};

#endif