//
// Created by Laurent Lao on 2019-04-06.
//

#ifndef DICE_ROLLER_DICE_H
#define DICE_ROLLER_DICE_H

#include <iostream>
#include <stdlib.h>

class Dice
{
    // Private attributes
    int numberOfDice;
    int numberOfFaces;
    int modifier;
    
    // Public attributes
public:
    Dice(int, int ,int);
    int roll();
    
    friend std::ostream &operator<<(std::ostream &os, const Dice &dice);
    
};


#endif //DICE_ROLLER_DICE_H
