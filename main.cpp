#include <stdlib.h>
#include <iostream>
#include "Dice.h"
#include "DiceParser.h"

using namespace std;

int main()
{
    std::cout << "Enter dice (i.e 1d100+3): ";
    
    // Get Input
    string input;
    std::cin >> input;
    
    Dice dice = DiceParser::inputToDice(input);
    std::cout << endl << dice << endl;
    
    dice.roll();
    return 0;
}