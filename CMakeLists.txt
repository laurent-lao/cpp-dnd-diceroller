cmake_minimum_required(VERSION 3.13)
project(Dice_Roller)

set(CMAKE_CXX_STANDARD 14)

add_executable(Dice_Roller main.cpp Dice.cpp Dice.h DiceParser.cpp DiceParser.h)