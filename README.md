# LP1 Projeto 3

Neste projeto você irá fazer um simulador para o jogo snaze, melhores informações podem ser encontradas no [documento de especificação](https://www.overleaf.com/read/prcdstrjrdjr);

# Como compilar

Para compilar o projeto, primeiramente você deve criar um arquivo para compilação, criaremos o arquivo build no qual guardaremos o projeto compilado usando os seguintes comandos:

```
mkdir build
cd build
cmake ..
cmake --build .
```

# Como executar

A compilação gera um executável com o nome Snaze dentro da pasta build, __no windows__ esse executável fica na pasta Debug. Logo após a compilação, para executar o programa gerado com um arquivo qualquer use os comandos:

No linux:
```
./Snaze CaminhoDoArquivo/nomeDoArquivo.txt modo(0-sem cauda|1-com cauda)
```
No windows:
```
.\Debug\Snaze.exe CaminhoDoArquivo\nomeDoArquivo.txt modo(0-sem cauda|1-com cauda)
```

# Labirintos pré-feitos

Os labiríntos pré feitos e suas descrições são:

easiest.txt -> o mais fácil e rápido, não importa o modo <br>
easy.txt -> fácil porem mais demorado, não importa o modo <br>
easyImpPack.txt -> pack com os 2 primeiros fáceis e último pulado caso o modo seja com cauda(por ser impossível gerar comida) e fácil e um pouco mais lento sem cauda <br>
easyPack.txt -> pack com os 3 níveis fáceis criados, escalando o tempo para cada nível mais a frente, não importa o modo <br>
impossible.txt -> nível reto impossível, perda de todas as vídas eminente, não importa o modo <br>
maze1.txt -> nível padrão com pequena chance da cobra colidir contra a parede ou contra si mesma caso tenha cauda <br>
maze1C.txt -> nível padrão com pequena alteração para evitar que a cobra colida com a parede em condições normais <br>
maze2.txt -> nível disponibilizado no discord para teste do algorítmo de esquiva da cobra, sendo também o pior caso com o uso do algorítmo de solução por recursão <br>
veryEasy.txt -> nível fácil com agilidade entre o easiest e o easy, não importa o modo <br>


# Avaliação CP2

## FindSolution.pacman

O método find soluiton ou similar deve ser capaz de encontrar o conjunto de comandos que levam da posição atual da cobrinha até a posição da comida no modo pacman.

**Avaiação**

ok

## FindSolution.snake

O método find soluiton ou similar deve ser capaz de encontrar o conjunto de comandos que levam da posição atual da cobrinha até a posição da comida no modo snake.

**Avaliação**

25% a solução não leva em conta o movimento do corpo da cobrinha quando executada

## Random start

Deveria ser implementado na execução do programa um comando que permita que a posição inicial seja sorteada aleatoriamente. A posição inicial precisa ser válida e não deve causar a cobrinha/pacman iniciar em uma posição encurralada.

**Avaliação**

não implementado

## Level Loop

Deveria se implementado na execução do programa um comando que permite que os níveis fiquem se repetindo infinitamente, com a transição de mapas indo do primeiro nível até o último nível e voltando para o primeiro, de forma que seja mantida a contagem de pontos bem como a contagem de nível.

**Avaliação**

vou considerar uma vez que você implementa outros tipos de interação não necessários

## Organização / Compilação automatizada / Casos de Teste

Para a entrega final a organização do código em scr/data/include e compilação automatizada de alguma forma deve ser feita.

**Avaliação**

ok

## Documentação do código / Readme / Documentação de Casos de Teste

**Avaliação**

ok
