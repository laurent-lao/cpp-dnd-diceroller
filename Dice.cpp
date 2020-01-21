//
// Created by Laurent Lao on 2019-04-06.
//

#include "Dice.h"
#include <random>
#include <iostream>
#include <stdlib.h>


Dice::Dice(int nbOfDice, int nbOfFaces, int someModifier) {
    numberOfDice = nbOfDice;
    numberOfFaces = nbOfFaces;
    modifier = someModifier;
}

int Dice::roll() {
    
    int total = 0;
    int results[numberOfDice];
    
    // Using OS seed for random number generator
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, numberOfFaces);
    
    // Generate Results
    for (int i = 0; i < numberOfDice; i++)
    {
        results[i] = dist(mt);
        total += results[i];
        
        // Print Results
        std::cout << "Dice " << (i + 1) << ": ";
        
        // Check for critical roll
        if (numberOfFaces == 20)
        {
            if (results[i] == 1)
            {
                std::cout << " 1 (Critical Fail...)";
            }
            else if (results[i] == numberOfFaces)
            {
                std::cout << " 20 (Critical Hit!)";
            }
            else
            {
                std::cout << results[i];
            }
        }
        else
        {
            std::cout << results[i];
        }
        
        // Next iteration
        std::cout << std::endl;
    }
    
    std::cout << "Total (with modifier): " << (total + modifier) << std::endl;
}

// Overwriting << operator
std::ostream &operator<<(std::ostream &os, const Dice &dice)
{
    os << "numberOfDice: " << dice.numberOfDice << " numberOfFaces: " << dice.numberOfFaces << " modifier: "
       << dice.modifier;
    return os;
}
