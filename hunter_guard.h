#include <cstdlib>
#include <ctime>
#include "personClass.h"
#include "position.h"
#include "guardClass.h"
#include "innocentClass.h"

#ifndef HUNTER
#define HUNTER

// should inherit from Guard
class HunterGuard : public Guard
{
    public:
        /** HunterGuard constructor. Calls Guard constructor with type 'H'
         * @parameter pos is the initial position.
         * @parameter hero is a pointer to the hero object in the castle */
        HunterGuard(const Position& pos, const Innocent& hero);

        /** Moves the guard. This function overrides in the Guard's pure virtual function
         *  moves this guard towards the hero either in the x or y direction.
         * @parameter move determines the  position to move to. Should be a pure virtual function, 
         *            Defaults to 'A' for auto */
        
        void move(const char move = 'A'); 

        /** Destructor */
        ~HunterGuard(){};
        
    protected:

    private:
      const Innocent* heroObj;
};

#endif