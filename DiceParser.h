//
// Created by Laurent Lao on 2019-04-06.
//
#include "Dice.h"
#include <iostream>
#include <stdlib.h>

#ifndef DICE_ROLLER_PARSER_H
#define DICE_ROLLER_PARSER_H

class DiceParser
{

public:
        static Dice inputToDice(std::string input);
        static bool diceParser(std::string *input, std::string *numOfDice, std::string *numOfFaces,
                               std::string *modifier);
};

#endif //DICE_ROLLER_PARSER_H
