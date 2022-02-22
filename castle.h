// iostream is only used for the operator<< function.
// Do not print anything directly to cout from this or any other class
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

#include "innocentClass.h"
#include "guardClass.h"
#include "indenturedClass.h"
#include "rovingClass.h"
#include "hunterClass.h"

// this class does not provide UI no does it contain main. 
class Castle
{
    /** stream insertion operator overload */
    friend std::ostream& operator<<(std::ostream&, const Castle&);  
    friend int main();
    
    public:
        /** castle constructor. Initializes the castle */ 
        Castle();

        /** move the position of the hero]]
         @ parameter move the direction in which the hero must move: must be a valid move
        @ throws invalid_argument exception if move is invalid */ 
        void move(char move);

        /** Castle destructor. Deletes all heap based objects (including guards) */

        int getStatus();

        ~Castle();

    private:
        int getRandomCoord(int, int);
        std::vector<Guard*> guards;
        Innocent* hero;
        Innocent* wife;
        bool hasWife;
        static unsigned const int SIZE = 8;

        void carry();
};