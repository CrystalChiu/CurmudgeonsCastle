#include <cstdlib>
#include <ctime>
#include "personClass.h"
#include "position.h"
#include "guardClass.h"
#include "guardClass.h"

#ifndef ROVING
#define ROVING

// should inherit from Guard
class RovingGuard : public Guard
{
    public:
        /** RovingGuard constructor. Calls Guard constructor with type 'R'
         * @parameter pos is the initial position.*/
        RovingGuard(const Position& pos);

        /** Moves the guard. This function overrides in the Guard's pure virtual function
         *  moves this guard in a random direction.
         * @parameter move determines the  position to move to. Should be a pure virtual function, 
         *            Defaults to 'A' for auto */
        void move(const char move = 'A');

        /** Destructor */
        ~RovingGuard(){};
        
    protected:

    private:    
};

#endif