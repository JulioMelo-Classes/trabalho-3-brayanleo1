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
veryEasy.txt -> nível fácil com agilidade entre o easiest e o easy, não importa o modo <br>

## Avaliação CP1

### Snake/Pacman
O jogo deveria conter o modo snake/pacman. Em ambos os modos não é possível andar pra trás. No modo snake deve ser desenhado o corpo.

**Avaliação**

ok

### Render.ui
O jogo deveria desenhar a UI corretamente, mostrando ao menos as vidas, o nível e o score.

**Avaliação**

Ok

### Render.mapa
O jogo deveria desenhar o mapa corretamente, com base no arquivo passado como argumento. Ok

**Avaliação**

ok

### Render.snake
O jogo deveria desenhar a snake corretamente.

**Avaliação**

ok

### Logic.colisão e Logic.comida
O jogo deve se comportar corretamente quando ocorre uma colisão com comida e com paredes.

**Avaliação**

ok

### Transição de mapas
O jogo deve ter transição de mapa uma vez que um mapa é terminado.

**Avaliação**

ok

### Interação com o usuário
O jogo deve perguntar ao usuário se quer continuar/reiniciar o nível/reiniciar o jogo a cada transição de mapa

**Avaliação**

ok

### Classe Level ou similar
O software deve encapsular as funcionalidades do nível em uma classe.

**Avaliação**

Ok

### Classe Player ou similar
O software deve encapsular as decisões do jogo em uma classe.

**Avaliação**

Ok

### Classe Snake ou similar
O software deve encapsular as funcionalidades relacionadas à snake em uma classe. 

**Avaliação**

OK

## Comentários gerais CP1

- Acho que a implementação ficou bem completa, a unica coisa que ficou estranha no meu ponto de vista é que na sua implementação a snake é comandada pelo usuário no método process_actions enquanto deveria ser no update, pelo padrão usado.
