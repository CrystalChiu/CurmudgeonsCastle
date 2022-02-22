#include <cstdlib>
#include <ctime>
#include "personClass.h"
#include "position.h"
#include "guardClass.h"

#ifndef INDENTURED
#define INDENTURED

// should inherit from guard 
class IndenturedGuard : public Guard
{
    public:
        /** IndenturedGuard constructor. Calls Guard constructor with type 'I'
         * @parameter pos is the initial position.*/
        IndenturedGuard(const Position& pos);

        /** Moves the guard. This function overrrides in the Guard's pure virtual function
         *  has a 15% chance of moving this guard in a random direction.
         * @parameter move determines the  position to move to. Should be a pure virtual function, 
         *            Defaults to 'A' for auto
         */
        void move(const char move = 'A'); 
        
        /** Destructor */
        ~IndenturedGuard(){}
        
    protected:

    private:
};

#endif