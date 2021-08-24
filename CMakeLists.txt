cmake_minimum_required(VERSION 3.5)
project(TesteLp1 VERSION 0.1 LANGUAGES CXX )

# set the compiling flags
# set ( CMAKE_CXX_FLAGS "-Wall" )

#--------------------------------
# This is for old cmake versions
set (CMAKE_CXX_STANDARD 14)
#--------------------------------

# configura o diretório contendo os .h, assim você pode incluílos apenas com include "arquivo.h"
include_directories( include )

# Cria um executável com nome "KenoGame", adiciona neste executável os arquivos do src e do include
add_executable( Snaze
                src/Level.cpp
                src/Snake.cpp
                src/SnakeGame.cpp
                src/Arquivo.cpp
                src/Player.cpp
                src/Snaze.cpp )

# The end
