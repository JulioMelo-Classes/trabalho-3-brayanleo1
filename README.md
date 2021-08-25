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

easiest.txt -> o mais fácil e rápido, não importa o modo \\
easy.txt -> fácil porem mais demorado, não importa o modo \\
easyImpPack.txt -> pack com os 2 primeiros fáceis e último pulado caso o modo seja com cauda(por ser impossível gerar comida) e fácil e um pouco mais lento sem cauda \\
easyPack.txt -> pack com os 3 níveis fáceis criados, escalando o tempo para cada nível mais a frente, não importa o modo \\
impossible.txt -> nível reto impossível, perda de todas as vídas eminente, não importa o modo \\
maze1.txt -> nível padrão com pequena chance da cobra colidir contra a parede ou contra si mesma caso tenha cauda \\
veryEasy.txt -> nível fácil com agilidade entre o easiest e o easy, não importa o modo \\


