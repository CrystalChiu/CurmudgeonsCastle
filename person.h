#include "position.h"

#ifndef PERSON
#define PERSON

// The base class of Guards and Innocents and is abstract
class Person
{
    friend class Castle;
    friend int main();

    public:
        /** Person object. the base class for guards and Innocents
         * @parameter pos. the initial position
         * @parameter type. the type of person
         */
        Person(const Position& pos, char type);
        
        /** Gets the current position of the Person
         * @return position. */
        Position getPosition() const;

        /** Gets the type of the person [I, R, H, Y, W]
         * @return the type of the Person
         */
        char getType() const; 

        /** Equality operator
         * @parameter other the other person object
         * @return true if this object has the same position as the other and false otherwise */
        bool operator==(const Person& other) const;

        /** Inequality operator
         * @parameter other the other person object
         * @return false if this object has the same position as the other and true otherwise */
        bool operator!=(const Person& other) const;

        /** Moves the Person from the current position to pos. This is a pure virtual function
         * @parameter move determines the direction to move. The default value is 'A' for auto  */
        void move(char move = 'A'); 

        /** Virtual Destructor */
        ~Person(){}
        
    protected:
        Position* pos;
        char type;

    private:
    
};

#endif