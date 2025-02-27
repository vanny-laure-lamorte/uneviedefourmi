#ifndef INPUTVALIDATOR_HPP
#define INPUTVALIDATOR_HPP

#include <iostream>
using namespace std;

class InputValidator {
public:

    /** 
    * @brief Validate only numbers between 0 and X (max option)
    * @param int userInput
    * @param int maxOption
    * @return bool userInput
    */
   bool isValidDigit(int userInput, int maxOption); 
    
private:

};

#endif // INPUTVALIDATOR_HPP
