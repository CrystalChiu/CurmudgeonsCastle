#include "personClass.h"
#include "position.h"

#ifndef INNOCENT
#define INNOCENT

// should inherit from Person
class Innocent : public Person
{
    public:
        /** Innocent constructor. Calls person constructor  
         * @parameter pos is the initial position. 
         * @parameter type is the type of person. */
        Innocent(const Position& pos, char type);

        /** Moves the Innocent based on the pos argument. 
         *  This function overrrides in the Guard's pure virtual function
         * @parameter move determines the updated position to move to. Moves: [N, S, E, W, P, C]
         * throws invalid_argument exception if pos is an invalid move */
        void move(const char move); //Used to move the wife with the hero if hasWife == true

        /** Destructor */
        ~Innocent(){};
        
    protected:

    private:
};

#endif