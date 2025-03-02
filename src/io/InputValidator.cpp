#include "InputValidator.hpp"

#include <iostream>
using namespace std;

bool InputValidator::isValidDigit(int userInput, int maxOption){
    if(!isdigit(userInput)){
        if (userInput >= 0 && userInput <= maxOption){
            return true;
        }
        else
        {
            cout << "\nOption "<<userInput << " is not valid :( The max option is " << maxOption <<"." <<endl;
            return false;
        }
    } return false;
}