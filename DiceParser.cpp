//
// Created by Laurent Lao on 2019-04-06.
//
#include <iostream>
#include <stdlib.h>
#include "DiceParser.h"

Dice DiceParser::inputToDice(std::string input)
{
    std::string numOfDice;
    std::string numOfFaces;
    std::string modifier;
    
    bool valid = diceParser(&input, &numOfDice, &numOfFaces, &modifier);
    
    if (!valid)
    {
        std::cout << "Invalid Dice" << std::endl;
        std::exit(1);
    }
    else
    {
        return Dice(std::stoi(numOfDice), std::stoi(numOfFaces), std::stoi(modifier));
    }
}

bool DiceParser::diceParser(std::string *input, std::string *numOfDice, std::string *numOfFaces, std::string *modifier)
{
    size_t indexOfD = input->find("d");
    size_t indexOfSign = input->find("+");
    
    bool hasNoModifier = false;
    
    // Checking indexOfD
    if (indexOfD == std::string::npos)
    {
        // Try Capital D
        indexOfD = input->find("D");
        
        if (indexOfD == std::string::npos)
        {
            return false;
        }
    }
    
    // Checking indexOfPlus
    if (indexOfSign == std::string::npos)
    {
        // Try negative
        indexOfSign = input->find("-");
        
        if (indexOfSign == std::string::npos)
        {
            hasNoModifier = true;
        }
    }
    
    // Computing size of NumOfDices
    size_t sizeOfNumOfDices = indexOfD;
    
    // Computing size of NumOfFaces
    size_t sizeOfNumOfFaces = indexOfSign - (indexOfD + 1);
    
    // Assigning numOfDice substring
    if (sizeOfNumOfDices == 0)
    {
        *numOfDice = "0";
    }
    else
    {
        *numOfDice = input->substr(0, indexOfD);
    }
    
    // Assigning numOfFaces substring
    if (hasNoModifier)
    {
        *numOfFaces = input->substr(indexOfD + 1); // until the end of str
        *modifier = "0";
    }
    else
    {
        *numOfFaces = input->substr(indexOfD + 1, sizeOfNumOfFaces);
        *modifier = input->substr(indexOfSign); // until the end of str
    }
    
    return true;
}