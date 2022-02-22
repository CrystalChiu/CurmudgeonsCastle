#include "person.h"

#ifndef PERSONCLASS
#define PERSONCLASS

Person::Person(const Position& initPos, char type)
{
    this->type = type;
    pos = new Position(initPos.x, initPos.y);
}

Position Person::getPosition() const
{
    return (*pos);
}

char Person::getType() const
{
    return type;
}

bool Person::operator==(const Person& other) const
{
    return(pos->x == other.pos->x 
           && pos->y == other.pos->y);
}

bool Person::operator!=(const Person& other) const
{
    return( !(pos->x == other.pos->x 
           && pos->y == other.pos->y) );
}

#endif